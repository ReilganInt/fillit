/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:50:19 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/20 00:50:20 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char				**new_map(char **map, int size)
{
	int				x;
	int				y;

	y = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		map[y] = (char *)malloc(sizeof(char) * (size + 1));
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = NULL;
	return (map);
}

char				**back_step(char **map, t_coord coord)
{
	int				x;
	int				y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == coord.sym)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

char				**put_tetri(char **map, t_coord coord)
{
	int				x;
	int				y;
	int				i;

	i = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (coord.x[i] == x && coord.y[i] == y)
			{
				map[y][x] = coord.sym;
				i++;
			}
			x++;
		}
		y++;
	}
	return (map);
}

char				**try_to_fill(char **map, t_coord *coord, int count, int i)
{
	int				x;
	int				y;
	char			**tmp;

	y = 0;
	if (i == count)
		return (map);
	tmp = NULL;
	while (map[y] && i < count)
	{
		x = 0;
		while (map[y][x] && i < count)
		{
			coord[i] = absolute_pos(coord[i], x, y);
			if (check_pos(map, coord[i]) == 1)
				tmp = try_to_fill(put_tetri(map, coord[i]),
				coord, count, (i + 1));
			if (tmp != NULL)
				return (tmp);
			map = back_step(map, coord[i]);
			x++;
		}
		y++;
	}
	return (NULL);
}

char				**solve(t_coord *coord, int size, int count)
{
	char			**map;

	map = NULL;
	while (!map)
	{
		map = new_map(map, size);
		map = try_to_fill(map, coord, count, 0);
		size++;
	}
	return (map);
}
