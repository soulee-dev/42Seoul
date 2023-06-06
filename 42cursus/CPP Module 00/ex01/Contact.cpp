/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:40:21 by soulee            #+#    #+#             */
/*   Updated: 2023/06/06 19:49:55 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::AddContact()
{
	std::cout << "First Name: ";
	std::cin >> this->firstname;

	std::cout << "Last Name: ";
	std::cin >> this->lastname;

	std::cout << "Nickname: ";
	std::cin >> this->nickname;

	std::cout << "Phone number: ";
	std::cin >> this->phonenumber;

	std::cout << "Secret: ";
	std::cin >> this->secret;
}

std::string	Contact::GetFirstname()
{
	return (this->firstname);
}

std::string	Contact::GetLastname()
{
	return (this->lastname);
}

std::string	Contact::GetNickname()
{
	return (this->nickname);
}

std::string	Contact::GetPhonenumber()
{
	return (this->phonenumber);
}

std::string	Contact::GetSecret()
{
	return (this->secret);
}
