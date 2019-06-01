/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:25:56 by vmormont          #+#    #+#             */
/*   Updated: 2019/05/30 13:31:08 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Function to get minimal and maximum values for get_part.
**	i is a 4 dimensional array encoded as:
**	xMinimum 0, xMaximum 1, yMinimum 2, yMaximum 3.
*/

void				get_limits(const char *str, char *lim)
{
	unsigned char	i;

	i = 0;
	lim[0] = 3;
	lim[2] = 3;
	lim[1] = 0;
	lim[3] = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < lim[0])
				lim[0] = i % 5;
			if (i % 5 > lim[1])
				lim[1] = i % 5;
			if (i / 5 < lim[2])
				lim[2] = i / 5;
			if (i / 5 > lim[3])
				lim[3] = i / 5;
		}
		i++;
	}
}

/*
**	Reads a part from a valid fragment and puts that in
**	the t_tetris structure.
*/

t_tetris			get_part(const char *str, const char id)
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

/*
**	Checks bond counts, if we have 6 or 8 bonds, the tetrimino is
**	valid.
*/

int					check_bond(const char *str)
{
	int				i;
	int				symbol;

	symbol = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i - 1) < 20 && str[i - 1] == '#')
				symbol++;
			if ((i + 1) < 20 && str[i + 1] == '#')
				symbol++;
			if ((i - 5) < 20 && str[i - 5] == '#')
				symbol++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				symbol++;
		}
		i++;
	}
	return (symbol == 6 || symbol == 8);
}

/*
**	Check character counts and that fragment format is valid.
*/

int					check_counts(const char *str, const int count)
{
	int				i;
	int				symbols;

	symbols = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++symbols > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (4);
	if (!check_bond(str))
		return (5);
	return (0);
}

/*
**	Read tetriminos from fd and put them in our tetrimino array.
**	Need use 21 sized reads to read part by part since there are
**	4 lines made of 4 characters and "\n" and "\0".
*/

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
		if (check_counts(buff, count) != 0)
			return (0);
		tetris[i] = get_part(buff, cur++);
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
