/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:41:21 by soulee            #+#    #+#             */
/*   Updated: 2023/06/27 20:31:20 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define DATA_PATH "data/data.csv"

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <sstream>

class BitcoinExchange
{
	private:
		const std::string				data_file_path;
		std::map<std::string, double>	data;

		void				checkDateFormat(const std::string date);
		void				checkInputForamt(const std::string date);
		void				checkFileFormat(const std::string file_path,
			const std::string header, const std::string delim, const std::size_t offset);
		void				printExchange(const char *date, const double n);
		void				printData(const std::string file_path, const std::string delim);

	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string data_file_path);
		BitcoinExchange(const BitcoinExchange& ref);
		~BitcoinExchange();

		BitcoinExchange&	operator=(const BitcoinExchange& ref);

		void				run(const char *input_file_path);
};

#endif