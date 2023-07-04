/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:18:15 by tterao            #+#    #+#             */
/*   Updated: 2023/07/04 15:16:01 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// Print triangle with points A, B, C, and P.
// This function is written with the help of Copilot.
// https://copilot.github.com/
void printTriangle(const Point a, const Point b, const Point c, const Point p) {
  // get min and max of x and y
  long minX = std::min(std::min(a.get_x(), b.get_x()), c.get_x()).getRawBits() ;
  long maxX = std::max(std::max(a.get_x(), b.get_x()), c.get_x()).getRawBits() ;
  long minY = std::min(std::min(a.get_y(), b.get_y()), c.get_y()).getRawBits() ;
  long maxY = std::max(std::max(a.get_y(), b.get_y()), c.get_y()).getRawBits() ;

  // get size of the triangle
  long width = maxX - minX;
  long height = maxY - minY;
  long size = std::max(width, height);
  long scale = 10 / size;

  // convert to 10x10 grid
  int ax = (a.get_x().getRawBits() - minX) * scale ;
  int ay = (a.get_y().getRawBits() - minY) * scale ;
  int bx = (b.get_x().getRawBits() - minX) * scale ;
  int by = (b.get_y().getRawBits() - minY) * scale ;
  int cx = (c.get_x().getRawBits() - minX) * scale ;
  int cy = (c.get_y().getRawBits() - minY) * scale ;
  int px = (p.get_x().getRawBits() - minX) * scale ;
  int py = (p.get_y().getRawBits() - minY) * scale ;

  // print triangle
  for (int y = 10; y >= 0; y--) {
    for (int x = 0; x <= 10; x++) {
      if (x == ax && y == ay) {
        std::cout << " A";
      } else if (x == bx && y == by) {
        std::cout << " B";
      } else if (x == cx && y == cy) {
        std::cout << " C";
      } else if (x == px && y == py) {
        std::cout << " P";
      // if point is on the edge of the triangle
      } else if (((y - ay) * (bx - ax) == (by - ay) * (x - ax)) && x >= std::min(ax, bx) &&
                 x <= std::max(ax, bx) && y >= std::min(ay, by) && y <= std::max(ay, by)) {
        std::cout << " .";
      } else if (((y - by) * (cx - bx) == (cy - by) * (x - bx)) && x >= std::min(bx, cx) &&
                 x <= std::max(bx, cx) && y >= std::min(by, cy) && y <= std::max(by, cy)) {
        std::cout << " .";
      } else if (((y - cy) * (ax - cx) == (ay - cy) * (x - cx)) && x >= std::min(cx, ax) &&
                 x <= std::max(cx, ax) && y >= std::min(cy, ay) && y <= std::max(cy, ay)) {
        std::cout << " .";
      } else {
        std::cout << "  ";
      }
    }
    std::cout << std::endl;
  }
}

int main()
{
	Point	a(10, 22);
	Point	b(7, 5);
	Point	c(9, 11);
	Point	p(9, 13);

	// std::cout << a.get_x() << a.get_y() << '\n';
	// std::cout << b.get_x() << b.get_y() << '\n';
	// std::cout << c.get_x() << c.get_y() << '\n';
	// std::cout << p.get_x() << p.get_y() << '\n';
	printTriangle(a, b, c, p);
	std::cout << (bsp(a, b, c, p) ? "true" : "false") << '\n';



	return 0;
}
