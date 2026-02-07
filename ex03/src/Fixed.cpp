/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:05:32 by lformank          #+#    #+#             */
/*   Updated: 2026/02/07 13:59:10 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
	: num(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const integer)
{
	// std::cout << "Int constructor called" << std::endl;
	this->num = integer << 8;
}

Fixed::Fixed(float const floating)
{
	// std::cout << "Float constructor called" << std::endl;
	this->num = roundf(floating * 256);
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& other)
{
	stream << other.toFloat();
	return stream;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->num = other.num;
	return *this;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->num);
}

void Fixed::setRawBits(int const raw)
{
	this->num = raw;
}

float Fixed::toFloat(void) const
{
	// float fl;

	// fl = (float)this->num / 256;
	return ((float)(this->num / 256));
}

int Fixed::toInt(void) const
{
	return (this->num >> 8);
}

/*ADDED*/

int	Fixed::operator>(const Fixed& other) const
{
	if (this->getRawBits() > other.getRawBits())
		return 1;
	else
		return 0;
}

int	Fixed::operator<(const Fixed& other) const
{
	if (this->getRawBits() < other.getRawBits())
		return 1;
	else
		return 0;
}

int	Fixed::operator>=(const Fixed& other)
{
	if (this->getRawBits() >= other.getRawBits())
		return 1;
	else
		return 0;	
}

int	Fixed::operator<=(const Fixed& other)
{
	if (this->getRawBits() <= other.getRawBits())
		return 1;
	else
		return 0;
}

int	Fixed::operator==(const Fixed& other)
{
	if (this->getRawBits() == other.getRawBits())
		return 1;
	else
		return 0;
}

int	Fixed::operator!=(const Fixed& other)
{
	if (this->getRawBits() != other.getRawBits())
		return 1;
	else
		return 0;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (this->toFloat() + other.toFloat()); 
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (this->toFloat() - other.toFloat()); 
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++()
{
	this->num++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->num--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	++this->num;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	--this->num;
	return (temp);
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first < second)
		return (first);
	else
		return (second);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first < second)
		return (first);
	else
		return (second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

