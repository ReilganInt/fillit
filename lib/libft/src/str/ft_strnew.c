/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:32:56 by vmormont          #+#    #+#             */
/*   Updated: 2019/05/01 20:32:58 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	size = size + 1;
	if (size == 0)
		return (NULL);
	if (!(new = (char *)ft_memalloc(size)))
		return (NULL);
	return (new);
}
