/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 05:05:51 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/27 05:01:03 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *list;

	list = *alst;
	new->next = NULL;
	if (!(*alst))
		*alst = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

t_map get_link(char *line, t_map *map)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			ft_lstadd_back(&(map->link), ft_lstnew(line, sizeof(char*)\
			* ft_strlen(line) + 1));
		++i;
	}
	free(line);
	map->err = 0;
	return (*map);
}
