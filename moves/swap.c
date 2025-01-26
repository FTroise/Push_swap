/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:01:19 by ftroise           #+#    #+#             */
/*   Updated: 2024/01/19 20:11:11 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack, int t)
{
	int	tmp;

	if (stack->la < 2)
		return ;
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	if (t == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int t)
{
	int	tmp;

	if (stack->lb < 2)
		return ;
	tmp = stack->stack_b[1];
	stack->stack_b[1] = stack->stack_b[0];
	stack->stack_b[0] = tmp;
	if (t == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack, int t)
{
	sa(stack, 0);
	sb(stack, 0);
	if (t == 1)
		write(1, "ss\n", 3);
}
