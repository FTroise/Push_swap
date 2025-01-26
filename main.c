/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 01:02:59 by ftroise           #+#    #+#             */
/*   Updated: 2024/01/21 17:26:35 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	make_stack_int_e_ceck_dub_sort(char **av)
{
	t_stack	stk;
	int		size;
	int		i;

	i = -1;
	size = stack_len(av);
	stk.stack_a = malloc(sizeof(int) * size);
	if (!stk.stack_a)
		return ;
	stk.la = size;
	stk.stack_b = malloc(sizeof(int) * size);
	if (!stk.stack_b)
	{
		free(stk.stack_a);
		return ;
	}
	stk.lb = 0;
	while (++i < size)
		stk.stack_a[i] = atoi_pushsap(av[i], stk.stack_a);
	check_doub(stk.stack_a, size);
	sort(&stk, size);
	free(stk.stack_a);
	free(stk.stack_b);
}

int	main(int ac, char **av)
{
	char	**tab;

	tab = NULL;
	av++;
	if (ac > 1)
	{
		if (ac == 2)
		{
			av = ft_split(*av, ' ');
			make_stack_int_e_ceck_dub_sort(av);
		}
		else if (ac > 1 && ac != 2)
		{
			tab = sub_split(av, ac);
			make_stack_int_e_ceck_dub_sort(tab);
		}
	}
	if (ac == 2)
		free_matrix(av);
	free_matrix(tab);
	return (0);
}
