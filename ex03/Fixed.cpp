/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:46:25 by tterao            #+#    #+#             */
/*   Updated: 2023/07/03 19:18:46 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::binaryPoint = 8;

Fixed&	Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if (lhs <= rhs)
		return (lhs);
	return (rhs);
}

const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs <= rhs)
		return (lhs);
	return (rhs);
}

Fixed&	Fixed::max(Fixed& lhs, Fixed& rhs)
{
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}

const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}

Fixed::Fixed() : fixedPointNum(0){};

Fixed::Fixed(const Fixed& obj) : fixedPointNum(obj.getRawBits()){}

Fixed::Fixed(const int num)
{
	fixedPointNum = num << binaryPoint;
}

Fixed::Fixed(const float num)
{
	fixedPointNum = roundf(num * (1 << binaryPoint));
}

Fixed::~Fixed(){};

Fixed&	Fixed::operator=(const Fixed& obj)
{
	if (this != &obj)
		fixedPointNum = obj.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& obj)
{
	Fixed	tmp;

	tmp.setRawBits(getRawBits());
	tmp.fixedPointNum += obj.fixedPointNum;
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& obj)
{
	Fixed	tmp;

	tmp.setRawBits(getRawBits());
	tmp.fixedPointNum -= obj.fixedPointNum;
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& obj)
{
	// 1.1 * 2 =  2.2
	// 11 * 20 = 220
	// 2.2 22
	Fixed	tmp;

	tmp.setRawBits(getRawBits());
	tmp.fixedPointNum *= (obj.fixedPointNum >> binaryPoint);
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& obj)
{
	// 2.2 / 2 =  1.1
	// 220 / 20 = 11
	// 1.1 11
	Fixed	tmp;

	tmp.setRawBits(getRawBits());
	tmp.fixedPointNum /= (obj.fixedPointNum >> binaryPoint);
	return (tmp);
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

bool	Fixed::operator!=(const Fixed& obj) const
{
	return (this->fixedPointNum != obj.fixedPointNum);
}

Fixed&	Fixed::operator++()
{
	fixedPointNum++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp.setRawBits(this->getRawBits());
	fixedPointNum++;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	fixedPointNum--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp.setRawBits(this->getRawBits());
	fixedPointNum--;
	return (tmp);
}

int	Fixed::getRawBits() const
{
	return (fixedPointNum);
}

void	Fixed::setRawBits(int const raw)
{
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
