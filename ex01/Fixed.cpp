/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:46:39 by rmakoni           #+#    #+#             */
/*   Updated: 2025/04/30 18:28:52 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointNum = 0;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_fixedPointNum = copy.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointNum = raw;
}

Fixed::Fixed(const int intNum)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointNum = intNum << _fracBits;
}

Fixed::Fixed(const float fpNum)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointNum = roundf(fpNum * (1 << _fracBits));
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixedPointNum / (1 << _fracBits);
}

int Fixed::toInt(void) const
{
    return this->_fixedPointNum >> _fracBits;
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat(); 
    return os;
}