/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 01:51:43 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/10 07:54:09 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t		size;
	int			symbol;
	int			tmp;
	char		*new;

	symbol = 0;
	if (n < 0)
		symbol = 1;
	tmp = n;
	size = 1;
	while ((tmp /= 10))
		size++;
	if (!(new = ft_strnew(size + symbol)))
		return (NULL);
	if (symbol)
		new[0] = '-';
	new[size + symbol + 1] = '\0';
	while (size--)
	{
		new[size + symbol] = (symbol ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (new);
}
