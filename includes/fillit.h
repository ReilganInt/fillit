/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 23:45:37 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/01 19:52:55 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_TETRIS 26
# define MAX_SIZE sizeof(uint16_t) * 16
# include <fcntl.h>
# include <string.h>
# include <stdint.h>
# include "libft.h"

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
char				*start_map(int size);
int					read_tetris(const int fd, t_tetris *tetris);
int					invalid(const char *str, const int count);
int					sharps(const char *str);
t_tetris			get_tetramino(const char *str, const char id);
void				get_limits(const char *str, char *lim);
int					solve(t_tetris *tetris, const int count, uint16_t *map);
int					try_map(t_tetris *tetris, const int size, uint16_t *map);
void				give_coord(const t_tetris *tetris, uint16_t *map);
int					check_coord(const t_tetris *tetris, uint16_t *map);

#endif
