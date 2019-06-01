/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:40:09 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/01 19:53:02 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*start_map(int size)
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
			str[x + (size + 1) * y] = '.';
			x++;
		}
		str[x + (size + 1) * y] = '\n';
		y++;
	}
	return (str);
}
