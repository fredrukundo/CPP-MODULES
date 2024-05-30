#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int						value;
        static const int	fractBits = 8;
    public:
        Fixed();

        Fixed( const int input );
        Fixed( const float input );

        Fixed(const Fixed& copy);
		  Fixed& operator=(const Fixed& other);

        float	toFloat( void ) const;
        int		toInt( void ) const;

        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const Row);
};
std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif