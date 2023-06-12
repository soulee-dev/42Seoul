/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:32:23 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 16:49:23 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat& ref);
		~Cat(void);
		
		Cat&	operator=(const Cat& ref);
		
		void	makeSound(void) const;
};

#endif