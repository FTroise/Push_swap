/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:36:04 by ftroise           #+#    #+#             */
/*   Updated: 2023/02/06 20:17:50 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (tofind[i] == '\0')
		return ((char *) s);
	if (len == 0)
		return (0);
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i + j] == tofind[j] && tofind[j] && i + j < len)
			j++;
		if (tofind[j] == '\0')
			return ((char *) s + i);
		i++;
	}
	return (0);
}
