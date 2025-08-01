/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:40:38 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/08/01 18:55:49 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	firts;
	int	second;
	int	third;

	firts = a->top->value;
	second = a->top->next->value;
	third = a->bottom->value;
	if (firts > second && second < third && firts < third)
		sa(a);
	else if (firts > second && second > third && firts > third)
	{
		sa(a);
		rra(a);
	}
	else if (firts > second && second < third && firts > third)
		ra(a);
	else if (firts < second && second > third && firts < third)
	{
		sa(a);
		ra(a);
	}
	else if (firts < second && second > third && firts > third)
		rra(a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
}
