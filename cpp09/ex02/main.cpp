#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char** av) {
    if (ac < 2) {
        std::cerr << "Error\n";
        return 1;
    }
    try {
        PmergeMe sorter;
        sorter.run(ac, av);
    } catch (const std::exception&) {
        std::cerr << "Error\n";
        return 1;
    }
    return 0;
}