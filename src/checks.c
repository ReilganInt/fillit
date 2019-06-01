/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:41:41 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/01 19:52:19 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					invalid(const char *str, const int count)
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
	if (!sharps(str))
		return (5);
	return (0);
}

int					sharps(const char *str)
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
