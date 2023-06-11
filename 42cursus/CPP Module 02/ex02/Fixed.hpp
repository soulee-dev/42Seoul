/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:18:46 by soulee            #+#    #+#             */
/*   Updated: 2023/06/11 11:46:09 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					value;
		const static int	bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &ref);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed	&operator=(const Fixed &ref);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		// Comparison operators
		bool			operator>(Fixed const &ref) const;
		bool			operator<(Fixed const &ref) const;
		bool			operator>=(Fixed const &ref) const;
		bool			operator<=(Fixed const &ref) const;
		bool			operator==(Fixed const &ref) const;
		bool			operator!=(Fixed const &ref) const;

		// Arithmetic operators
		Fixed			operator+(Fixed const &ref) const;
		Fixed			operator-(Fixed const &ref) const;
		Fixed			operator*(Fixed const &ref) const;
		Fixed			operator/(Fixed const &ref) const;

		// Increment/Decrement
		Fixed			&operator++(void);
		const Fixed		operator++(int);
		Fixed			&operator--(void);
		const Fixed		operator--(int);

		// min, max
		static Fixed		&min(Fixed &ref1, Fixed &ref2);
		static const Fixed	&min(Fixed const &ref1, Fixed const &ref2);

		static Fixed		&max(Fixed &ref1, Fixed &ref2);
		static const Fixed	&max(Fixed const &ref1, Fixed const &ref2);
};

std::ostream&	operator<<(std::ostream &out, const Fixed &ref);
#endif