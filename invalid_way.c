/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 22:15:15 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/19 22:30:35 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		ft_lstdelbyfunc(t_list **alst, void (*del)(void *content))
{
	t_list		*tmp;
	t_list		*tmp2;

	tmp = *alst;
	while (tmp)
	{
		if (del)
			del(tmp->content);
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}

void		ft_invaliduselessways(t_list *map)
{
	int			way;
	t_room		*start;
	t_room		*keep;
	t_room		*tmp;

	way = 1;
	start = ft_getroomwid(map, 1);
	while (ft_getroomwway(start->pipes, way))
	{
		map = start->pipes;
		keep = ft_getroomwbalance(start->pipes, way);
		if (keep == NULL)
			break ;
		while (map)
		{
			tmp = map->content;
			if (tmp->way == way && tmp != keep)
				tmp->way = -1;
			map = map->next;
		}
		way++;
	}
}
