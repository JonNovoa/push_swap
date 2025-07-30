/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:12:39 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/07/30 14:23:30 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.top = NULL;
	a.bottom = NULL;
	a.size = 0;
	b.top = NULL;
	b.bottom = NULL;
	b.size = 0;

	if (argc == 1)
		return (0);
	if (!validate_args(argc, argv))
		exit_error(NULL, NULL);
	if (!parse_input(argc, argv, &a))
		exit_error(&a, NULL);

	push_swap(&a, &b);

	free_stack(&a);
	free_stack(&b);

	return (0);
}
