/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:46:46 by rmakoni           #+#    #+#             */
/*   Updated: 2025/04/30 13:57:15 by rmakoni          ###   ########.fr       */
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

        Fixed& operator=(const Fixed& copy);

        //Destructor
        ~Fixed();

        //Getter
        int getRawBits(void) const;
        //Setter
        void setRawBits(int const raw);
};
#endif