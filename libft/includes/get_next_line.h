/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:06:21 by vmormont          #+#    #+#             */
/*   Updated: 2019/05/01 20:22:17 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"
# define BUFF_SIZE 1

typedef struct		s_fd
{
	int				fd;
	int				state;
	size_t			numlines;
	t_list			*res;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);

#endif
