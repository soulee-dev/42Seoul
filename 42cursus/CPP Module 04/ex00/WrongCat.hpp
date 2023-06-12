/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:32:23 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 17:06:12 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(std::string type);
		WrongCat(const WrongCat& ref);
		~WrongCat(void);
		
		WrongCat&	operator=(const WrongCat& ref);
		
		void	makeSound(void) const;
};

#endif