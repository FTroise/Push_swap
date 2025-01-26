/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:39:05 by ftroise           #+#    #+#             */
/*   Updated: 2024/01/19 20:07:09 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack, int t)
{
	int	i;

	if (!stack->stack_b)
		return ;
	stack->la++;
	i = stack->la - 1;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i < stack->lb - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->lb--;
	if (t == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack, int t)
{
	int	i;

	if (!stack->stack_a)
		return ;
	stack->lb++;
	i = stack->lb - 1;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i < stack->la - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->la--;
	if (t == 1)
		write(1, "pb\n", 3);
}
