#include <iostream>
#include <string>
#include "array.hpp"

int main() {
    Array<int> a0;
    std::cout << "a0.size() = " << a0.size() << "\n";

    Array<int> a(5);
    std::cout << "a.size()  = " << a.size() << "\n";
    for (size_t i = 0; i < a.size(); ++i) a[i] = static_cast<int>(i * 10);

    Array<int> b = a;
    a[0] = 999;
    std::cout << "a[0]=" << a[0] << "  b[0]=" << b[0] << " (deep copy ok)\n";

    Array<std::string> s1(3);
    s1[0] = "oi"; s1[1] = "cpp"; s1[2] = "42";
    Array<std::string> s2;
    s2 = s1;
    s1[1] = "mod";
    std::cout << "s1[1]=" << s1[1] << "  s2[1]=" << s2[1] << " (deep copy ok)\n";

    try {
        std::cout << a[a.size()] << "\n";
    } catch (const std::exception& e) {
        std::cout << "catch: " << e.what() << "\n";
    }

    return 0;
}
