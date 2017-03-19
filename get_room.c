/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 22:12:26 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/19 22:13:11 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room		*ft_getroomwid(t_list *map, int id)
{
	t_room	*res;
	t_room	*tmp;

	tmp = map->content;
	res = NULL;
	while (map)
	{
		tmp = map->content;
		if (tmp->id == id)
			res = tmp;
		map = map->next;
	}
	return (res);
}

t_room		*ft_getroomwway(t_list *map, int way)
{
	int		weight;
	t_room	*tmp;
	t_room	*res;

	res = NULL;
	weight = 0;
	while (map)
	{
		tmp = map->content;
		if (tmp->id == 0)
			return (tmp);
		if (tmp->way == way && (weight > tmp->ok || weight == 0) &&
			tmp->nb_ants == 0)
		{
			res = tmp;
			weight = tmp->ok;
		}
		map = map->next;
	}
	return (res);
}

t_room		*ft_getroomwbalance(t_list *map, int way)
{
	int			weight;
	t_room		*res;
	t_room		*tmp;

	weight = 0;
	res = NULL;
	while (map)
	{
		tmp = map->content;
		if ((tmp->ok < weight || weight == 0) && tmp->way != -1 &&
			(tmp->way == way || way == 0) && tmp->nb_ants == 0 && tmp->ok != -1)
		{
			res = tmp;
			weight = tmp->ok;
		}
		map = map->next;
	}
	return (res);
}
