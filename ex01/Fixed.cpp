/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:46:25 by tterao            #+#    #+#             */
/*   Updated: 2023/07/02 18:31:01 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::binaryPoint = 8;

Fixed::Fixed() : fixedPointNum(0)
{
	std::cout << "Default constructor called\n";
};

Fixed::Fixed(const Fixed& obj) : fixedPointNum(obj.getRawBits())
{
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int num)
{
	//10
	// int n = 0b0000000000000000000000000001010;
	// n = 0b0000000000000000000101000000000;
	fixedPointNum = num << binaryPoint;
}

Fixed::Fixed(const float num)
{
	//1234.4321f
	// 123443210000
	// 123443210000.0
	//1234.4321f

	//1234.4321f
	//1234.4321 * (2**8 = 256)
	//316014.6176
	//316014

	fixedPointNum = roundf(num * (1 << binaryPoint));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
};

Fixed&	Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
		fixedPointNum = obj.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (fixedPointNum);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	fixedPointNum = raw;
}

float	Fixed::toFloat() const
{
	return static_cast<float>(fixedPointNum) / (1 << binaryPoint);
}

int	Fixed::toInt() const
{
	return fixedPointNum >> binaryPoint;
}

std::ostream&	operator<<(std::ostream& os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}
