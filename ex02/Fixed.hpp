/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:46:46 by rmakoni           #+#    #+#             */
/*   Updated: 2025/04/30 18:59:04 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <string>
#include <cmath>


class Fixed
{
    private:
        int _fixedPointNum;
        static const int _fracBits = 8;
    public:
        //Default constructor 
        Fixed();

        //Copy constructor
        Fixed(const Fixed& copy);
        Fixed(const int intNum);
        Fixed(const float fpNum);

        Fixed& operator=(const Fixed& copy);
        friend std::ostream& operator<<(std::ostream& os, const Fixed& copy);
        
        //Comparison operators
        bool operator>(const Fixed& copy) const;
        bool operator<(const Fixed& copy) const;
        bool operator>=(const Fixed& copy) const;
        bool operator<=(const Fixed& copy) const;
        bool operator==(const Fixed& copy) const;
        bool operator!=(const Fixed& copy) const;
        
        //Arithmetic operators
        Fixed operator+(const Fixed& copy) const;
        Fixed operator-(const Fixed& copy) const;
        Fixed operator*(const Fixed& copy) const;
        Fixed operator/(const Fixed& copy) const;

        //Increment and Decrement operators
        Fixed& operator++(); // Pre-increment
        Fixed operator++(int); // Post-increment
        Fixed& operator--(); // Pre-decrement
        Fixed operator--(int); // Post-decrement

        //Overload min and max functions
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        //Destructor
        ~Fixed();

        //Getter
        int getRawBits(void) const;
        //Setter
        void setRawBits(int const raw);
        //Conversion functions
        float toFloat(void) const;
        int toInt(void) const;
};
#endif