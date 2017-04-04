/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 01:02:23 by niludwig          #+#    #+#             */
/*   Updated: 2017/04/04 16:42:34 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void get_st(char *str, char *str2)
{
	int i;

	i = 0;
	while (ft_iswhitespace(str[i]) != 1)
		++i;
	str[i] = '\0';
	i = 0;
	while (ft_iswhitespace(str2[i]) != 1)
		++i;
	str2[i] = '\0';
}

static void ft_road(char **link, t_map *map, char *st, char *end)
{
	get_st(st, end);
	ft_printf("%s\n%s\n%s\n%i\n", st, end, link[0], map->nb);
}

void get_algo(char *start, char *end, t_map *map)
{
	char **str = NULL;
	int i;

	i = 0;
	if (start == NULL || end == NULL || map->nb < 1)
	{
		put_err(4);
		return ;
	}
	else
	{
		str = (char**)malloc(sizeof(char*) * map->i);
		ft_printf("%i\n##start\n%s\n##end\n%s\n", map->nb ,start, end);
	}
	while (map->link->next)
	{
		ft_printf("%s\n", map->link->content);
		map->link = map->link->next;
		if (get_trait(map->link->content) == 1)
		{
			str[i] = (char*)malloc(sizeof(char)\
			* ft_strlen(map->link->content) + 1);
			str[i] = map->link->content;
			++i;
		}
	}
	++i;
	ft_printf("%s\n", map->link->content);
	if (get_trait(map->link->content) == 1 && ++i)
	{
		str[i] = (char*)malloc(sizeof(char)\
		* ft_strlen(map->link->content) + 1);
		str[i] = map->link->content;
	}
	ft_road(str, map, start, end);
}

void get_link(char *line, t_map *map)
{
	map->i += 1;
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
		ft_putstr_fd("ERROR: room start or end are not corect\n", 2);
	else if (err == 4)
		ft_putstr_fd("ERROR: no room start or end finded\n", 2);
}
