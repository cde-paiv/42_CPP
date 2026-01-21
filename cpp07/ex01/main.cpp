#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElem(T const& x) {
    std::cout << x << " ";
};

void incInt(int& x) {x += 1; }

void addBang(std::string& s) {s += "!"; }

int main() {
    {
        int a[] = {1, 2, 3, 4};
        std::size_t n = sizeof(a)/sizeof(a[0]);

        std::cout << "int antes: ";
        iter(a, n, printElem<int>);
        std::cout << "\n";

        iter(a, n, incInt);
        std::cout << "int after: ";
        iter(a, n, printElem<int>);
        std::cout << "\n\n";
    }
    {
        std::string s[] = {"oi", "cpp", "42"};
        std::size_t n = sizeof(s)/sizeof(s[0]);

        std::cout << "string before: ";
        iter(s, n, printElem<std::string>);
        std::cout << "\n";

        iter(s, n, addBang);
        std::cout << "string after: ";
        iter(s, n, printElem<std::string>);
        std::cout << "\n\n";
    }
}