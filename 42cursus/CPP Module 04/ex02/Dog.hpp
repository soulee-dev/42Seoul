/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:32:56 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 16:53:32 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog& ref);
		~Dog(void);
		
		Dog&	operator=(const Dog& ref);
		
		void	makeSound(void) const;
};


#endif