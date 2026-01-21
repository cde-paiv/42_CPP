#include "Base.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base() {}

Base* Base::generate(void) {
    int r = std::rand() % 3;
    switch (r)
    {
        case 0: return new A();
        case 1: return new B();
        default: return new C();
    }
}

// versao com ponteiro
void Base::identify(Base* p) {
    if (!p) {std::cout << "Null pointer\n"; return; }

    if (dynamic_cast<A*>(p)) {std::cout << "A\n"; return; }
    if (dynamic_cast<B*>(p)) {std::cout << "B\n"; return; }
    if (dynamic_cast<C*>(p)) {std::cout << "C\n"; return; }

    std::cout << "Unknown\n";
}

// versao por referencia
void Base::identify(Base& p) {
    try { (void)dynamic_cast<A&>(p); std::cout << "A\n"; return; } catch (...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B\n"; return; } catch (...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C\n"; return; } catch (...) {}
    std::cout << "Unknown\n";
}