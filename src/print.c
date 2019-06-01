/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:34:15 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/01 19:53:10 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print(t_tetris *tetris, int count, int size)
{
	char	*str;
	int		x;
	int		y;

	str = start_map(size);
	while (count > 0)
	{
		y = 0;
		while (y < tetris->height)
		{
			x = 0;
			while (x < tetris->width)
			{
				if (1 & (tetris->value >> ((y + 1) * 16 - x - 1)))
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
