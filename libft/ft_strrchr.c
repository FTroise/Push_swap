/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:07:29 by ftroise           #+#    #+#             */
/*   Updated: 2023/02/06 20:17:57 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;
	char	*str;

	j = ft_strlen(s);
	str = (char *)s;
	while (j >= 0)
	{
		if (str[j] == (char)c)
			return ((char *)s + j);
		j--;
	}
	return (NULL);
}
