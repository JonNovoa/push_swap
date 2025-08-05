/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jon <jon@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:07:16 by jon               #+#    #+#             */
/*   Updated: 2025/08/06 01:15:25 by jon              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

typedef struct s_cost
{
	int		a_rotations;
	int		b_rotations;
	int		total;
	t_node	*node;
}	t_cost;


/* Stack functions*/
t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);
int		stack_length(t_node *stack);

/* Input parsing */
t_node	*parse_args(int argc, char **argv);
int		is_numeric(char *str);
long	ft_atol(const char *str);
int		is_duplicate(t_node *stack, int value);

/* Operations*/
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* Sort */
void	sort_stack(t_node **a, t_node **b);
void	sort_two(t_node **a);
void	sort_three(t_node **a);

/* Target */
void	assign_target_positions(t_node *a, t_node *b);



/* Checker */
int		is_sorted(t_node *stack);

#endif