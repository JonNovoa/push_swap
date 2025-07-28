/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:41:08 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/07/28 18:31:50 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack -> value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*stack;
	long	num;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			exit_error();
		num = ft_atol(argv[i]);
		if (num < -2147483648 || num > 2147483647)
			exit_error();
		if (is_duplicate(stack, (int)num))
			exit_error();
		add_back(&stack, new_node((int) num));
		i++;
	}
	return (stack);
}
