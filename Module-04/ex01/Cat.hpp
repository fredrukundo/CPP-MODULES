#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat: public Animal {
    private:
        Brain   *brain;
    public:
        Cat();
        Cat(const Cat &cpy);
        Cat& operator=(const Cat &other);
        ~Cat();
        void makeSound() const;
};
#endif