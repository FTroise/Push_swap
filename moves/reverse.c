/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:24:14 by ftroise           #+#    #+#             */
/*   Updated: 2023/11/18 15:28:52 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack, int t)
{
	int	tmp;
	int	i;

	i = stack->la - 1;
	tmp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = tmp;
	if (t == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int t)
{
	int	tmp;
	int	i;

	i = stack->lb - 1;
	tmp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	if (t == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack, int t)
{
	rra(stack, 0);
	rrb(stack, 0);
	if (t == 1)
		write(1, "rrr\n", 4);
}
