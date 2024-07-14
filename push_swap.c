/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:33:32 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/14 02:55:19 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(t_list **stack, t_list *nums)
{
	t_list	*temp;
	int		*i;

	*stack = 0;
	while (nums)
	{
		i = (int *) malloc(sizeof(int));
		if (!i)
			return (0);
		*i = ft_atoi(nums->content);
		temp = ft_lstnew((void *) i);
		if (!temp)
		{
			free(i);
			return (0);
		}
		ft_lstadd_back(stack, temp);
		nums = nums->next;
	}
	return (1);
}

int	main(int size, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*char_lst;

	if (size == 1)
		return (0);
	stack_a = 0;
	stack_b = 0;
	char_lst = parse_args(args, size);
	if (char_lst == 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(0);
	}
	if (!init_stack_a(&stack_a, char_lst))
		ft_lstclear(&stack_a, free);
	ft_lstclear(&char_lst, free);
	if (!is_stack_sorted(stack_a, "asc"))
		sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
