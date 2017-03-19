/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:43:48 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/19 23:26:33 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/libft/get_next_line.h"

typedef struct	s_room
{
	char		*name;
	int			ok;
	int			way;
	int			id;
	int			nb_ants;
	int			x;
	int			y;
	t_list		*pipes;
}				t_room;

typedef struct	s_double_room
{
	t_room		*start;
	t_room		*end;
}				t_double_room;

/*
** Initialisation
*/

t_list			*get_map(int *nb_ants);
t_list			*get_input(void);
int				init_map(t_list **tmp, t_list **map, int *nb_ants);
int				treat_line(t_list **file, t_list **map, int *nb_ants);
void			get_commands(t_list **file, t_list **map);
int				check_room(char *line);
int				check_name(char *name, t_list *map);
int				ft_checkpipefmt(char *line);//here
void			create_room(char *line, t_list **map, int se);
int				ft_getpipes(t_list *file, t_list **map);
void			ft_delhill(void *content);
void			ft_fillmapwithants(t_list *map, int nb_ants);

/*
** predicate
*/

int				ft_ismapvalid(t_list *map);
int				ft_ispipevalid(t_room *r1, t_room *r2);
int				not_valid(t_list *map);

int				ft_printmap(t_list *map);

/*
** Debut d'algo
*/

void			ft_initpond(t_list *map);
void			ft_initants(int nb_ants, t_list *map, t_parse *parse);
void			ft_invaliduselessways(t_list *map);

/*
** getrooms
*/

t_room			*ft_getroomwid(t_list *map, int id);
t_room			*ft_getroomwway(t_list *map, int way);
t_room			*ft_getroomwbalance(t_list *map, int way);

/*
** a remaitre dans la lib
*/

int				ft_iswhitespace(char c);
void			ft_lstaddtail(t_list **alst, t_list *new);
void			ft_lstdelbyfunc(t_list **alst, void (*del)(void *content));
int				ft_wordlen(char *str, char c);

#endif
