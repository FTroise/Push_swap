/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:40:23 by ftroise           #+#    #+#             */
/*   Updated: 2024/01/21 17:58:57 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*ft_strjoin2(char *str1, char *str2)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = malloc(ft_strlen2(str1) + ft_strlen2(str2) + 1);
	if (!newstr)
		return (NULL);
	while (str1 && str1[i])
	{
		newstr[i] = str1[i];
		i++;
	}
	free(str1);
	while (*str2)
	{
		newstr[i++] = *str2;
		if (*str2++ == '\n')
			break ;
	}
	newstr[i] = '\0';
	return (newstr);
}

static int	clean_buff(char *buff)
{
	int	i;
	int	new_line;
	int	j;

	i = 0;
	j = 0;
	new_line = 0;
	while (buff[i])
	{
		if (new_line)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			new_line = 1;
		buff[i++] = '\0';
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (buff[i])
			buff[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin2(line, buff);
		if (clean_buff(buff))
			break ;
	}
	return (line);
}

void	free_matrix(char **av)
{
	int	i;

	i = -1;
	if (!av)
		return ;
	while (av[++i])
		free(av[i]);
	free(av);
}
