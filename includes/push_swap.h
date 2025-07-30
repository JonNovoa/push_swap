/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:22:24 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/07/30 14:08:13 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	int				size;
}	t_stack;

/* Parsing */
int		validate_args(int argc, char **argv);
long	ft_atol(char *str);
int		is_numeric(char *str);
int		has_duplicates(int *arr, int size);
int		parse_input(int argc, char **argv, t_stack *a);

/* Stack operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Utils */
void	free_stack(t_stack *stack);
void	exit_error(t_stack *a, t_stack *b);
void	print_instruction(char *instr);

/* Sorting */
void	sort_small(t_stack *a, t_stack *b);
void	push_swap(t_stack *a, t_stack *b);

#endif