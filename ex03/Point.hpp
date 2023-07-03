/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:39:13 by tterao            #+#    #+#             */
/*   Updated: 2023/07/03 21:45:45 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& obj);
		~Point();
		Point&	operator=(const Point& obj);
		Fixed	get_x() const;
		Fixed	get_y() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif