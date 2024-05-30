#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	static const int fractBits = 8;

public:
	// Constructors
	Fixed();
	Fixed(const int input);
	Fixed(const float input);
	Fixed(const Fixed &copy);

	// Destructors
	~Fixed();

	//overloaded operators
	Fixed &operator=(const Fixed &other);

	//Comparision operators
	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	//arithmetic operators
	float operator-(const Fixed &other) const;
	float operator+(const Fixed &other) const;
	float operator*(const Fixed &other) const;
	float operator/(const Fixed &other) const;

	//post-incrementation and de-incrementation
	Fixed operator++( int );
	Fixed operator--( int );

	//pre-incrementation
	Fixed &operator++( void );
	Fixed &operator--( void );

	//public methods
	float toFloat(void) const;
	int toInt(void) const;
	static const Fixed &min(const Fixed &first, const Fixed &second);
	static Fixed &min(Fixed &first, Fixed &second);
	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &max(const Fixed &first, const Fixed &second);

	//getters and setters
	int getRawBits(void) const;
	void setRawBits(int const Row);
};
std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif