/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:46:39 by rmakoni           #+#    #+#             */
/*   Updated: 2025/04/30 19:02:23 by rmakoni          ###   ########.fr       */
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

bool Fixed::operator>(const Fixed& copy) const
{
    return this->_fixedPointNum > copy._fixedPointNum;
}

bool Fixed::operator<(const Fixed& copy) const
{
    return this->_fixedPointNum < copy._fixedPointNum;
}

bool Fixed::operator>=(const Fixed& copy) const
{
    return this->_fixedPointNum >= copy._fixedPointNum;
}

bool Fixed::operator<=(const Fixed& copy) const
{
    return this->_fixedPointNum <= copy._fixedPointNum;
}

bool Fixed::operator==(const Fixed& copy) const
{
    return this->_fixedPointNum == copy._fixedPointNum;
}

bool Fixed::operator!=(const Fixed& copy) const
{
    return this->_fixedPointNum != copy._fixedPointNum;
}

Fixed Fixed::operator+(const Fixed& copy) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointNum + copy._fixedPointNum);
    return result;
}

Fixed Fixed::operator-(const Fixed& copy) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointNum - copy._fixedPointNum);
    return result;
}

Fixed Fixed::operator*(const Fixed& copy) const
{
    Fixed result;
    result.setRawBits((this->_fixedPointNum * copy._fixedPointNum) >> _fracBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& copy) const
{
    Fixed result;
    result.setRawBits((this->_fixedPointNum << _fracBits) / copy._fixedPointNum);
    return result;
}

Fixed& Fixed::operator++()
{
    ++this->_fixedPointNum;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++this->_fixedPointNum;
    return temp;
}

Fixed& Fixed::operator--()
{
    --this->_fixedPointNum;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --this->_fixedPointNum;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}
