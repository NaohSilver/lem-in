/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:45:40 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/18 23:37:03 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int get_space(char *line)
{
	int i;

	i = -1;
	while (++i && line[i] != ' ')
		;
	return (i);
}

void get_in(char *line, char *room, int u)
{
	int i;

	i = 0;
	while (i != u)
	{
		room[i] = line[i];
		++i;
	}
	room[u] = '\0';
}

static void get_room(char *line, t_room *room)
{
	int i;

	i = 0;
	if (ft_strncmp(line, "##start", 7) == 0)
	{
		free(line);
		get_next_line(0, &line);
		i = get_space(line);
		room->start = (char*)malloc(sizeof(char) * i + 1);
		get_in(line, room->start, i + 1);
	}
	if (ft_strncmp(line, "##end", 5) == 0)
	{
		free(line);
		get_next_line(0, &line);
		i = get_space(line);
		room->end = (char*)malloc(sizeof(char) * i + 1);
		get_in(line, room->end, i + 1);
	}
}

static int get_ant(char *line)
{
	int nb;

	nb = ft_atoi(line);
	if (nb == 0)
	{
		free(line);
		return (0);
	}
	free(line);
	return (nb);
}

int main(void)
{
	t_room room;
	char *line;
	t_ant ant;

	get_next_line(0, &line);
	ant.nb = get_ant(line);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "#", 1) == 0)
			get_room(line, &room);
		free(line);
	}
	ft_printf("nb de ant %i\nstart = %s\nend = %s\n", ant.nb, room.start, room.end);
	return (0);
}
