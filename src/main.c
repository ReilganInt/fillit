/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:26:10 by vmormont          #+#    #+#             */
/*   Updated: 2019/05/06 06:00:51 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Allocates an fiil points map string to populate with our parts
*/

char			*fill_points(int size)
{
	char		*str;
	int			x;
	int			y;

	str = ft_strnew((size + 1) * (size));
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			str[y * (size + 1) + x] = '.';
			x++;
		}
		str[y * (size + 1) + x] = '\n';
		y++;
	}
	return (str);
}

/*
**	Print a map as resolved by the programm
*/

void			print(t_tetris *tetris, int count, int size)
{
	char		*str;
	int			x;
	int			y;

	str = fill_points(size);
	while (count > 0)
	{
		y = 0;
		while (y < tetris->height)
		{
			x = 0;
			while (x < tetris->width)
			{
				if ((tetris->value >> (16 * (y + 1) - x - 1)) & 1)
					str[(tetris->y + y) * (size + 1)
						+ x + tetris->x] = tetris->id;
				x++;
			}
			y++;
		}
		tetris++;
		count--;
	}
	ft_putstr(str);
	ft_strdel(&str);
}

/*
**	Function to end programm with some "errors"
*/

int				end(char *str)
{
	ft_putendl(str);
	return (1);
}

/*
**	Check double newline at end of file
*/

int				check_newline(const int fd)
{
	char		buff[572];
	int			count;

	if ((count = read(fd, buff, 572)) <= 572)
		if (buff[count - 2] == '\n' && buff[count - 1] == '\n')
			return (1);
	return (0);
}

/*
**	Entry point for our programm
*/

int				main(int argc, char **argv)
{
	t_tetris	tetris[MAX_TETRIS + 1];
	uint16_t	map[16];
	int			count;
	int			size;

	if (argc != 2)
		return (end("usage: ./fillit [input_file]"));
	ft_bzero(tetris, sizeof(t_tetris) * (MAX_TETRIS + 1));
	if (check_newline(open(argv[1], O_RDONLY)))
		return (end("error"));
	if ((count = read_tetris(open(argv[1], O_RDONLY), tetris)) == 0)
		return (end("error"));
	ft_bzero(map, sizeof(uint16_t) * 16);
	if ((size = solve(tetris, count, map)) == 0)
		return (end("error"));
	print(tetris, count, size);
	return (0);
}
