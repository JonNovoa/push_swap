/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jon <jon@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 01:06:15 by jon               #+#    #+#             */
/*   Updated: 2025/08/06 01:26:44 by jon              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_target_position(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target;

	current_b = b;
	while (current_b)
	{
		target = find_target_position(a, current_b->index);
		current_b->target_pos = get_position(a, target);
		current_b = current_b->next;
	}
}

static t_node	*find_target_position(t_node *a, int index_b)
{
	t_node	*target;

	target = get_closest_lower_index(a, index_b);
	if (target)
		return (target);
	target = a;
	while (target)
	{
		if (target->index == get_min_index(a))
			return (target);
		target = target->next;
	}
	return (NULL);
}

static	t_node	*get_closest_lower_index(t_node *a, int index_b)
{
	t_node	*closest;
	t_node	*current;

	closest = NULL;
	current = a;
	while (current)
	{
		if (current->index < index_b)
		{
			if (!closest || current->index > closest->index)
				closest = current;
		}
		current = current->next;
	}
	return (closest);
}