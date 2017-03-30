/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 01:02:23 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/30 07:51:50 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void get_algo(char *start, char *end, t_map *map)
{
	ft_printf("%i\n##start\n%s\n##end\n%s\n%s\n", map->nb ,start, end, map->link->content);
}

void get_link(char *line, t_map *map)
{
	ft_lstadd_back(&(map->link), ft_lstnew(line, ft_strlen(line) + 1));
}

void get_room(char *line, t_map *map)
{
	ft_lstadd_back(&(map->link), ft_lstnew(line, ft_strlen(line) + 1));
}

void put_err(int err)
{
	if (err == 1)
		ft_putstr_fd("ERROR: no files\n", 2);
	else if (err == 2)
		ft_putstr_fd("ERROR: no ants or not valid files\n", 2);
	else if (err == 3)
		ft_putstr_fd("ERRO: room start or end are not corect\n", 2);
	else if (err == 4)
		ft_putstr_fd("ERRO: no room start or end finded\n", 2);
}
