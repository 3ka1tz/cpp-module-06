#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void)
{
    int r = rand() % 3;
    
    if (r == 0)
    {
        return (new A());
    }
    else if (r == 1)
    {
        return (new B());
    }
    else if (r == 2)
    {
        return (new C());
    }
        
    std::cerr << "Error: rand() failed\n";
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A is the actual type of the object pointed by p\n";
        return;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B is the actual type of the object pointed by p\n";
        return;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C is the actual type of the object pointed by p\n";
        return;
    }
    
    std::cerr << "Error: Unknown type pointed by p\n";
    return;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A is the actual type of the object referenced by p\n";
        return;
    }
    catch (...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B is the actual type of the object referenced by p\n";
        return;
    }
    catch (...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C is the actual type of the object referenced by p\n";
        return;
    }
    catch (...) {}

    std::cerr << "Error: Unknown type referenced by p\n";
    return;
}

int main(void)
{
    srand(time(NULL));

    Base* p = generate();

    identify(p);
    identify(*p);

    delete p;

    return (0);
}
