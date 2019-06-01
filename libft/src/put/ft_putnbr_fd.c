/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 01:54:06 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/10 08:23:56 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printnegative(int n, int fd)
{
	if (n <= -10)
		ft_printnegative(n / 10, fd);
	ft_putchar_fd((0 - (n % 10)) + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (!fd)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_printnegative(n, fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
