/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:47:13 by ftroise           #+#    #+#             */
/*   Updated: 2024/01/21 17:27:36 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	la;
	int	lb;
}		t_stack;

void	pa(t_stack *stk, int choice);
void	pb(t_stack *stk, int choice);
void	sa(t_stack *stk, int choice);
void	sb(t_stack *stk, int choice);
void	ss(t_stack *stk, int choice);
void	ra(t_stack *stk, int choice);
void	rb(t_stack *stk, int choice);
void	rr(t_stack *stk, int choice);
void	rra(t_stack *stk, int choice);
void	rrb(t_stack *stk, int choice);
void	rrr(t_stack *stk, int choice);
void	ft_error(int *stack);
int		stack_len(char **av);
void	make_stack_int_e_ceck_dub_sort(char **av);
void	sort_3_a(t_stack *stk);
int		sort(t_stack *stk, int size);
int		sort_3_b(t_stack *stk, int len);
void	check_doub(int *stack, int size);
int		atoi_pushsap(char *str, int *stack);
int		ft_push(t_stack *stk, int len, int push);
int		quicksort_a(t_stack *stk, int len, int rot);
int		quicksort_b(t_stack *stk, int len, int rot);
char	*get_next_line(int fd);
int		check_sorted(int *stack, int size, int order);
void	temporary_sort(int *stk_tmp, int size);
int		mid_number(int *pivot, int *stk, int size);
void	quicksort_stacks(t_stack *stk, int len);
char	**sub_split(char **av, int size);
void	free_matrix(char **av);

#endif
