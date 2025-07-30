/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:47:05 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/07/30 17:43:19 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static t_stack_node	*new_node(int value)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	stack_fill_from_array(int *arr, int count, t_stack *a)
{
	int				i;
	t_stack_node	*node;
	t_stack_node	*last;

	i = 0;
	last = NULL;
	while (i < count)
	{
		node = new_node(arr[i]);
		if (!node)
			return (0);
		if (!a->top)
			a->top = node;
		else
		{
			last->next = node;
			node->prev = last;
		}
		last = node;
		i++;
	}
	a->bottom = last;
	a->size = count;
	return (1);
}

int	fill_tmp_array(int argc, char **argv, int *tmp)
{
	int		i;
	long	num;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		tmp[count++] = (int)num;
	}
	return (count);
}

int	parse_input(int argc, char **argv, t_stack *a)
{
	int	*tmp;
	int	count;

	tmp = (int *)malloc(sizeof(int) * (argc - 1));
	if (!tmp)
		return (0);
	count = fill_tmp_array(argc, argv, tmp);
	if (!count)
		return (free(tmp), 0);
	if (has_duplicates(tmp, count))
		return (free(tmp), 0);
	if (!stack_fill_from_array(tmp, count, a))
		return (free(tmp), 0);
	free(tmp);
	return (1);
}
