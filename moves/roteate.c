/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roteate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:13:43 by ftroise           #+#    #+#             */
/*   Updated: 2024/01/19 20:07:19 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack, int t)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->la < 2)
		return ;
	tmp = stack->stack_a[0];
	while (i < stack->la - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = tmp;
	if (t == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int t)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->lb < 2)
		return ;
	tmp = stack->stack_b[0];
	while (i < stack->lb - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp;
	if (t == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack, int t)
{
	ra(stack, 0);
	rb(stack, 0);
	if (t == 1)
		write(1, "rr\n", 3);
}
