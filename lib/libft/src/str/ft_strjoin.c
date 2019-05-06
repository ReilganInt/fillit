/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 04:36:26 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/13 18:21:35 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = ft_memalloc((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	return ((char *)new);
}
