/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 22:05:31 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/19 22:06:39 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		ft_fillmapwithants(t_list *map, int nb_ants)
{
	t_room	*tmp;

	while (map)
	{
		tmp = map->content;
		if (tmp->id == 1)
		{
			tmp->ok = nb_ants;
			return ;
		}
		map = map->next;
	}
}

int			ft_treatleminerror(int ret)
{
	if (ret == 0)
		ft_printf("\nERROR : Bad declaration of ants\n%@", 2);
	else if (ret == -1)
		ft_printf("\nERROR : Bad format for line\n%@", 2);
	else if (ret == -2)
		ft_printf("\nERROR : Bad room name in pipes declaration\n%@", 2);
	return (0);
}

int			ft_initleminmap(t_list **tmp, t_list **map, int *nb_ants)
{
	int		ret;

	while (*tmp)
	{
		if ((ret = ft_treatline(tmp, map, nb_ants)) > 0)
		{
			if (ret != 2 && *tmp)
				ft_printf("%s\n", (*tmp)->content);
		}
		else if (ft_seemshillvalid(*map) == 0)
		{
			ft_lstdelbyfunc(map, &ft_delhill);
			return (ft_treatleminerror(ret));
		}
		if (ret != 2 && tmp)
			*tmp = (*tmp)->next;
	}
	return (1);
}

t_list		*ft_getinput(void)
{
	t_list	*file;
	char	*line;

	file = NULL;
	line = NULL;
	while (get_next_line(0, &line) > 0 && *line != '\0')
	{
		ft_lstaddtail(&file, ft_lstnew(line, ft_strlen(line) + 1));
		if (!file)
			return (NULL);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	return (file);
}
