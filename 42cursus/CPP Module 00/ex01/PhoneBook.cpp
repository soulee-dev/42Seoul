/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:40:26 by soulee            #+#    #+#             */
/*   Updated: 2023/04/24 18:28:13 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

void	PhoneBook::AddContact(void)
{
	this->contacts[this->index % 8].AddContact();
	this->index++;
}

Contact	PhoneBook::GetContact(int index)
{
	return (this->contacts[index % 8]);
}
