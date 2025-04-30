/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:04:30 by rmakoni           #+#    #+#             */
/*   Updated: 2025/04/30 19:10:06 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void RestOfTheTests(void)
{
    std::cout << "=== Testing Comparison Operators ===" << std::endl;
    Fixed a(10.5f);
    Fixed b(10.5f);
    Fixed c(20.75f);
    
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    std::cout << "a > c: " << (a > c) << std::endl;
    std::cout << "a < c: " << (a < c) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;

    std::cout << "=== Testing Arithmetic Operators ===" << std::endl;
    std::cout << "a + c = " << (a + c) << std::endl;
    std::cout << "c - a = " << (c - a) << std::endl;
    std::cout << "a * c = " << (a * c) << std::endl;
    std::cout << "c / a = " << (c / a) << std::endl;

    std::cout << "=== Testing Decrement Operators ===" << std::endl;
    Fixed d(5);
    std::cout << "d = " << d << std::endl;
    std::cout << "--d = " << --d << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "d-- = " << d-- << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << "=== Testing min/max Functions ===" << std::endl;
    Fixed e(15.75f);
    Fixed f(15.25f);
    
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << Fixed::min(e, f) << std::endl;
    
    const Fixed g(30.5f);
    const Fixed h(29.8f);
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min(const g, const h) = " << Fixed::min(g, h) << std::endl;
    std::cout << "max(e, f) = " << Fixed::max(e, f) << std::endl;
    std::cout << "max(const g, const h) = " << Fixed::max(g, h) << std::endl;
}

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    std::cout << "..................................................................." << std::endl;
    std::cout << "Personal test" << std::endl;
    RestOfTheTests();
    
    return 0;
}
