/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:50:04 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/20 00:50:06 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**split_tetri(char *str)
{
	size_t		i;
	size_t		len;

	i = 20;
	len = ft_strlen(str);
	while (str[i] && i < len - 2)
	{
		if (str[i] == '\n')
			str[i] = 'N';
		i = i + 21;
	}
	return (ft_strsplit(str, 'N'));
}

static int		check_len(char *str)
{
	int len;

	len = ft_strlen(str) + 1;
	if (len % 21 != 0 || len > 546)
		return (1);
	else
		return (0);
}

char			**get_tetri(char *str)
{
	int			i;
	int			fd;
	char		**tetri;
	char		buff[BUFF_SIZE + 1];

	tetri = NULL;
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0 || (read(fd, buff, BUFF_SIZE) < 0) || !buff[0] ||
			check_len(buff) == 1)
		return (NULL);
	tetri = split_tetri(buff);
	close(fd);
	return (tetri);
}

t_coord			*get_coord(char **str, int nbr_tetri)
{
	t_coord		*temp;
	int			i;
	int			j;
	int			x;
	int			y;

	j = -1;
	temp = (t_coord *)malloc(sizeof(t_coord) * (nbr_tetri + 1));
	while (str[++j])
	{
		i = -1;
		x = 0;
		y = 0;
		temp[j].sym = 66 + i + j;
		while (str[j][++i])
		{
			if (ft_isalpha(str[j][i]))
			{
				temp[j].x[x++] = i % 5;
				temp[j].y[y++] = i / 5;
			}
		}
	}
	return (temp);
}
