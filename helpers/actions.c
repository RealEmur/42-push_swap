/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:12:25 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/06 13:13:50 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_min_target_index(t_list *stack, int target)
{
	if (target == TARGET_LOWER_BIGGEST)
		return (get_max_num_index(stack));
	return (get_min_num_index(stack));
}

int	get_target_index(int num, t_list *stack, int target)
{
	int	index;
	int	t_indx;
	int	t_num;

	if (!stack)
		return (0);
	else if ((num < get_min_in_stack(stack) || num > get_max_in_stack(stack)))
		return (get_max_min_target_index(stack, target));
	t_indx = -1;
	index = 0;
	while (stack)
	{
		if ((target == TARGET_LOWER_BIGGEST && (*((int *) stack->content) < num \
		&& (t_indx == -1 || *((int *) stack->content) > t_num))) || \
		(target == TARGET_BIGGER_LOWEST && (*((int *) stack->content) > num && \
		(t_indx == -1 || *((int *) stack->content) < t_num))))
		{
			t_num = *((int *) stack->content);
			t_indx = index;
		}
		index++;
		stack = stack->next;
	}
	return (t_indx);
}

t_action	get_action(int sa_len, int sa_index, int sb_len, int sb_index)
{
	t_action	act;

	act.ra = 0;
	act.rb = 0;
	act.rr = 0;
	act.rra = 0;
	act.rrb = 0;
	act.rrr = 0;
	act.cost = 0;
	set_stack_actions(&act, sa_index, sa_len, 'a');
	set_stack_actions(&act, sb_index, sb_len, 'b');
	set_rrs(&act);
	set_cost(&act);
	return (act);
}

t_action	get_cheapest_action(t_list	*stack_a, t_list *stack_b)
{
	int			index_a;
	int			sa_len;
	int			sb_len;
	t_action	cheapest_action;
	t_action	temp_action;

	sa_len = stack_len(stack_a);
	sb_len = stack_len(stack_b);
	index_a = 0;
	cheapest_action.cost = -1;
	while (stack_a)
	{
		temp_action = get_action(sa_len, index_a, sb_len, \
		get_target_index(*((int *) stack_a->content), stack_b, \
		TARGET_LOWER_BIGGEST));
		if (temp_action.cost < cheapest_action.cost || \
		cheapest_action.cost == -1)
			cheapest_action = temp_action;
		index_a++;
		stack_a = stack_a->next;
	}
	return (cheapest_action);
}
