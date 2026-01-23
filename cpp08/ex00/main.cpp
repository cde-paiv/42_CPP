#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void printFound(int value, int got) {
    std::cout << "find(" << value << ") -> " << got << "\n";
}

int main() {
    try {
        // vector
        std::vector<int> v;
        v.push_back(1); v.push_back(3); v.push_back(5); v.push_back(7);

        std::vector<int>::iterator itv = easyfind(v, 5);
        printFound(5, *itv);
        // modifying via iterator
        *itv = 50;
        std::cout << "vector after: ";
        for (size_t i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
        std::cout << "\n\n";

        // list (const)
        const std::list<int> lst(1, 42); // lista com um elemento 42
        std::list<int>::const_iterator itc = easyfind(lst, 42);
        printFound(42, *itc);
        std::cout << "\n";

        std::deque<int> dq;
        for (int i = 0; i < 4; ++i) dq.push_back(i*2);
        std::deque<int>::iterator itd = easyfind(dq, 6);
        printFound(6, *itd);

        // error (not found)
        easyfind(dq, 99);
        std::cout << "never printed\n";

    }
    catch (const std::exception& e) {
        std::cout << "catch: " << e.what() << "\n";
    }
    return 0;
}