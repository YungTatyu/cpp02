/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:18:15 by tterao            #+#    #+#             */
/*   Updated: 2023/07/03 19:19:20 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	float n = 1.001;
	std::cout << n++ << std::endl;
	std::cout << n << std::endl;
	std::cout << Fixed( 2.2f ) / Fixed( 2 ) << "\n";
	return 0;
}

// void	output_boolean(std::string nanka, int i)
// {
// 	if (i == 1)
// 		std::cout << nanka << " is true" << std::endl;
// 	else
// 		std::cout << nanka << " is false" << std::endl;
// }

// std::string interpret(Fixed const nanka)
// {
// 	return (std::to_string(nanka.toInt()));
// }

// int	main( void ) {
// 	Fixed a;
// 	Fixed  b( 2147.0f );
// 	Fixed  g( 80000.0f );
// 	Fixed  one( 1.0f );
// 	Fixed  c( 10 );
// 	Fixed  d( 10 );

// 	a = Fixed( 1234.4321f );
// 	// std::cout << "a is " << a << std::endl;
// 	// std::cout << "b is " << b << std::endl;
// 	// std::cout << "c is " << c << std::endl;
// 	// std::cout << "d is " << d << std::endl;
// 	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;

// 	/*https://monozukuri-c.com/langcpp-funclist-bool 参照/*/
// 	/*boolean check*/
// 	/*a = 1234 b = 2147 c = 10 d = 10*/
// 	std::cout << " ~~ boolean test ~~ " << std::endl;
// 	output_boolean(interpret(a) + " < " + interpret(b), a<b);
// 	output_boolean(interpret(a) + " > " + interpret(b), a>b);
// 	output_boolean(interpret(c) + " >= " + interpret(d), c>=d);
// 	output_boolean(interpret(a) + " >= " + interpret(d), a>=d);
// 	output_boolean(interpret(c) + " <= " + interpret(d), c<=d);
// 	output_boolean(interpret(a) + " == " + interpret(b), a==b);
// 	output_boolean(interpret(c) + " == " + interpret(d), c==d);
// 	output_boolean(interpret(c) + " != " + interpret(d), c!=d);
// 	std::cout << " ~~ testend ~~ " << std::endl;
// 	/*boolean test end*/
// 	/*operatorcheck*/
// 	std::cout << " ~~ arithmethic test ~~ " << std::endl;
// 	std::cout << "a+a test " << (a+a) << std::endl;
// 	std::cout << "b+b test " << (b+b) << std::endl;
// 	std::cout << "a-a test " << (a-a) << std::endl;
// 	std::cout << "a*a test " << (a*a) << std::endl;// 1234 * 1234 = 1522756
// 	std::cout << "a/a test " << (a/a) << std::endl;
// 	std::cout << "g/one test " << (g/one) << std::endl;
// 	std::cout << " ~~ testend ~~ " << std::endl;
// 	/*end*/
// 	/*implementcheck*/

// 	/*implementcheckend*/

// 	Fixed e;
// 	Fixed const ff(0);
// 	Fixed const f( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << e << std::endl;
// 	std::cout << ++e << std::endl;
// 	std::cout << e << std::endl;
// 	std::cout << e++ << std::endl;
// 	std::cout << e << std::endl;

// 	std::cout << f << std::endl;

// 	std::cout << Fixed::max( e, f ) << std::endl;
// 	std::cout << Fixed::min( e, f ) << std::endl;

// 	std::cout << Fixed::max( ff, f ) << std::endl;
// 	std::cout << Fixed::min( ff, f ) << std::endl;

// 	return 0;
// }
