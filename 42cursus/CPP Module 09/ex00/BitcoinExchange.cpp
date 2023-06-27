/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:41:24 by soulee            #+#    #+#             */
/*   Updated: 2023/06/27 20:45:52 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Check leap year
// TODO: Use map container, and lower_bound
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : data_file_path(DATA_PATH)
{
}

BitcoinExchange::BitcoinExchange(const std::string data_file_path) : data_file_path(data_file_path)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
	*this = ref;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& ref)
{
	static_cast<void>(ref);
	return (*this);
}

void	BitcoinExchange::checkDateFormat(const std::string date_string)
{
	std::string			date;
	std::istringstream	string_stream(date_string);
	int					year;
	int					month;
	int					day;
	std::size_t			date_type = 0;

	if (date_string.length() != 10)
		throw std::runtime_error("Error: corrupted file format. (Date length)");
	
	while (std::getline(string_stream, date, '-'))
	{
		// Year
		if (date_type == 0)
		{
			std::istringstream(date) >> year;
			if (year < 1000 || year > 9999)
				throw std::runtime_error("Error: corrupted file format. (Year)");
		}
		// Month
		else if (date_type == 1)
		{
			std::istringstream(date) >> month;
			if (month < 1 || month > 12)
				throw std::runtime_error("Error: corrupted file format. (Month)");
		}
		// Day
		else if (date_type == 2)
		{
			std::istringstream(date) >> day;
			if (day < 1 || day > 31)
				throw std::runtime_error("Error: corrupted file format. (Day 1)");
			if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
				throw std::runtime_error("Error: corrupted file format. (Day 2)");
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			{
				if (day > 29 && month == 2)
					throw std::runtime_error("Error: corrupted file format. (Day 3)");
				else if (day > 28 && month == 2)
					throw std::runtime_error("Error: corrupted file format. (Day 4)");
			}
		}
		date_type++;
	}
	if (date_type != 3)
		throw std::runtime_error("Error: corrupted file format. (Date Types)");
}

void	BitcoinExchange::checkInputForamt(const std::string str)
{
	char	*ptr = NULL;
	double	value = std::strtod(str.c_str(), &ptr);
	
	if (!str.find('.', 0 ) || str.find('.', str.length() - 1) != std::string::npos)
		throw std::runtime_error("Error: not a number.");
	if (value == 0.0 && !std::isdigit(str[0]))
		throw std::runtime_error("Error: not a number.");
	if (*ptr && std::strcmp(ptr, "f"))
		throw std::runtime_error("Error: not a number.");
	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	if (str.length() > 10 || (str.length() == 10 && value > 2147483647))
		throw std::runtime_error("Error: too large a number.");
}

void	BitcoinExchange::checkFileFormat(const std::string file_path, 
	const std::string header, const std::string delim, const std::size_t offset)
{
	std::ifstream	file(file_path);
	std::string		line;
	std::size_t		date_length;
	double			value;

	if (!file)
		throw std::runtime_error("Error: could not open file.");
	if (std::getline(file, line).eof())
		throw std::runtime_error("Error: corrupted file format.");
	if (line != header)
		throw std::runtime_error("Error: corrupted file format.");
	while (std::getline(file, line))
	{
		date_length = line.find(delim);
		try
		{
			checkDateFormat(line.substr(0, date_length));
		}
		catch (const std::exception& e)
		{
			if (!offset)
			{
				std::cerr << e.what() << std::endl;
				throw std::runtime_error("Error: corrupted file format. (Date)");
			}
			continue;
		}
		try
		{
			checkInputForamt(line.substr(date_length + offset + 1, line.length()));
		}
		catch (const std::exception& e)
		{
			if (!offset)
				throw std::runtime_error("Error: corrupted file format. (Value)");
		}
		if (!offset)
		{
			std::istringstream(line.substr(date_length + 1, line.length())) >> value;
			this->data[line.substr(0, date_length)] = value;
		}
	}
	file.close();
}

void				BitcoinExchange::printExchange(const char *date, const double n)
{
	std::map<std::string, double>::const_iterator	it = this->data.find(date);
	std::map<std::string, double>::const_iterator	ite = this->data.end();
	double											ret = 0;

	if (it != ite)
		ret = (it->second) * n;
	else
	{
		it = this->data.lower_bound(date);
		if (it == this->data.begin())
		{
			throw std::runtime_error("Error: invalid date.");
		}
		--it;
		ret = (it->second) * n;
	}
	if (n == static_cast<int>(n))
		std::cout << date << " => " << static_cast<int>(n) << " = " << ret << std::endl;
	else
	    std::cout << date << " => " << n << " = " << ret << std::endl;
}

void				BitcoinExchange::printData(const std::string file_path, const std::string delim)
{
	std::string		date;
	std::ifstream	file(file_path);
	std::string		line;
	std::size_t		date_length;
	double			value;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		date_length = line.find(delim);
		try
		{
			date = line.substr(0, date_length);
			checkDateFormat(date);
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		try
		{
			checkInputForamt(line.substr(date_length + 3, line.length()));
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			continue;
		}
		std::istringstream(line.substr(date_length + 3, line.length())) >> value;
		printExchange(date.c_str(), value);
	}
	file.close();
}

void				BitcoinExchange::run(const char *input_file_path)
{
	try
	{
		checkFileFormat(this->data_file_path, "date,exchange_rate", ",", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	try
	{
		checkFileFormat(input_file_path, "date | value", " | ", 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	printData(input_file_path, " | ");
	
}