/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:26:04 by vmormont          #+#    #+#             */
/*   Updated: 2019/05/30 10:30:58 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Checks for a part
*/

int				check_part(const t_tetris *tetris, uint16_t *map)
{
	return (!(*(uint64_t *)(map + tetris->y) & (tetris->value >> tetris->x)));
}

/*
**	Switches off a partcs
*/

void			switch_part(const t_tetris *tetris, uint16_t *map)
{
	*(uint64_t *)(map + tetris->y) ^= tetris->value >> tetris->x;
}

/*
**	Backtracking implementation of the solver.
*/

int				solve_map(t_tetris *tetris, const int size, uint16_t *map)
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
			if (check_part(tetris, map))
			{
				switch_part(tetris, map);
				if (solve_map(tetris + 1, size, map))
					return (1);
				switch_part(tetris, map);
			}
			tetris->x++;
		}
		tetris->y++;
	}
	tetris->x = 0;
	tetris->y = 0;
	return (0);
}

/*
**	We tryies to solve maps starting from the minimal possible size.
*/

int				solve(t_tetris *tetris, const int count, uint16_t *map)
{
	int			size;

	size = 2;
	while (size * size < count * 4)
		size++;
	while (!solve_map(tetris, size, map) && size <= 16)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	return (size == 17 ? 0 : size);
}
