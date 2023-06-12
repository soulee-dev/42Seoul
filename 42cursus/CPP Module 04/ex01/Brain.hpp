/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:09:10 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 19:28:57 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain(void);
		Brain(const Brain& ref);
		~Brain(void);

		Brain&	operator=(const Brain& ref);

		std::string	getIdea(size_t n) const;
		void		setIdea(std::string idea, size_t n); 
};

#endif