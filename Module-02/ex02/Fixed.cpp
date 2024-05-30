#include "Fixed.hpp"

/* ---------- constructors --------*/
Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed( const int input )
{
    this->value = input << this->fractBits;
}

Fixed::Fixed( const float input )
{
    this->value = roundf(input * (1 << this->fractBits));
}

Fixed::Fixed(const Fixed& copy)
{
    *this = copy;
}

/* ---------- destructors --------*/
Fixed::~Fixed()
{
}

/* ---------- assignement operator --------*/
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other) //handling self assignemnt
        this->value = other.getRawBits();
    return *this;
}

/* ---------- Comparision operators --------*/
bool Fixed::operator>( const Fixed& other) const
{
    return (this->value > other.getRawBits());
}
bool Fixed::operator<( const Fixed& other) const
{
    return (this->value < other.getRawBits());
}
bool Fixed::operator<=( const Fixed& other) const
{
    return (this->value <= other.getRawBits());
}
bool Fixed::operator>=( const Fixed& other) const
{
    return (this->value >= other.getRawBits());
}
bool Fixed::operator==( const Fixed& other) const
{
    return (this->value == other.getRawBits());
}
bool Fixed::operator!=( const Fixed& other) const
{
    return (this->value != other.getRawBits());
}

/* ---------- arithmetic operators --------*/
float Fixed::operator+(const Fixed &other) const
{
    return (this->toFloat() + other.toFloat());
}
float Fixed::operator-(const Fixed &other) const
{
    return (this->toFloat() - other.toFloat());
}
float Fixed::operator*(const Fixed &other) const
{
    return (this->toFloat() * other.toFloat());
}
float Fixed::operator/(const Fixed &other) const
{
    return (this->toFloat() / other.toFloat());
}

/* ---------- post-incrementation and de-incrementation --------*/
Fixed Fixed::operator++( int )
{
    Fixed temp = *this;
    this->value++;
    return (temp);
}
Fixed Fixed::operator--( int )
{
    Fixed temp = *this;
    this->value--;
    return (temp);
}

/* ---------- pre-incrementation and de-incrementation --------*/
Fixed& Fixed::operator++( void)
{
    this->value++;
    return (*this);
}
Fixed& Fixed::operator--( void)
{
    this->value--;
    return (*this);
}

/* ---------- getters and setters methods --------*/

int Fixed::getRawBits( void ) const
{
    return this->value;
}

void Fixed::setRawBits( int const raw)
{
    this->value = raw;
}

/* ---------- public functions --------*/
float	Fixed::toFloat( void ) const
{
	return ((float)this->value / (float)(1 << this->fractBits));
}

int	Fixed::toInt( void ) const
{
	return (this->value >> this->fractBits);
}

Fixed& Fixed::min( Fixed& first, Fixed& second)
{
    if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}
const Fixed& Fixed::min( const Fixed& first, const Fixed& second)
{
    if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed& Fixed::max( Fixed& first, Fixed& second)
{
    if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}
const Fixed& Fixed::max( const Fixed& first, const Fixed& second)
{
    if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

/* ----- Overload for ostream -------*/
std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}