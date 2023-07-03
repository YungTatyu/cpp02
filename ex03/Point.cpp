/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:42:15 by tterao            #+#    #+#             */
/*   Updated: 2023/07/03 21:45:49 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const float x, const float y) : x(x), y(y){}

Point::Point(const Point& obj) : x(obj.x), y(obj.y) {}

Point::~Point(){}

Point&	Point::operator=(const Point& obj)
{
	if (this != &obj)
	{
		this->x = obj.x;
		this->y = obj.y;
	}
	return (*this);
}

Fixed	Point::get_x() const
{
	return (x);
}

Fixed	Point::get_y() const
{
	return (y);
}
