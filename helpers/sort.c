/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:45:51 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/10 01:33:39 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **stack)
{
	t_list	*temp;
	int		max;
	int		min;

	min = *((int *)(*stack)->content);
	max = *((int *)(*stack)->content);
	temp = (*stack)->next;
	while (temp)
	{
		if (*((int *) temp->content) > max)
			max = *((int *) temp->content);
		if (*((int *) temp->content) < min)
			min = *((int *) temp->content);
		temp = temp->next;
	}
	if (*((int *)(*stack)->content) == max)
		do_action(stack, 0, "ra", 1);
	else if (*((int *) ft_lstlast((*stack))->content) == min)
		do_action(stack, 0, "rra", 1);
	if (!is_stack_sorted(*stack, "asc"))
		do_action(stack, 0, "sa", 1);
	if (!is_stack_sorted(*stack, "asc"))
		do_action(stack, 0, "ra", 1);
}

void	do_set_of_actions(t_action act, t_list **stack_a, \
t_list **stack_b, char *push)
{
	while (act.rr--)
		do_action(stack_a, stack_b, "rr", 1);
	while (act.ra--)
		do_action(stack_a, stack_b, "ra", 1);
	while (act.rb--)
		do_action(stack_a, stack_b, "rb", 1);
	while (act.rrr--)
		do_action(stack_a, stack_b, "rrr", 1);
	while (act.rra--)
		do_action(stack_a, stack_b, "rra", 1);
	while (act.rrb--)
		do_action(stack_a, stack_b, "rrb", 1);
	do_action(stack_a, stack_b, push, 1);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	index;

	while (stack_len(*stack_a) > 3)
		do_set_of_actions(get_cheapest_action(*stack_a, *stack_b), \
		stack_a, stack_b, "pb");
	if (!is_stack_sorted(*stack_a, "asc"))
		sort_three(stack_a);
	while (!is_stack_sorted(*stack_b, "desc"))
		do_action(0, stack_b, "rrb", 1);
	while (*stack_b)
	{
		index = get_target_index(*((int *)(*stack_b)->content), \
			*stack_a, TARGET_BIGGER_LOWEST);
		while (index != 0)
		{
			do_action(stack_a, 0, "rra", 1);
			index = get_target_index(*((int *)(*stack_b)->content), \
			*stack_a, TARGET_BIGGER_LOWEST);
		}
		do_set_of_actions(get_action(stack_len(*stack_a), 0, \
		0, 0), stack_a, stack_b, "pa");
	}
	while (!is_stack_sorted(*stack_a, "asc"))
		do_action(stack_a, 0, "rra", 1);
}