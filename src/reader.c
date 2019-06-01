/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:25:56 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/01 19:53:22 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris			get_tetramino(const char *str, const char id)
{
	t_tetris		tetris;
	int				x;
	int				y;
	char			lim[4];

	get_limits(str, lim);
	tetris.id = id;
	tetris.value = 0;
	tetris.last = NULL;
	tetris.width = lim[1] - lim[0] + 1;
	tetris.height = lim[3] - lim[2] + 1;
	y = 0;
	while (y < tetris.height)
	{
		x = 0;
		while (x < tetris.width)
		{
			if (str[(lim[0] + x) + (lim[2] + y) * 5] == '#')
				tetris.value |= (1L << (16 * (y + 1) - x - 1));
			x++;
		}
		y++;
	}
	return (tetris);
}

int					read_tetris(const int fd, t_tetris *tetris)
{
	char			buff[22];
	int				count;
	int				i;
	int				j;
	char			cur;

	cur = 'A';
	i = 0;
	while ((count = read(fd, buff, 21)) >= 20)
	{
		if (invalid(buff, count) != 0)
			return (0);
		tetris[i] = get_tetramino(buff, cur++);
		j = i - 1;
		while (j >= 0)
		{
			if (tetris[j].value == tetris[i].value)
				tetris[j].last = tetris + j;
			j--;
		}
		i++;
	}
	if (count != 0)
		return (0);
	return (cur - 'A');
}
