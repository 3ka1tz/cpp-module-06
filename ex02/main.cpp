#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate() {
    switch (rand() % 3) {
        case 0 : return new A();
        case 1 : return new B();
        case 2 : return new C();
        default : return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A is the actual type of the object pointed by p" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B is the actual type of the object pointed by p" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C is the actual type of the object pointed by p" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A is the actual type of the object referenced by p" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B is the actual type of the object referenced by p" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C is the actual type of the object referenced by p" << std::endl;
        return;
    } catch (...) {}
}

int main() {
    srand(time(NULL));

    Base* p = generate();

    identify(p);
    identify(*p);

    delete p;
}
