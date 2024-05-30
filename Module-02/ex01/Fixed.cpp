#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed( const int input )
{
    std::cout << "Int constructor called" << std::endl;
    this->value = input << this->fractBits;
}

Fixed::Fixed( const float input )
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(input * (1 << this->fractBits));
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return this->value;
}

void Fixed::setRawBits( int const raw)
{
    this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->value / (float)(1 << this->fractBits));
}

int	Fixed::toInt( void ) const
{
	return (this->value >> this->fractBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}
