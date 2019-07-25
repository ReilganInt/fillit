/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:49:58 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/20 00:50:00 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				print_map(char **str, char **buff, t_coord *coord)
{
	int				i;

	i = -1;
	while (str[++i])
		ft_putendl(str[i]);
	free_map(str, buff, coord);
}

int					main(int argc, char *argv[])
{
	char			**map;
	char			**buff;
	t_coord			*coord;
	int				count;

	buff = NULL;
	map = NULL;
	if (argc != 2)
		write(1, "usage ./fillit [map]\n", 21);
	else
	{
		count = 2;
		buff = get_tetri(argv[1]);
		if (valid(buff) == 1)
		{
			buff = replace_sharp(buff);
			count = count_tetri(buff);
			coord = get_coord(buff, count);
			map = solve(coord, square(count), count);
			print_map(map, buff, coord);
		}
		else
			write(1, "error\n", 6);
	}
	return (0);
}
