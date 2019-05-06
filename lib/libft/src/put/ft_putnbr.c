/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:10 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/10 06:52:48 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printnegative(int nb)
{
	if (nb <= -10)
		ft_printnegative(nb / 10);
	ft_putchar((0 - (nb % 10)) + 48);
}

void			ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_printnegative(nb);
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}
