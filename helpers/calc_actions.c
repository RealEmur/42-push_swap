/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:51:22 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/10 00:53:40 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_stack_actions(t_action *act, int s_index, int s_size, char stack)
{
	if (stack == 'a')
	{
		if (s_index <= s_size / 2)
			act->ra = s_index;
		else
			act->rra = s_size - s_index;
	}
	else if (stack == 'b')
	{
		if (s_index <= s_size / 2)
			act->rb = s_index;
		else
			act->rrb = s_size - s_index;
	}
}

void	set_rrs(t_action *act)
{
	if (act->ra && act->rb)
	{
		act->rr = min(act->ra, act->rb);
		act->ra -= act->rr;
		act->rb -= act->rr;
	}
	else if (act->rra && act->rrb)
	{
		act->rrr = min(act->rra, act->rrb);
		act->rra -= act->rrr;
		act->rrb -= act->rrr;
	}
}

void	set_cost(t_action *act)
{
	act->cost += act->ra + act->rb + act->rr \
	+ act->rra + act->rrb + act->rrr;
	if (act->rrr)
		act->cost += 2;
	else if (act->rra || act->rrb)
		act->cost++;
}
