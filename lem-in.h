/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 01:02:34 by niludwig          #+#    #+#             */
/*   Updated: 2017/04/04 16:15:32 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/libft/get_next_line.h"

typedef struct	s_map
{
	int			nb;
	int			err;
	int			i;
	t_list		*link;
}				t_map;

void			get_link_room(char *line, t_map *map);
t_map			set_map(t_map *map, char *line);
void			get_link(char *line, t_map *map);
void			get_room(char *line, t_map *map);
int				ft_iswhitespace(char c);
void			put_err(int err);
void			ft_lstadd_back(t_list **alst, t_list *new);
int				ft_isend(char c);
void			get_algo(char *start, char *end, t_map *map);
int				get_trait(char *str);
#endif
