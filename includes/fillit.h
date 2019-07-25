/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 01:01:40 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/20 01:01:42 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include <string.h>

# define BUFF_SIZE 600

typedef struct				s_coord
{
	int						x[4];
	int						y[4];
	char					sym;
}							t_coord;

void						free_map(char **map, char **buff, t_coord *coord);
int							valid(char **str);
char						**replace_sharp(char **str);
char						**get_tetri(char *str);
void						solver(void);
char						**new_map(char **map, int size);
char						**solve(t_coord *tetriminos,
									int size, int nbr_tetri);
void						print_map(char **str, char **buff, t_coord *coord);
int							count_tetri(char **str);
int							square(int count);
int							check_pos(char **map, t_coord tetriminos);
t_coord						*get_coord(char **str, int nbr_tetri);
t_coord						absolute_pos(t_coord tetriminos, int x, int y);

#endif
