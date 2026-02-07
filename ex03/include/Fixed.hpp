/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:05:17 by lformank          #+#    #+#             */
/*   Updated: 2026/02/07 13:53:52 by lformank         ###   ########.fr       */
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
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int operator>(const Fixed& other) const;
		int operator<(const Fixed& other) const;
		int operator>=(const Fixed& other);
		int operator<=(const Fixed& other);
		int operator==(const Fixed& other);
		int operator!=(const Fixed& other);
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed& operator=(const Fixed& other);
		static Fixed& min(Fixed& first, Fixed& second);
		static const Fixed& min(const Fixed& first, const Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);
};

std::ostream& operator<<(std::ostream& stream, const Fixed& other);
