/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 21:45:10 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/18 23:14:30 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int sheck_line(char *line)
{
	int i;

	i = 0;
	while ((line[i] != '-') && *line)
		++i;
	if (line[i] == '-')
			return (1);
	else
		return (0);
}

void get_link(t_ant *ant, char *line)
{
	if (sheck_line(line) == 0)
		 ;
	else
	{
		ant->name = (char *)malloc(sizeof(char) * ft_strlen(line));
		ft_bzero(ant->name, ft_strlen(line));
		ft_strcpy(ant->name, line);
		ft_printf("%s\n", ant->name);
		free(ant->name);
	}
}
