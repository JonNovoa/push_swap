/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:39:20 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/08/01 18:54:09 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  Busca el nodo con el valor mínimo en el
 stack a y devuelve su índice (0-based)*/
static int	finde_min_index(t_stack *a)
{
	t_stack_node	*tmp;
	int				min_value;
	int				min_index;
	int				i;

	tmp = a->top;
	min_value = tmp->value;
	min_index = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min_value)
		{
			min_value = tmp->value;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}

/* Rota el stack a para colocar el nodo mínimo en la cima */
static void	rotate_to_top(t_stack *a, int index)
{
	if (index <= a->size / 2)
	{
		while (index-- > 0)
			ra(a);
	}
	else
	{
		index = a->size - index;
		while (index-- > 0)
			rra(a);
	}
}

/* Ordena 4 o 5 elementos */
void	sort_five(t_stack *a, t_stack *b)
{
	int	num_to_push;
	int	min_idx;

	num_to_push = a->size - 3;
	while (num_to_push > 0)
	{
		min_idx = finde_min_index(a);
		rotate_to_top(a, min_idx);
		pb(a, b);
		num_to_push--;
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}