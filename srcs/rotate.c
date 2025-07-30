/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:53:01 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/07/30 19:17:13 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_stack_node	*node;

	if (!stack || stack->size < 2)
		return ;
	node = stack->top;
	stack->top = node->next;
	stack->top->prev = NULL;
	node->prev = NULL;
	node->prev = stack->bottom;
	stack->bottom->next = node;
	stack->bottom = node;
}

void	ra(t_stack *a)
{
	rotate(a);
	print_instruction("ra");
}

void	rb(t_stack *b)
{
	rotate(b);
	print_instruction("rb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	print_instruction("rr");
}