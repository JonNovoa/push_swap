/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:53:16 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/07/30 19:20:59 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_stack_node	*node;

	if (!stack || stack->size < 2)
		return ;
	node = stack->bottom;
	stack->bottom = node->prev;
	stack->bottom->next = NULL;
	node->next = stack->top;
	stack->top->prev = node;
	stack->top = node;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	print_instruction("rra");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	print_instruction("rrb");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	print_instruction("rrr");
}

