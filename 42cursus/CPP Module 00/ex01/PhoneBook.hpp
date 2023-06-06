/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:40:28 by soulee            #+#    #+#             */
/*   Updated: 2023/06/06 19:48:30 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		int		index;
	public:
		void	AddContact(void);
		int		GetIndex(void);
		Contact	GetContact(int index);
	PhoneBook();
};

#endif