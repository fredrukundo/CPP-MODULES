#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a;
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        Bureaucrat b("fred", 50);
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        Bureaucrat c("duke", 10);
        c = b;
        std::cout << c << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat a1("Testing2", 0);
        std::cout << a1 << std::endl;
        a1.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}