/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:28:39 by soulee            #+#    #+#             */
/*   Updated: 2023/06/18 16:37:38 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "[ScalarConverter] Default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& ref)
{
	*this = ref;
	std::cout << "[ScalarConverter] Copy constructor" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "[ScalarConverter] Destructor" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& ref)
{
	if (this != &ref)
		return (*this);
	return (*this);
}

void			ScalarConverter::convert(const std::string& s)
{
	double	val;

	try
	{
		char	*ptr = NULL;

		val = std::strtod(s.c_str(), &ptr);
		if (val == 0.0 &&
			(s[0] != '-' && s[0] != '+' && !std::isdigit(s[0])) &&
			(*ptr && std::strcmp(ptr, "f")))
			throw std::bad_alloc();
	}
	catch (std::exception& e)
	{
		std::cout << "Error: conversion failed: " << e.what() << std::endl;	
	}

	std::cout << "char : ";
	if (std::isnan(val) || std::isinf(val))
		std::cout << "impossible" << std::endl;
	else
	{
		if (std::isprint(val))
			std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	
	std::cout << "int: ";
	if (std::isnan(val) || std::isinf(val) || val > 2147483647 || val < -2147483648)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<int>(val) << "'" << std::endl;

	std::cout << "float: ";
	if (std::isnan(val) || std::isinf(val))
		std::cout << std::showpos << static_cast<float>(val) << "f" << std::endl;
	else
	{
		// Comaprison with integer
		if (static_cast<float>(val) == static_cast<int64_t>(static_cast<float>(val)))
			std::cout << static_cast<float>(val) << ".0f" << std::endl;
		else
			std::cout << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(val) << "f" << std::endl;
	}

	std::cout << "double: ";
	if (std::isnan(val) || std::isinf(val))
		std::cout << std::showpos << static_cast<double>(val) << std::endl;
	else
	{
		if (static_cast<double>(val) == static_cast<int64_t>(static_cast<double>(val)))
			std::cout << static_cast<double>(val) << ".0" << std::endl;
		else
			std::cout << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<double>(val) << std::endl;
	}
}
