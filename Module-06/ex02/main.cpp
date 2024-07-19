#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base*   generate() {
    srand(time(0));
    int randomValue = std::rand() % 3;

    switch(randomValue) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    std::cout << "Unknown type" << std::endl;
}


int main()
{
     // Generate a random instance of A, B, or C
    Base* basePtr = generate();

    // Identify the type using a pointer
    std::cout << "Identifying using pointer: ";
    identify(basePtr);

    // Identify the type using a reference
    std::cout << "Identifying using reference: ";
    identify(*basePtr);

    // Clean up
    delete basePtr;

}