/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:43:48 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/19 22:31:09 by niludwig         ###   ########.fr       */
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

t_list			*get_map(int *nb_ants);//ft_getleminmap
t_list			*ft_getinput(void);
int				ft_initleminmap(t_list **tmp, t_list **map, int *nb_ants);
int				ft_treatline(t_list **file, t_list **map, int *nb_ants);
void			ft_treatcommands(t_list **file, t_list **map);
int				ft_checkroomfmt(char *line);
int				ft_checkname(char *name, t_list *map);
int				ft_checkpipefmt(char *line);
void			ft_createroom(char *line, t_list **map, int se);
int				ft_getpipes(t_list *file, t_list **map);
void			ft_delhill(void *content);
void			ft_fillmapwithants(t_list *map, int nb_ants);

/*
** predicate
*/

int				ft_ismapvalid(t_list *map);
int				ft_ispipevalid(t_room *r1, t_room *r2);
int				ft_seemshillvalid(t_list *map);

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

#endif
