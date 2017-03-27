/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 23:51:16 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/27 04:52:26 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int get_err(char *line)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (ft_iswhitespace(line[i]) != 1)
	{
		if (ft_isend(line[i]) == 1)
		{
			free(line);
			return (1);
		}
		else
			++i;
	}
	if (line[i] == ' ')
	{
		++i;
		while (ft_isend(line[i]) != 1)
		{
			++k;
			++i;
		}
		if (k >= 3)
			return (0);
		else
		{
			free(line);
			return (1);
		}
	}
	else
		return (1);
}

void put_err(int err)
{
	if (err == 2)
		ft_putstr_fd("ERROR\n", 2);
	else if (err == 3)
		ft_putstr_fd("ERROR\n", 2);
	else if (err == 4)
		ft_putstr_fd("ERROR\n", 2);
}

t_map set_map(t_map *map)
{
	map->start = NULL;
	map->end = NULL;
	map->link = NULL;
	map->err = 0;
	map->nb = -1;
	return (*map);
}

int		ft_isend(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int		ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r')
		return (1);
	else
		return (0);
}
