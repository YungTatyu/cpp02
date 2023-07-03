/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:59:30 by tterao            #+#    #+#             */
/*   Updated: 2023/07/03 21:53:39 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{

	Fixed	abXap = (b.get_x() - a.get_x()) * (point.get_x() - a.get_y()) - (b.get_y() - a.get_y()) * (point.get_x() - a.get_x());
	Fixed	bcXbp = (c.get_x() - b.get_x()) * (point.get_y() - b.get_y()) - (c.get_y() - b.get_y()) * (point.get_x() - b.get_x());
	Fixed	caXcp = (a.get_x() - c.get_x()) * (point.get_y() - c.get_y()) - (a.get_y() - c.get_y()) * (point.get_x() - c.get_x());

	return (( abXap > 0 && bcXbp > 0 && caXcp > 0) || ( abXap < 0 && bcXbp < 0 && caXcp < 0));
}
