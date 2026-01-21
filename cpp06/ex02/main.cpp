#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < 3; ++i)
    {
        Base *ptr = Base::generate();
        Base &ref = *ptr;
        std::cout << "Identify Pointer: ";
        Base::identify(ptr);
        std::cout << "Identify Reference: ";
        Base::identify(ref);
        delete ptr;
    }
    return 0;
}
