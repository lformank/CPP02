/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:03:34 by lformank          #+#    #+#             */
/*   Updated: 2026/02/01 18:19:18 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(Fixed(3.5f));
	Fixed d(Fixed(1));

	// std::cout << "My tests" << std::endl;
	// std::cout << "Post increment" << c++ << std::endl;
	// std::cout << "Post decrement" << c-- << std::endl;
	// // std::cout << "Pre increment" << ++c << std::endl;
	// // std::cout << "Pre decrement" << --c << std::endl;
	// // std::cout << "Post increment" << d++ << std::endl;
	// // std::cout << "Post decrement" << d-- << std::endl;
	// // std::cout << "Pre increment" << ++d << std::endl;
	// // std::cout << "Pre decrement" << --d << std::endl;
	// std::cout << "END\n\n\n" << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
