/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 01:17:06 by niludwig          #+#    #+#             */
/*   Updated: 2017/04/04 16:15:41 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void get_free(t_map *map, char *str, char *str2)
{
	free(str);
	free(str2);
	while (map->link->next)
	{
		free(map->link->content);
		map->link = map->link->next;
	}
	free(map->link->content);
}

int get_trait(char *line)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (ft_iswhitespace(line[i]) != 1 && line[i])
	{
		if (line[i] == '-')
			k = 1;
		++i;
	}
	return (k);
}

void get_link_room(char *line, t_map *map)
{
	int i;

	i = 0;
	if (line[0] == '#')
		;
	else
	{
		while (ft_iswhitespace(line[i]) != 1 && line[i])
			++i;
		if (line[i] == ' ')
			get_room(line, map);
		else if (get_trait(line) == 1)
			get_link(line, map);
	}
}

t_map set_map(t_map *map, char *line)
{
	map->err = 0;
	map->i = 0;
	map->link = NULL;
	get_next_line(0, &line);
	map->nb = ft_atoi(line);
	free(line);
	return (*map);
}

int main(void)
{
	char *line = NULL;
	t_map map;
	char *start;
	char *end;

	map = set_map(&map, line);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp("##start", line, 7) == 0)
		{
			free(line);
			get_next_line(0, &line);
			start = (char*)malloc(sizeof(char) * ft_strlen(line) + 1);
			ft_strcpy(start, line);
		}
		else if (ft_strncmp("##end", line, 5) == 0)
		{
			free(line);
			get_next_line(0, &line);
			end = (char*)malloc(sizeof(char) * ft_strlen(line) + 1);
			ft_strcpy(end, line);
		}
		else if (ft_iswhitespace(line[0]) != 1 && line[0] != '\0')
			get_link_room(line, &map);
		free(line);
	}
	get_algo(start, end, &map);
	get_free(&map, end, start);
	return (0);
}
