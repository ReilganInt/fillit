/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:49:52 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/20 00:49:54 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_pos(char **map, t_coord coord)
{
	int			x;
	int			y;
	int			i;

	y = 0;
	i = 0;
	while (map[y])
	{
		x = 0;
		while (map[x])
		{
			if (coord.x[i] == x && coord.y[i] == y && map[y][x] != '.')
				return (0);
			else if (coord.x[i] == x && coord.y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

t_coord			absolute_pos(t_coord coord, int x, int y)
{
	int			xmin;
	int			ymin;
	int			i;

	xmin = 999;
	ymin = 999;
	i = 0;
	while (i < 4)
	{
		if (coord.x[i] < xmin)
			xmin = coord.x[i];
		if (coord.y[i] < ymin)
			ymin = coord.y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		coord.x[i] = coord.x[i] - xmin + x;
		coord.y[i] = coord.y[i] - ymin + y;
		i++;
	}
	return (coord);
}
