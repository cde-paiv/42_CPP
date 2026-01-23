#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    try {
        std::cout << "=== Subject test ===\n";
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan()  << std::endl;
    } catch (const std::exception& e) {
        std::cout << "catch: " << e.what() << "\n";
    }

    std::cout << "\n";

    try {
        std::cout << " 10k numbers test \n";
        const unsigned int N = 10000;
        Span big(N);

        std::vector<int> buf;
        buf.reserve(N);
        for (unsigned int i = 0; i < N; ++i)
            buf.push_back(std::rand());

        big.addRange(buf.begin(), buf.end());

        std::cout << "size = " << big.size() << "\n";
        std::cout << "shortestSpan = " << big.shortestSpan() << "\n";
        std::cout << "longestSpan  = " << big.longestSpan()  << "\n";

    } catch (const std::exception& e) {
        std::cout << "catch: " << e.what() << "\n";
    }

    return 0;
}
