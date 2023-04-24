/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:40:21 by soulee            #+#    #+#             */
/*   Updated: 2023/04/24 18:29:29 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::AddContact()
{
	std::cout << "First Name: ";
	std::cin >> this->first_name;

	std::cout << "Last Name: ";
	std::cin >> this->last_name;

	std::cout << "Nickname: ";
	std::cin >> this->nickname;

	std::cout << "Phone Number: ";
	std::cin >> this->phone_number;

	std::cout << "Secret: ";
	std::cin >> this->secret;
}
