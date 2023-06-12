/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:30:15 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 19:58:24 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& ref);
		virtual ~Animal(void);

		Animal&	operator=(const Animal& ref);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif