/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:32:56 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 19:28:19 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	brain;
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog& ref);
		~Dog(void);
		
		Dog&	operator=(const Dog& ref);
		
		void		makeSound(void) const;
		Brain*		getBrain(void) const;
		std::string	getIdea(size_t n) const;
		void		setIdea(std::string idea, size_t n);
};


#endif