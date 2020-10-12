/**
 * \defgroup main_group MAIN
 * \brief The MAIN code module contains primary execution.
 */

/**
 * \file   main.cpp
 * \author akirby
 */


#include "SampleClass.h"

/** Main function to this SampleClass example.
 * 
 * @return Program success flag.
 */
int main(){
    SampleClass sc1;
    sc1.displayInitValue();

    SampleClass sc2(9965);
    sc2.displayInitValue();

    return 0;
}
