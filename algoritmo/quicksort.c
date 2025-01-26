/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:53:05 by ftroise           #+#    #+#             */
/*   Updated: 2024/01/21 12:29:09 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort(t_stack *stk, int size)
{
	if (check_sorted(stk->stack_a, stk->la, 0) == 0)
	{
		if (size == 2)
			sa(stk, 1);
		else if (size == 3)
			sort_3_a(stk);
		else
			quicksort_a(stk, size, 0);
	}
	return (0);
}

void	sort_3_a(t_stack *stk)
{
	if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] < \
	stk->stack_a[2] && stk->stack_a[1] > stk->stack_a[2])
	{
		rra(stk, 1);
		sa(stk, 1);
	}
	else if (stk->stack_a[0] > stk->stack_a[1] && stk->stack_a[0] < \
	stk->stack_a[2] && stk->stack_a[1] < stk->stack_a[2])
		sa(stk, 1);
	else if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] > \
	stk->stack_a[2] && stk->stack_a[1] > stk->stack_a[2])
		rra(stk, 1);
	else if (stk->stack_a[1] < stk->stack_a[2] && stk->stack_a[0] > \
	stk->stack_a[1] && stk->stack_a[0] > stk->stack_a[2])
		ra(stk, 1);
	else if (stk->stack_a[1] > stk->stack_a[2] && stk->stack_a[0] > \
	stk->stack_a[1] && stk->stack_a[0] > stk->stack_a[2])
	{
		ra(stk, 1);
		sa(stk, 1);
	}
}

int	sort_3_b(t_stack *stk, int len)
{
	if (len == 1)
		pa(stk, 1);
	else if (len == 2)
	{
		if (stk->stack_b[0] < stk->stack_b[1])
			sb(stk, 1);
		while (len--)
			pa(stk, 1);
	}
	else if (len == 3)
	{
		while (len || !(stk->stack_a[0] < stk->stack_a[1] \
		&& stk->stack_a[1] < stk->stack_a[2]))
		{
			if (len == 1 && stk->stack_a[0] > stk->stack_a[1])
				sa(stk, 1);
			else if (len == 1 || (len >= 2 && stk->stack_b[0] > stk->stack_b[1])
				|| (len == 3 && stk->stack_b[0] > stk->stack_b[2]))
				len = ft_push(stk, len, 1);
			else
				sb(stk, 1);
		}
	}
	return (0);
}

int	quicksort_a(t_stack *stk, int len, int rot)
{
	int	pivot;
	int	numbers;

	if (check_sorted(stk->stack_a, len, 0) == 1)
		return (1);
	numbers = len;
	if (len <= 3)
	{
		quicksort_stacks(stk, len);
		return (1);
	}
	if (mid_number(&pivot, stk->stack_a, len) == 0)
		return (0);
	while (len != numbers / 2 + numbers % 2)
	{
		if (stk->stack_a[0] < pivot && (len--))
			pb(stk, 1);
		else if (++rot)
			ra(stk, 1);
	}
	while (numbers / 2 + numbers % 2 != stk->la && rot--)
		rra(stk, 1);
	return (quicksort_a(stk, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(stk, numbers / 2, 0));
	return (1);
}

int	quicksort_b(t_stack *stk, int len, int rot)
{
	int	pivot;
	int	numbers;

	if (check_sorted(stk->stack_b, len, 1) == 1)
		while (len--)
			pa(stk, 1);
	if (len <= 3)
	{
		sort_3_b(stk, len);
		return (1);
	}
	numbers = len;
	if (!mid_number(&pivot, stk->stack_b, len))
		return (0);
	while (len != numbers / 2)
	{
		if (stk->stack_b[0] >= pivot && len--)
			pa(stk, 1);
		else if (++rot)
			rb(stk, 1);
	}
	while (numbers / 2 != stk->lb && rot--)
		rrb(stk, 1);
	return (quicksort_a(stk, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(stk, numbers / 2, 0));
}
