/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:53:05 by ftroise           #+#    #+#             */
/*   Updated: 2024/01/19 19:29:49 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_push(t_stack *stk, int len, int push)
{
	if (push == 0)
		pb(stk, 1);
	else
		pa(stk, 1);
	len--;
	return (len);
}

int	check_sorted(int *stack, int size, int order)
{
	int	i;

	if (order == 0)
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] > stack[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	temporary_sort(int *stk_tmp, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stk_tmp[i] > stk_tmp[j])
			{
				tmp = stk_tmp[i];
				stk_tmp[i] = stk_tmp[j];
				stk_tmp[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	mid_number(int *pivot, int *stk, int size)
{
	int		*tmp_stk;
	int		i;

	tmp_stk = (int *)malloc(size * sizeof(int));
	if (!tmp_stk)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_stk[i] = stk[i];
		i++;
	}
	temporary_sort(tmp_stk, size);
	*pivot = tmp_stk[size / 2];
	free(tmp_stk);
	return (1);
}

void	quicksort_stacks(t_stack *stk, int len)
{
	if (len == 3 && stk->la == 3)
		sort_3_a(stk);
	else if (len == 2)
	{
		if (stk->stack_a[0] > stk->stack_a[1])
			sa(stk, 1);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stk->stack_a[0] < stk->stack_a[1] \
		&& stk->stack_a[1] < stk->stack_a[2]))
		{
			if (len == 3 && stk->stack_a[0] > stk->stack_a[1] \
			&& stk->stack_a[2])
				sa(stk, 1);
			else if (len == 3 && !(stk->stack_a[2] > stk->stack_a[0]
					&& stk->stack_a[2] > stk->stack_a[1]))
				len = ft_push(stk, len, 0);
			else if (stk->stack_a[0] > stk->stack_a[1])
				sa(stk, 1);
			else if (len++)
				pa(stk, 1);
		}
	}
}
