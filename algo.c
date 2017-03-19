/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 22:07:35 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/19 22:08:41 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r')
		return (1);
	else
		return (0);
}

void		ft_lstaddtail(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst && *alst)
	{
		tmp = *alst;
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (tmp)
			tmp->next = new;
	}
	else if (alst)
		*alst = new;
}

static void	ft_balance(t_room *room, int way, int weight)
{
	t_list		*pipes;

	if (room->id == 0)
		return ;
	if (room->id == 1)
	{
		room->ok = weight;
		return ;
	}
	if (room->ok == -1 || room->ok > weight)
	{
		room->way = way;
		room->ok = weight;
	}
	else
		return ;
	pipes = room->pipes;
	while (pipes)
	{
		ft_balance(pipes->content, way, weight + 1);
		pipes = pipes->next;
	}
}

void		ft_initpond(t_list *map)
{
	t_room		*end;
	t_list		*pipes;
	int			way;

	end = map->content;
	way = 1;
	while (end->id != 0)
	{
		map = map->next;
		end = map->content;
	}
	pipes = end->pipes;
	end->ok = 1;
	while (pipes)
	{
		ft_balance(pipes->content, way, 2);
		way++;
		pipes = pipes->next;
	}
}
