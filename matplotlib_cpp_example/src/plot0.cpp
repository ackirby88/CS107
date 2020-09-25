#include "plot0.h"

namespace plt = matplotlibcpp;

void plot0(){
    /* Example 0 */
    std::vector<double> y = {1, 3, 2, 1, 4, 5, 5, 4, 3, 2, 1};
    plt::figure();

    std::cout << "Plotting fig. 0... ";
    plt::plot(y);
    plt::save("minimal.pdf");
    std::cout << "minimal.pdf saved!\n";
}
