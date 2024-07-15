/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:24:33 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/15 02:42:23 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack)
{
	t_list	*temp;

	if (!stack || !*stack)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	push(t_list **from, t_list **to)
{
	t_list	*temp;

	if (!from || !*from)
		return ;
	temp = (*from)->next;
	if (!*to)
	{
		*to = *from;
		(*to)->next = 0;
	}
	else
		ft_lstadd_front(to, *from);
	*from = temp;
}

void	rotate(t_list **stack)
{
	t_list	*temp;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	ft_lstadd_back(stack, temp);
	*stack = (*stack)->next;
	temp->next = 0;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*temp;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	last = ft_lstlast(*stack);
	while (temp->next != last)
		temp = temp->next;
	ft_lstadd_front(stack, last);
	temp->next = 0;
}

void	do_action(t_list **stack_a, t_list **stack_b, char *move)
{
	if (ft_strncmp(move, "sa", 3) == 0 || ft_strncmp(move, "ss", 3) == 0)
		swap(stack_a);
	if (ft_strncmp(move, "sb", 3) == 0 || ft_strncmp(move, "ss", 3) == 0)
		swap(stack_b);
	if (ft_strncmp(move, "pa", 3) == 0)
		push(stack_b, stack_a);
	if (ft_strncmp(move, "pb", 3) == 0)
		push(stack_a, stack_b);
	if (ft_strncmp(move, "ra", 3) == 0 || ft_strncmp(move, "rr", 3) == 0)
		rotate(stack_a);
	if (ft_strncmp(move, "rb", 3) == 0 || ft_strncmp(move, "rr", 3) == 0)
		rotate(stack_b);
	if (ft_strncmp(move, "rra", 4) == 0 || ft_strncmp(move, "rrr", 4) == 0)
		reverse_rotate(stack_a);
	if (ft_strncmp(move, "rrb", 4) == 0 || ft_strncmp(move, "rrr", 4) == 0)
		reverse_rotate(stack_b);
	ft_printf("%s\n", move);
}
