/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:05:17 by lformank          #+#    #+#             */
/*   Updated: 2026/02/01 15:28:07 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*orthodox canonical form*/
/*	- 4 fnc - constructor, copy constructor, copy assignment operator, destructor*/
/*	- */

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int num;
		static const int n_fraction = 8;
	public:
		Fixed(void);
		Fixed(int const integer);
		Fixed(float const floating);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		// int getRawBits(void) const;
		// void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		~Fixed();
};

std::ostream& operator<<(std::ostream& stream, const Fixed& other);
