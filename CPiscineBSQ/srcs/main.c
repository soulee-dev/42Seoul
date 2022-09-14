/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:26:45 by soulee            #+#    #+#             */
/*   Updated: 2022/09/14 00:31:12 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

// In case of anything can be done, what should we print out? > just print map
int	main(void)
{
	int		**map;
	char	*charset;
	char	**splitted_file_contents;
	int		*xy;

	map = read_dict("map");
	splitted_file_contents = ft_split(read_file("map"), "\n");
	xy = get_size(splitted_file_contents);
	charset = read_charset(splitted_file_contents);
	get_bsq(map, charset, xy);
}
