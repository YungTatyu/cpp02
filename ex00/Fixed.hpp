/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:47:11 by tterao            #+#    #+#             */
/*   Updated: 2023/06/30 16:38:30 by tterao           ###   ########.fr       */
/*                                                                            */	
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int					fixedPointNum;
		static const int	num_bit;
	public:
		Fixed();//default constructor
		~Fixed();//destructor
		Fixed(const Fixed& obj);//copy constructor
		Fixed&	operator=(const Fixed& obj);//assignment operator
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif