/* header files */
#include "MatrixClass.h"

/* ============ */
/* Constructors */
/* ============ */
/* Default */
MatrixClass::MatrixClass() : nrow(2), ncol(2), initial_val(0) {
  /* initialize a using () */
  this->A = new double[nrow*ncol];
  this->B = new double[nrow*ncol];
  for (int j = 0; j < nrow; ++j) {
    for (int i = 0; i < ncol; ++i) {
      A[j*ncol+i] = (double) i*j;
      B[j*ncol+i] = (double) j + 1.0;
    }
  }  
}

/* Initializer */
MatrixClass::MatrixClass(int nrow,int ncol) : initial_val(1) {
  this->nrow = nrow;
  this->ncol = ncol;

  this->A = new double[nrow*ncol];
  this->B = new double[nrow*ncol];
  for (int j = 0; j < nrow; ++j) {
    for (int i = 0; i < ncol; ++i) {
      A[j*ncol+i] = 2.0*i;
      B[j*ncol+i] = (double) j;
    }
  }
}

MatrixClass::~MatrixClass(){
  delete[] A;
  delete[] B;
}

/* =============== */
/* Class Functions */
/* =============== */
void MatrixClass::displayInitValue(){
    if (initial_val == 1) {
        std::cout << "Set Constructor: [" << nrow << "," << ncol << "]" << std::endl;
    } else {
        std::cout << "Default Constructor: [" << nrow << "," << ncol << "]" << std::endl;
    }
}

double* MatrixClass::add(){
    double *C = new double[nrow*ncol];

#ifdef F95_MATH
    std::cout << "[USING F95 Kernels!]\n";
    add_matrix_(&nrow,&ncol,A,B,C);
#else
    std::cout << "[USING Default Matrix Add!]\n";
    for (int i = 0; i < nrow; ++i) {
	for (int j = 0; j < ncol; ++j) {
	    C[i*ncol+j] = A[i*ncol+j] + B[i*ncol+j];
	}
    }
#endif
    return C;
}

void print_matrix(int nrow, int ncol, double *mat){
  for (int j = 0; j < nrow; ++j) {
    for (int i = 0; i < ncol; ++i) {
      printf(" %f ",mat[j*ncol+i]);
    }
    printf("\n");
  }
}
void MatrixClass::display(double *C){
  printf("Matrix A:\n"); print_matrix(nrow, ncol, A);
  printf("Matrix B:\n"); print_matrix(nrow, ncol, B);
  printf("Matrix C:\n"); print_matrix(nrow, ncol, C);
}
