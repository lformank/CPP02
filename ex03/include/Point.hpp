/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:29:53 by lformank          #+#    #+#             */
/*   Updated: 2026/02/07 14:12:16 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point(void);
		Point(float x, float y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();
		const Fixed getx(void) const;
		const Fixed gety(void) const;
};
