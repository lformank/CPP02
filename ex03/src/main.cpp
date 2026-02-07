/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:03:34 by lformank          #+#    #+#             */
/*   Updated: 2026/02/07 14:57:24 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point	vector(const Point& from, const Point& to)
{
	Point	ret((to.getx() - from.getx()).toFloat(), (to.gety() - from.gety()).toFloat());
	return ret;
}
Fixed	CrossProduct(const Point& v_orig, const Point& v_side)
{
	Fixed result;

	result = (v_orig.getx() * v_side.gety()) - (v_orig.gety() * v_side.getx());
	return result;
}

Fixed	DotProduct(const Fixed& ref, const Fixed& test)
{
	Fixed result;

	result = ref * test;
	return result;
}

Fixed	computing(Point const P1, Point const P2, Point const ref, Point const test)
{
	Point	v_P1P2(vector(P1, P2));
	Point	v_P1R(vector(P1, ref));
	Point	v_P1T(vector(P1, test));
	Fixed	CP1(CrossProduct(v_P1P2, v_P1R).toFloat());
	Fixed	CP2(CrossProduct(v_P1P2, v_P1T).toFloat());
	return (CP1 * CP2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Point	v_AB(vector(a, b));
	// Point	v_AC(vector(a, c));
	// Point	v_AP(vector(a, point));
	// Fixed	CP1(CrossProduct(v_AB, v_AC).toFloat());
	// Fixed	CP2(CrossProduct(v_AB, v_AP).toFloat());
	// Fixed	res(CP1 * CP2);
	// std::cout << "AtoB = [" << v_AB.getx().toFloat() << ", " << v_AB.gety().toFloat() << "]" << std::endl;
	// std::cout << "AtoC = [" << v_AC.getx().toFloat() << ", " << v_AC.gety().toFloat() << "]" << std::endl;
	// std::cout << "AtoP = [" << v_AP.getx().toFloat() << ", " << v_AP.gety().toFloat() << "]" << std::endl;
	// std::cout << "AB_AC = " << CrossProduct(v_AB, v_AC).toFloat() << std::endl;
	// std::cout << "AB_AP = " << CrossProduct(v_AB, v_AP).toFloat() << std::endl;
	// std::cout << "result product 1: " << res.toFloat() << std::endl;
	if (computing(a, b, c, point) > 0 && computing(b, c, a, point) > 0
		&& computing(c, a, b, point) > 0)
		return (true);
	else
		return (false);
}

int main(void)
{
	Point A(1, 2);
	Point B(3, 0);
	Point C(2, 4);
	Point P(3, 0);

	std::cout << A.getx().toFloat() << std::endl;
	std::cout << A.gety().toFloat() << std::endl;
	if (bsp(A, B, C, P) == true)
		std::cout << "The point IS in the triangle defined by points A, B, C" << std::endl;
	else
		std::cout << "The point IS NOT in the triangle defined by points A, B, C" << std::endl;
	
	return 0;
}
