/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jon <jon@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 01:49:42 by jon               #+#    #+#             */
/*   Updated: 2025/08/06 00:48:30 by jon              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **a, t_node **b)
{
	int	len;

	(void)b;
	len = stack_length(*a);
	if (len == 2)
		sort_two(a);
	else if (len == 3)
		sort_three(a);
	(void)b;
}

void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	assign_target_positions(t_node *a, t_node *b)
{
	while (b)
	{
		b->target_pos = find_target_pos(a, b->value);
		b = b->next;
	}
}

static int	find_target_pos(t_node *a, int b_value)
{
	int		target_pos;
	t_node	*tmp;
	int		min_diff;
	int		diff;

	target_pos = -1;
	min_diff = INT_MAX;
	tmp = a;
	while (tmp)
	{
		diff = tmp->value - b_value;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target_pos = tmp->index;
		}
		tmp = tmp->next;
	}
	if (target_pos == -1)
	{
		tmp = a;
		target_pos = tmp->index;
		while (tmp)
		{
			if (tmp->value < a->value)
				target_pos = tmp->index;
			tmp = tmp->next;
		}
	}
	return (target_pos);
}

