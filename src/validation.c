/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:50:25 by jvoor             #+#    #+#             */
/*   Updated: 2019/06/20 00:50:27 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**replace_sharp(char **str)
{
	int			tetri;
	int			i;
	char		sym;

	tetri = -1;
	sym = 65;
	while (str[++tetri])
	{
		i = 0;
		while (str[tetri][i] && sym <= 'Z')
		{
			if (str[tetri][i] == '#')
				str[tetri][i] = sym;
			i++;
		}
		sym++;
	}
	return (str);
}

int				bond(char *str)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				count++;
			if (str[i + 5] == '#')
				count++;
			if (str[i - 1] == '#')
				count++;
			if (str[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

int				symbol(char *str, char c)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
	{
		if (str[len] == c)
			i++;
		len++;
	}
	return (i);
}

int				end_line(char *str)
{
	int			count;
	int			len;

	count = 0;
	len = 4;
	if (str == NULL)
		return (0);
	while (str[len] && len < 21)
	{
		if (str[len] == '\n')
			count++;
		len = len + 5;
	}
	return (count);
}

int				valid(char **str)
{
	int			i;
	int			endl;
	int			bnd;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != NULL)
	{
		endl = end_line(str[i]);
		bnd = bond(str[i]);
		if ((symbol(str[i], '.') == 12 && symbol(str[i], '#') == 4) &&
			(endl == 4 || endl == 3) && (bnd == 6 || bnd == 8))
			i++;
		else
			return (0);
	}
	if (str[i] == NULL)
		return (1);
	return (0);
}
