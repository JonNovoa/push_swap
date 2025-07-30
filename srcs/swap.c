/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:52:25 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/07/30 19:05:11 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_stack_node	*firts;
	t_stack_node	*second;

	if (!stack || stack->size < 2)
		return ;
	firts = stack->top;
	second = firts->next;
	if (second->next)
		second->next->prev = firts;
	second->prev = NULL;
	second->next = firts;
	firts->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = firts;
}

void	sa(t_stack *a)
{
	swap(a);
	print_instruction("sa");
}

void	sb(t_stack *b)
{
	swap(b);
	print_instruction("sb");
}


void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	print_instruction("ss");
}
