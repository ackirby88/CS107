#ifndef MATRIXCLASS_H
#define MATRIXCLASS_H

/* system header files */
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

/* External Fortran Functions */
void add_matrix_(int *nrow,int *ncol,
                 double *A,double *B,double *C);

/**
 * MatrixClass Class: demonstrates multiple 
 * constructors and a public display function.
 */
class MatrixClass {
    private:
	char initial_val;
    protected:
        int nrow;
	int ncol;
	double *A;
	double *B;
    public:
	/**< Default Constructor Function */
	MatrixClass();
	~MatrixClass();

	/**< Initializer Constructor Function
	 * a [in]   initialization value
	 */
	MatrixClass(int nrow, int ncol);

	/**< Displays initialization value */
        void displayInitValue();

	double* add();
	void display(double *C);
};

#ifdef __cplusplus
}
#endif
#endif /* MATRIXCLASS_H */
