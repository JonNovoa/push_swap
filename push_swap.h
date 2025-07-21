/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:34:04 by jon               #+#    #+#             */
/*   Updated: 2025/07/21 18:35:56 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);
long	ft_atol(const char *str);
int		is_numeric(char *s);
t_node	*parse_args(int argc, char **argv);
void	free_stack(t_node **stack);
void	exit_error(void);
#endif