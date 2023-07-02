/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:47:11 by tterao            #+#    #+#             */
/*   Updated: 2023/07/02 20:41:31 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixedPointNum;
		static const int	binaryPoint;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed& obj);
		Fixed&	operator=(const Fixed& obj);
		Fixed&	operator+(const Fixed& obj);
		Fixed&	operator-(const Fixed& obj);
		Fixed&	operator*(const Fixed& obj);
		Fixed&	operator/(const Fixed& obj);
		bool	operator>(const Fixed& obj) const;
		bool	operator>=(const Fixed& obj) const;
		bool	operator<(const Fixed& obj) const;
		bool	operator<=(const Fixed& obj) const;
		bool	operator==(const Fixed& obj) const;
		bool	operator!=(const Fixed& obj) const;
		Fixed&	operator++();
		Fixed	operator++(int);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
		static Fixed&	min(Fixed& lhs, Fixed& rhs);
		static const Fixed&	min(const Fixed& lhs, const Fixed& rhs);
		static Fixed&	max(Fixed& lhs, Fixed& rhs);
		static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);
};

std::ostream&	operator<<(std::ostream& os, const Fixed &obj);

#endif