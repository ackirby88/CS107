#include "MatrixClass.h"

int main(){
    MatrixClass m(4,4);
    m.displayInitValue();

    double *C = m.add();
    m.display(C);
    delete[] C;

    return 0;
}
