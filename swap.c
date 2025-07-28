/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:36:30 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/07/22 14:44:54 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	second->next = first;
	*a = second;
	write (1, "sa\n", 3);
}

void	sb(t_node **b)
{
	t_node	*firts;
	t_node	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	firts = *b;
	second = (*b)->next;
	firts->next = second->next;
	second->next = firts;
	*b = second;
	write (1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	write (1, "ss\n", 3);
}
