/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 05:18:29 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/06 10:39:08 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_in_stack(t_list *stack)
{
	int	min;
	int	first;

	first = 1;
	while (stack)
	{
		if (*((int *) stack->content) < min || first)
		{
			min = *((int *) stack->content);
			first = 0;
		}
		stack = stack->next;
	}
	return (min);
}

int	get_max_in_stack(t_list *stack)
{
	int	max;
	int	first;

	first = 1;
	while (stack)
	{
		if (*((int *) stack->content) > max || first)
		{
			max = *((int *) stack->content);
			first = 0;
		}
		stack = stack->next;
	}
	return (max);
}

int	get_max_num_index(t_list *stack)
{
	int	max;
	int	max_index;
	int	index;

	index = 0;
	max_index = -1;
	while (stack)
	{
		if (*((int *) stack->content) > max || max_index == -1)
		{
			max = *((int *) stack->content);
			max_index = index;
		}
		index++;
		stack = stack->next;
	}
	return (max_index);
}

int	get_min_num_index(t_list *stack)
{
	int	min;
	int	min_index;
	int	index;

	index = 0;
	min_index = -1;
	while (stack)
	{
		if (*((int *) stack->content) < min || min_index == -1)
		{
			min = *((int *) stack->content);
			min_index = index;
		}
		index++;
		stack = stack->next;
	}
	return (min_index);
}
