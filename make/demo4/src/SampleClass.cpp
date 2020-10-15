/* header files */
#include "SampleClass.h"

/* ============ */
/* Constructors */
/* ============ */
/* Default */
SampleClass::SampleClass() : a(17), initial_val(0) {/* initialize a using () */}

/* Initializer */
SampleClass::SampleClass(int a) : initial_val(1) {
    this->a = a;
}

/* =============== */
/* Class Functions */
/* =============== */
void SampleClass::displayInitValue(){
    if (initial_val == 1) {
        std::cout << "Set Value Constructor: " << a << std::endl;
    } else {
        std::cout << "Default Constructor: " << a << std::endl;
    }
}
