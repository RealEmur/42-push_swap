/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:05:43 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/14 09:24:24 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_len(t_list *stack)
{
	int	len;

	len = 0;
	while (stack && ++len)
		stack = stack->next;
	return (len);
}

int	is_stack_sorted(t_list *stack, char *type)
{
	while (stack && stack->next)
	{
		if (ft_strncmp("asc", type, 3) == 0 && \
		*((int *) stack->content) > *((int *) stack->next->content))
			return (0);
		else if (ft_strncmp("desc", type, 4) == 0 && \
		*((int *) stack->content) < *((int *) stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}
