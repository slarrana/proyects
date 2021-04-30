#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & rhs)
{
	*this = rhs;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
	this->_n = (n << this->_bits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n)
{
	this->_n = roundf(n * (1 << this->_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_n = rhs.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream & ofs, Fixed const & rhs)
{
	ofs << rhs.toFloat();
	return (ofs);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

int	Fixed::toInt(void) const
{
	return (this->_n >> this->_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_n / (1 << this->_bits));
}
