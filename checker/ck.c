/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:39:31 by ftroise           #+#    #+#             */
/*   Updated: 2024/01/21 18:04:27 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ck_error(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	write(2, "ERROR\n", 6);
	exit(1);
}

void	read_moves(t_stack *stack, char *moves)
{
	if (ft_strncmp(moves, "pa\n", 3) == 0)
		pa(stack, 0);
	else if (ft_strncmp(moves, "pb\n", 3) == 0)
		pb(stack, 0);
	else if (ft_strncmp(moves, "sa\n", 3) == 0)
		sa(stack, 0);
	else if (ft_strncmp(moves, "sb\n", 3) == 0)
		sb(stack, 0);
	else if (ft_strncmp(moves, "ss\n", 3) == 0)
		ss(stack, 0);
	else if (ft_strncmp(moves, "ra\n", 3) == 0)
		ra(stack, 0);
	else if (ft_strncmp(moves, "rb\n", 3) == 0)
		rb(stack, 0);
	else if (ft_strncmp(moves, "rr\n", 3) == 0)
		rr(stack, 0);
	else if (ft_strncmp(moves, "rra\n", 4) == 0)
		rra(stack, 0);
	else if (ft_strncmp(moves, "rrb\n", 4) == 0)
		rrb(stack, 0);
	else if (ft_strncmp(moves, "rrr\n", 4) == 0)
		rrr(stack, 0);
	else
		ck_error(stack);
}

static void	make_stack_int_e_ceck_dub(char **av, t_stack *stack)
{
	int		size;
	int		i;

	i = -1;
	size = stack_len(av);
	stack->stack_a = malloc(size * sizeof(int));
	if (!stack->stack_a)
		return ;
	stack->la = size;
	stack->stack_b = malloc(size * sizeof(int));
	if (!stack->stack_b)
	{
		free(stack->stack_a);
		return ;
	}
	stack->lb = 0;
	while (++i < size)
		stack->stack_a[i] = atoi_pushsap(av[i], stack->stack_a);
	check_doub(stack->stack_a, size);
}

void	check_moves(t_stack *stack)
{
	char		*move;

	move = get_next_line(0);
	while (move)
	{
		read_moves(stack, move);
		free(move);
		move = get_next_line(0);
	}
	if (check_sorted(stack->stack_a, stack->la, 0) && stack->lb == 0)
		write(1, "OK\n", 3);
	else
		write(1, "K.0\n", 4);
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->stack_b)
		free(stack->stack_b);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	char	**tab;

	tab = NULL;
	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			av = ft_split (*av, ' ' );
			make_stack_int_e_ceck_dub(av, &stack);
		}
		else if (ac > 1 && ac != 2)
		{
			tab = sub_split(av, ac);
			make_stack_int_e_ceck_dub(tab, &stack);
		}
		check_moves(&stack);
	}
	if (ac == 2)
		free_matrix(av);
	free_matrix(tab);
	return (0);
}
