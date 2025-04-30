/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:04:30 by rmakoni           #+#    #+#             */
/*   Updated: 2025/04/30 13:51:29 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;
    std::cout << "b.getRawBits() = " << b.getRawBits() << std::endl;
    std::cout << "c.getRawBits() = " << c.getRawBits() << std::endl;

    return 0;
}