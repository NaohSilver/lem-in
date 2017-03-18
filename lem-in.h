/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:43:48 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/16 21:58:51 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define print ft_printf(" ------- %i -------\n", i)

# include "libft/libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/libft/get_next_line.h"

typedef struct	s_room
{
	char		*start;
	char		*end;
}				t_room;

#endif
