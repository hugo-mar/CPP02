/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:36:07 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/12 15:40:52 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main( void ) {

	// Part 1 - Subject main
	{
		std::cout << "-- Part1: Subject main -----------------" << std::endl;
		Fixed		a;
		Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl << std::endl;

	// Part 2 - Comparison Operators
	{
		std::cout << "-- Part2: Comparison operators----------" << std::endl;
		Fixed x(10);
		Fixed y(42.42f);
		Fixed z(10);
		
		std::cout << std::boolalpha;
		std::cout << "x = " << x << ", y = " << y << ", z = " << z << "\n";
		std::cout << "x > y: " << (x > y) << std::endl;
		std::cout << "x < y: " << (x < y) << std::endl;
		std::cout << "x >= z: " << (x >= z) << std::endl;
		std::cout << "x <= z: " << (x <= z) << std::endl;
		std::cout << "x == z: " << (x == z) << std::endl;
		std::cout << "x != y: " << (x != y) << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl << std::endl;

	// Part 3 - Arithmetic Operators
	{
		std::cout << "-- Part3: Arithmetic operators ----------" << std::endl;
		Fixed a(5.5f);
		Fixed b(2.25f);

		std::cout << "a = " << a << ", b = " << b << "\n";
		std::cout << "a + b = " << (a + b) << std::endl; // Esperado: 7.75
		std::cout << "a - b = " << (a - b) << std::endl; // Esperado: 3.25
		std::cout << "a * b = " << (a * b) << std::endl; // Esperado: 12.375
		std::cout << "a / b = " << (a / b) << std::endl; // Esperado: ~2.44444
	}
	std::cout << "----------------------------------------" << std::endl << std::endl;

	// Part 4 - Increment/Decrement Operators
	{
		std::cout << "-- Part4: Increment/Decrement operators --" << std::endl;
		Fixed f;
		
		std::cout << "Initial value: " << f << std::endl;
		
		std::cout << "Pre-increment (++f): " << ++f << std::endl;
		std::cout << "After pre-increment: " << f << std::endl;
		
		std::cout << "Post-increment (f++): " << f++ << std::endl;
		std::cout << "After post-increment: " << f << std::endl;
		
		std::cout << "Pre-decrement (--f): " << --f << std::endl;
		std::cout << "After pre-decrement: " << f << std::endl;
		
		std::cout << "Post-decrement (f--): " << f-- << std::endl;
		std::cout << "After post-decrement: " << f << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl << std::endl;

	// Part 4 - min and max functions
	{
		std::cout << "-- Part4: min and max ------------------" << std::endl;

		Fixed a(10.5f);
		Fixed b(42.42f);
		const Fixed c(3.14f);
		const Fixed d(3.15f);

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl << std::endl;

	return 0;
}