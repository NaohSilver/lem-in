/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:45:40 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/19 22:25:19 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	t_list	*map;
	int		nb_ants;

	map = get_map(&nb_ants);
	if (map)
	{
		ft_initpond(map);
		if (ft_ismapvalid(map) == 2)
		{
			write(1, "\n", 1);
			ft_invaliduselessways(map);
			ft_initants(nb_ants, map, parse);
			ft_free_parse(parse);
			ft_lstdelbyfunc(&map, &ft_delhill);
		}
		else
		{
			ft_putstr_fd("\n--ERROR : No ways to the end--\n", 2);
			return (0);
		}
	}
	return (1);
}
