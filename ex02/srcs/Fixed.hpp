/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:36:14 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/12 11:02:12 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

private:
	int					_rawBits;					// Stores the fixed-point value
	static const int	_fractionalBits = 8;		// Number of fractional bits

public:
	// Canonical form
	Fixed();										// Default constructor
	Fixed(const Fixed& other);						// Copy constructor
	Fixed& operator=(const Fixed& other);			// Copy assignment operator
	~Fixed();										// Destructor

	// Additional constructors
	Fixed(const int value);							// Converts int to fixed-point
	Fixed(const float value);						// Converts float to fixed-point

	// Conversion methods
	float toFloat(void) const;						// Converts fixed-point to float
	int toInt(void) const;							// Converts fixed-point to int

	// Getters and Setters
	int getRawBits(void) const;						// Gets the raw integer value
	void setRawBits(int const raw);					// Sets the raw integer value

	// Comparison operators
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Increment / Decrement operators
	Fixed& operator++();							// Pre-increment (++a)
	Fixed operator++(int);							// Post-increment (a++)
	Fixed& operator--();							// Pre-decrement (--a)
	Fixed operator--(int);							// Post-decrement (a--)

	// Min and Max static functions
	static Fixed& min(Fixed& a, Fixed& b);						// Non-const reference
	static const Fixed& min(const Fixed& a, const Fixed& b);	// Const reference
	static Fixed& max(Fixed& a, Fixed& b);						// Non-const reference
	static const Fixed& max(const Fixed& a, const Fixed& b);	// Const reference
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& value);

#endif
