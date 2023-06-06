/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:40:19 by soulee            #+#    #+#             */
/*   Updated: 2023/06/06 20:15:46 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
	public:
		void		AddContact();
		std::string	GetFirstname();
		std::string	GetLastname();
		std::string	GetNickname();
		std::string	GetPhonenumber();
		std::string	GetSecret();
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string	secret;
};

#endif
