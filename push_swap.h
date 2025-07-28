/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:34:04 by jon               #+#    #+#             */
/*   Updated: 2025/07/28 18:42:19 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);
long	ft_atol(const char *str);
int		is_numeric(char *s);
t_node	*parse_args(int argc, char **argv);
void	free_stack(t_node **stack);
void	exit_error(void);
int		is_numeric(char *s);
t_node	*new_node(int value);
/* static int	is_duplicate(t_node *stack, int value);*/
t_node	*parse_args(int argc, char **argv);

/* swap.c */
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

/* push.c */
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

/* rotate.c */
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

/* reverse.c */
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif