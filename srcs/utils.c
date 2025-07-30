/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:59:08 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/07/30 14:12:18 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	exit_error(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	print_instruccion(char *instr)
{
	while (instr)
		write(1, instr++, 1);
	write(1, "\n", 1);
}
