/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:42:07 by soulee            #+#    #+#             */
/*   Updated: 2022/09/12 16:13:42 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*read_file(char *filename);

int	main(void)
{
	char	*file_contents;

	file_contents = read_file("map");
	printf("AA");
	printf("%s", file_contents);
	return (0);
}
