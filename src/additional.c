/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:49:58 by jvoor             #+#    #+#             */
/*   Updated: 2019/06/20 00:50:00 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					square(int count)
{
	int				max;

	max = 2;
	while (max * max < count * 4)
		max++;
	return (max);
}

int					count_tetri(char **str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void				free_map(char **map, char **buff, t_coord *coord)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!map || !buff)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	while (buff[j])
	{
		free(buff[j]);
		j++;
	}
	free(map);
	free(buff);
	free(coord);
}
