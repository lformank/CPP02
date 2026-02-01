/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:05:32 by lformank          #+#    #+#             */
/*   Updated: 2026/02/01 18:21:01 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->num = 0;
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
	// Fixed *new_ = new Fixed(other.num);
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->num = other.num;
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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
	float fl;

	fl = (float)this->num / 256;
	return fl;
}

int Fixed::toInt(void) const
{
	return (this->num >> 8);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& other)
{
	stream << other.toFloat();
	return stream;
}

int	Fixed::operator>(const Fixed& other)
{
	if (this->getRawBits() > other.getRawBits())
		return 1;
	else
		return 0;
}

int	Fixed::operator<(const Fixed& other)
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
    Fixed result;
    result.setRawBits(this->num + other.getRawBits());
    return (result); 
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->num - other.getRawBits());
    return (result); 
}

Fixed&	Fixed::operator*(const Fixed& other)
{
	Fixed *result = new Fixed((int)((long)this->toInt() * (long)other.toInt()) >> 8);
	return (*result);
}

Fixed&	Fixed::operator/(const Fixed& other)
{
	Fixed *result = new Fixed((int)((long)this->toInt() / (long)other.toInt()) << 8);
	return (*result);
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
	Fixed temp = *this;
	this->num++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->num--;
	return (temp);
}
