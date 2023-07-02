/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:46:25 by tterao            #+#    #+#             */
/*   Updated: 2023/07/02 20:41:57 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::binaryPoint = 8;

Fixed&	min(Fixed& lhs, Fixed& rhs)
{
	if (lhs <= rhs)
		return (lhs);
	return (rhs);
}

const Fixed&	min(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs <= rhs)
		return (lhs);
	return (rhs);
}

Fixed&	max(Fixed& lhs, Fixed& rhs)
{
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}

const Fixed&	max(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}

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
	fixedPointNum = num << binaryPoint;
}

Fixed::Fixed(const float num)
{
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

Fixed&	Fixed::operator+(const Fixed& obj)
{
	this->fixedPointNum += obj.fixedPointNum;
	return (*this);
}

Fixed&	Fixed::operator-(const Fixed& obj)
{
	this->fixedPointNum -= obj.fixedPointNum;
	return (*this);
}

Fixed&	Fixed::operator*(const Fixed& obj)
{
	this->fixedPointNum *= obj.fixedPointNum;
	return (*this);
}

Fixed&	Fixed::operator/(const Fixed& obj)
{
	this->fixedPointNum /= obj.fixedPointNum;
	return (*this);
}

bool	Fixed::operator>(const Fixed& obj) const
{
	return (this->fixedPointNum > obj.fixedPointNum);
}

bool	Fixed::operator>=(const Fixed& obj) const
{
	return (this->fixedPointNum >= obj.fixedPointNum);
}

bool	Fixed::operator<(const Fixed& obj) const
{
	return (this->fixedPointNum < obj.fixedPointNum);
}

bool	Fixed::operator<=(const Fixed& obj) const
{
	return (this->fixedPointNum <= obj.fixedPointNum);
}

bool	Fixed::operator==(const Fixed& obj) const
{
	return (this->fixedPointNum == obj.fixedPointNum);
}

Fixed&	Fixed::operator++()
{
	fixedPointNum++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(this->fixedPointNum);

	tmp.fixedPointNum++;
	return (tmp);
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
