/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:47:25 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/11 23:48:11 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Integer constructor — converts an int to fixed-point format
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = value << _fractionalBits;
}

// Float constructor — converts a float to fixed-point format
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(value * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Converts fixed-point to float
float Fixed::toFloat(void) const {
	return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

// Converts fixed-point to int (truncates the fractional part)
int Fixed::toInt(void) const {
	return _rawBits >> _fractionalBits;
}

// Getter for the raw fixed-point value
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

// Setter for the raw fixed-point value
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
	return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_rawBits != other._rawBits;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	long temp = static_cast<long>(this->_rawBits) * static_cast<long>(other._rawBits);
	result.setRawBits(static_cast<int>(temp >> _fractionalBits));
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	long temp = (static_cast<long>(this->_rawBits) << _fractionalBits) / other._rawBits;
	result.setRawBits(static_cast<int>(temp));
	return result;
}

// Pre-increment
Fixed& Fixed::operator++() {
	++_rawBits;
	return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++_rawBits;
	return temp;
}

// Pre-decrement
Fixed& Fixed::operator--() {
	--_rawBits;
	return *this;
}

// Post-decrement
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--_rawBits;
	return temp;
}

// Min/Max functions (non-const overload)
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

// Min/Max functions (const overload)
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

// Overload of the stream insertion operator (<<)
// Used to output the float representation of a Fixed object
std::ostream& operator<<(std::ostream& os, const Fixed& value) {
	os << value.toFloat();
	return os;
}
