/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:31:04 by lformank          #+#    #+#             */
/*   Updated: 2026/02/07 14:25:56 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
	: x(0), y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(float x, float y)
	: x(roundf(x)), y(roundf(y))
{
	// std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Point& other)
	: x(other.x), y(other.y)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		{}
	return *this;
}

const Fixed Point::getx(void) const
{
	return (this->x);
}

const Fixed Point::gety(void) const
{
	return (this->y);
}

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

