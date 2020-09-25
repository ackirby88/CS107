#include "matplotlibcpp.h"
#include <iostream>
#include <vector>

namespace plt = matplotlibcpp;

int main(){
    std::vector<double> y = {1, 3, 2, 1, 4, 5, 5, 4, 3, 2, 1};
    plt::figure();
    plt::plot(y);

    std::cout << "Plotting... ";
    plt::save("minimal.pdf");
    std::cout << "minimal.pdf saved!\n";
    return 0;
}
