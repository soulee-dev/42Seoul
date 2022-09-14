/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:44:42 by soulee            #+#    #+#             */
/*   Updated: 2022/09/14 01:19:42 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	is_valid_string(char *str1, char *str2)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (i < ft_strlen(str1))
	{
		j = 0;
		flag = 0;
		while (j < ft_strlen(str2))
		{
			if (str1[i] == str2[j])
				flag = 1;
			j++;
		}
		if (!flag)
			print_error("ERROR: VALIDATOR (NOT MATCHING CHARACTER)\n");
		i++;
	}
}

void	valid_lines(char **splitted_file_contents)
{
	int		i;
	int		lines;
	char	*characters;
	int		count_first_line;
	int		count_before_line;

	count_first_line = ft_strlen(splitted_file_contents[0]);
	characters = get_string(splitted_file_contents[0],
			count_first_line - 3, 2);
	lines = ft_atoi(get_string(splitted_file_contents[0],
				0, ft_strlen(splitted_file_contents[0]) - 3));
	i = 1;
	count_before_line = ft_strlen(splitted_file_contents[1]);
	while (i < lines)
	{
		is_valid_string(splitted_file_contents[i], characters);
		if (count_before_line != ft_strlen(splitted_file_contents[i]))
			print_error("ERROR: VALIDATOR (LINE LENGTH NOT MATCHING)\n");
		count_before_line = ft_strlen(splitted_file_contents[i]);
		i++;
	}
}

void	valid_file(char **splitted_file_contents)
{
	int		count;
	int		lines;
	int		count_first_line;

	count = count_tab(splitted_file_contents);
	count_first_line = ft_strlen(splitted_file_contents[0]);
	lines = ft_atoi(get_string(splitted_file_contents[0],
				0, ft_strlen(splitted_file_contents[0]) - 3));
	if (count <= 0)
		print_error("ERROR: VALIDATOR (NOT VALID LINE)\n");
	if (count_first_line <= 3)
		print_error("ERROR: VALIDATOR (NOT VALID ARGUMENTS)\n");
	if (!is_numeric(get_string(splitted_file_contents[0],
				0, count_first_line - 3)))
		print_error("ERROR: VALIDATOR (NOT NUMBER LINE ARGUMENT)\n");
	if (!is_printable(get_string(splitted_file_contents[0],
				count_first_line - 3, 3)))
		print_error("ERROR: VALIDATOR (NOT PRINTABLE CHARACTER)\n");
	if (count - 1 != lines)
		print_error("ERROR: VALIDATOR (NOT MATCHING LINES)\n");
	if (lines <= 0)
		print_error("ERROR: VALIDATOR (EQUAL OR LESS THAN 0LINE )\n");
	valid_lines(splitted_file_contents);
}
