/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:51:07 by ftroise           #+#    #+#             */
/*   Updated: 2024/01/21 17:27:07 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(char **av)
{
	int	i;

	i = 0;
	while (*av)
	{
		av++;
		i++;
	}
	return (i);
}

int	atoi_pushsap(char *str, int *stack)
{
	long			n;
	int				s;
	unsigned int	i;

	i = 0;
	n = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(stack);
		n = (str[i] - '0') + (n * 10);
		i++;
	}
	n = n * s;
	if (n < INT_MIN || n > INT_MAX)
		ft_error(stack);
	n = (int)n;
	return (n);
}

void	check_doub(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
				ft_error(stack);
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	ft_error(int *stack)
{
	free(stack);
	write(1, "Error\n", 6);
	exit (1);
}

char	**sub_split(char **av, int size)
{
	int				i;
	int				x;
	int				y;
	char			**sub_mat;
	char			**mat;

	i = 0;
	x = 0;
	mat = (char **)malloc(sizeof(char *) * size);
	while (av[i])
	{
		sub_mat = ft_split(av[i], ' ');
		y = 0;
		while (sub_mat[y])
		{
			mat[x] = malloc(ft_strlen(sub_mat[y]));
			ft_strlcpy(mat[x], sub_mat[y], ft_strlen(*sub_mat) + 1);
			x++;
			y++;
		}
		i++;
		free_matrix(sub_mat);
	}
	mat[x] = NULL;
	return (mat);
}
