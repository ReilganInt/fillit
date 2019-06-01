/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:26:04 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/01 19:54:22 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				solve(t_tetris *tetris, const int count, uint16_t *map)
{
	int			size;

	size = 2;
	while (size * size < count * 4)
		size++;
	while (!try_map(tetris, size, map) && size <= 16)
	{
		ft_bzero(map, MAX_SIZE);
		size++;
	}
	return (size == 17 ? 0 : size);
}

void				give_coord(const t_tetris *tetris, uint16_t *map)
{
	*(uint64_t *)(map + tetris->y) ^= tetris->value >> tetris->x;
}

int				check_coord(const t_tetris *tetris, uint16_t *map)
{
	if ((tetris->value >> tetris->x) & (*(uint64_t *)(map + tetris->y)))
		return (0);
	else
		return (1);
}

int				try_map(t_tetris *tetris, const int size, uint16_t *map)
{
	int			i;

	if (tetris->id == 0)
		return (1);
	i = (tetris->last ? (tetris->last->x + tetris->last->y * size) : 0);
	tetris->y = i / size;
	while (tetris->y <= size - tetris->height)
	{
		tetris->x = (tetris->y == i / size ? i % size : 0);
		while (tetris->x <= size - tetris->width)
		{
			if (check_coord(tetris, map))
			{
				give_coord(tetris, map);
				if (try_map(tetris + 1, size, map))
					return (1);
				give_coord(tetris, map);
			}
			tetris->x++;
		}
		tetris->y++;
	}
	tetris->x = 0;
	tetris->y = 0;
	return (0);
}
