/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 01:02:34 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/27 04:39:49 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define print ft_printf("%s\n", line);

# include "libft/libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/libft/get_next_line.h"

typedef struct	s_map
{
	int			nb;
	int			err;
	char		*start;
	char		*end;
	t_list		*link;
}				t_map;

t_map			set_map(t_map *map);
int				ft_iswhitespace(char c);
void			put_err(int err);
int				ft_isend(char c);
int				get_err(char *line);
t_map			get_link(char *line, t_map *map);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			get_yolo(t_map *map);
#endif
