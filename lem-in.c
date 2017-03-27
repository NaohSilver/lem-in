/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 01:02:23 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/27 05:02:58 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int get_start(char *line, t_map *map)
{
	int i;

	i = 0;
	while (line[i] != ' ')
		++i;
	if (i == 0)
		map->err = 3;
	return (i);
}

static t_map *get_end(char *line, t_map *map)
{
	int len;

	free(line);
	get_next_line(0, &line);
	len = get_start(line, map);
	if (get_err(line) == 1)
	{
		print;
		map->err = 3;
		return (map);
	}
	else
	{
		map->end = (char*)malloc(sizeof(char) * (len + 1));
		ft_strncpy(map->end, line, len);
		map->end[len] = '\0';
		return (map);
	}
}

static t_map get_line(char *line, t_map *map)
{
	int len;

	if (ft_strncmp("##start", line, 7) == 0)
	{
		free(line);
		get_next_line(0, &line);
		len = get_start(line, map);
		if (len == 0)
			return(*map);
		if (get_err(line) == 1)
		{
			map->err = 3;
			return (*map);
		}
		else
		{
			map->start = (char*)malloc(sizeof(char) * (len + 1));
			ft_strncpy(map->start, line, len);
			map->start[len] = '\0';
			free(line);
			return (*map);
		}
	}
	else if (ft_strncmp("##end", line, 5) == 0)
	{
		map = get_end(line, map);
		if (ft_strlen(line) == 0)
			map->err = 3;
		return(*map);
	}
	else
		return (*map);
}

static int map_nb(char *line)
{
	int i;

	i = ft_atoi(line);
	if (i <= 0)
	{
		put_err(2);
		free(line);
		return (0);
	}
	else
		return (i);
}

int main(void)
{
	char *line;
	t_map map;

	map = set_map(&map);
	get_next_line(0, &line);
	if ((map.nb = map_nb(line)) <= 0)
		return (0);
	else
	{
		free(line);
		while (get_next_line(0, &line) > 0)
		{
			print;
			if ((ft_strncmp("#", line, 1) == 0) || (ft_strncmp("L", line, 1) == 0))
				map = get_line(line, &map);
			else
				map = get_link(line, &map);
			if (map.err > 0)
			{
				put_err(map.err);
				return (0);
			}
		}
	}
	if (map.start == NULL || map.end == NULL)
		put_err(4);
	return (0);
}
