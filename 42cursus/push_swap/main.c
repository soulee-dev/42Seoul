/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:49:18 by soulee            #+#    #+#             */
/*   Updated: 2023/01/17 17:58:49 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void    exit_error(char *error_message)
{
    exit(1);
}

int ft_atoi(const char *s)
{
    while (*s)
    {
        if (*s < '0' || *s > '9')
            exit_error("INVALID ARGUMENT (INVALID INTEGER)");
    }    
}

int main(int argc, char *argv[])
{
    if (argc < 1)
        exit_error("INVALID ARGUMENT (NO ARGUMENT)");
    
    printf("%d", argc);
    return (0);
}

