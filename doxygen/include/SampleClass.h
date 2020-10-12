/**
 * \defgroup SampleClass_group SampleClass
 * \brief The SampleClass code module contains the implementation of the SampleClass.
 */

/**
 * \file   SampleClass.h
 * \author akirby
 */

#ifndef SAMPLECLASS_H
#define SAMPLECLASS_H

/* system header files */
#ifndef DOXYGEN_IGNORE
#  include <iostream>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \class SampleClass
 * \brief Demonstrates multiple constructors and a public display function.
 */
class SampleClass {
    private:
        /** Flag indicating whether the default or the initializer constructor was employed. */
	char initial_val;

    protected:
	/** Class integer. */
        int a;

    public:
	SampleClass();

	/** Initializer Constructor Function.
	 * 
	 * @param [in] a  	initialization value of class
	 */
	SampleClass(int a);

        /** Displays initialization value. */
	void displayInitValue() const;
};

#ifdef __cplusplus
}
#endif
#endif /* SAMPLECLASS_H */
