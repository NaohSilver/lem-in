/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:45:40 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/16 21:57:44 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int get_space(char *line)
{
	int i;

	i = -1;
	while (++i && line[i] != ' ')
		;
	++i;
	return (i);
}

static void get_room(char *line, t_room *room)
{
	int i;

	i = get_space(line);
	if (ft_strncmp(line, "##start", 7) == 0)
	{
		get_next_line(0, &line);
		room->start = (char*)malloc(sizeof(char) * i);
		print;
		ft_strncpy(room->start, line, i);
		room->start[i] = '\0';
		free(line);
	}
	if (ft_strncmp(line, "##end", 5) == 0)
	{
		get_next_line(0, &line);
		room->end = (char*)malloc(sizeof(char) * i);
		print;
		ft_bzero(room->end, i);
		ft_strncpy(room->end, line, i);
		room->end[i] = '\0';
		free(line);
	}
	else
		;
}

int main(void)
{
	t_room room;
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "#", 1) == 0)
			get_room(line, &room);
		else
			;
		free(line);
	}
	ft_printf("start = %s\nend = %s\n", room.start, room.end);
	return (0);
}
