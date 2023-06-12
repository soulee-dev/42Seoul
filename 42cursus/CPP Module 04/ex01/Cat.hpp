/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:32:23 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 19:28:29 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	brain;
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat& ref);
		~Cat(void);
		
		Cat&	operator=(const Cat& ref);
		
		void		makeSound(void) const;
		Brain*		getBrain(void) const;
		std::string	getIdea(size_t n) const;
		void		setIdea(std::string idea, size_t n);
};

#endif