/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jon <jon@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 01:05:14 by jon               #+#    #+#             */
/*   Updated: 2025/08/05 01:44:02 by jon              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (! *s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - '0');
	return (num * sign);
}

int	is_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*stack;
	t_node	*node;
	long	n;
	long	i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			return (free_stack(&stack), NULL);
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX || is_duplicate(stack, n))
			return (free_stack(&stack), NULL);
		node = new_node((int)n);
		if (!node)
			return (free_stack(&stack), NULL);
		add_back(&stack, node);
		i++;
	}
	return (stack);
}

