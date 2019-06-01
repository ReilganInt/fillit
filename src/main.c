/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:26:10 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/01 19:52:45 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_newline(const int fd)
{
	char		buff[572];
	int			count;

	if ((count = read(fd, buff, 572)) <= 572)
		if (buff[count - 2] == '\n' && buff[count - 1] == '\n')
			return (1);
	return (0);
}

int				main(int argc, char **argv)
{
	t_tetris	tetris[MAX_TETRIS + 1];
	uint16_t	map[16];
	int			count;
	int			size;

	if (argc != 2)
		return (end("usage: ./fillit [input_file]"));
	ft_bzero(tetris, sizeof(t_tetris) * (MAX_TETRIS + 1));
	if (check_newline(open(argv[1], O_RDONLY)))
		return (end("error"));
	if ((count = read_tetris(open(argv[1], O_RDONLY), tetris)) == 0)
		return (end("error"));
	ft_bzero(map, MAX_SIZE);
	if ((size = solve(tetris, count, map)) == 0)
		return (end("error"));
	print(tetris, count, size);
	return (0);
}
