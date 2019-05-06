/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 23:45:37 by vmormont          #+#    #+#             */
/*   Updated: 2019/05/06 01:19:58 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_TETRIS 26
# include <fcntl.h>
# include <string.h>
# include <stdint.h>
# include "libft.h"

/*
**	Our tetramino structure when:
**	"value" - encrypted coordinates all "#" characters
**	"id" - character to fill map,
**	"x" - x
**	"y" - y
**	"width" - width current tetramino
**	"height" - height current tetramino
*/

typedef struct		s_tetris
{
	uint64_t		value;
	unsigned char	id;
	unsigned char	x;
	unsigned char	y;
	unsigned char	width;
	unsigned char	height;
	struct s_tetris	*last;
}					t_tetris;

int					end(char *str);
int					check_newline(const int fd);
void				print(t_tetris *tetris, int count, int size);
char				*fill_points(int size);
int					read_tetris(const int fd, t_tetris *tetris);
int					check_counts(const char *str, const int count);
int					check_bond(const char *str);
t_tetris			get_part(const char *str, const char id);
void				get_limits(const char *str, char *lim);
int					solve(t_tetris *tetris, const int count, uint16_t *map);
int					solve_map(t_tetris *tetris, const int size, uint16_t *map);
void				switch_part(const t_tetris *tetris, uint16_t *map);
int					check_part(const t_tetris *tetris, uint16_t *map);

#endif
