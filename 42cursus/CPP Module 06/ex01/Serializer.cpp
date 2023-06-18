/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:33:23 by soulee            #+#    #+#             */
/*   Updated: 2023/06/18 18:26:56 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "[Serializer] Default constructor" << std::endl;
}

Serializer::Serializer(const Serializer& ref)
{
	*this = ref;
	std::cout << "[Serializer] Copy constructor" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "[Serializer] Destructor" << std::endl;
}

Serializer&		Serializer::operator=(const Serializer& ref)
{
	if (this != &ref)
		return (*this);
	return (*this);
}

uintptr_t		Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*			Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}