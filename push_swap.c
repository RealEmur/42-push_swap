/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:33:32 by emyildir          #+#    #+#             */
/*   Updated: 2024/05/07 05:49:27 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_list **stack, t_list *nums)
{
	t_list	*temp;
	int		*i;
	
	*stack = 0;
	while (nums)
	{
		i = (int *) malloc(sizeof(t_list));
		if(!i)
		{
			return (0);
		}
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

int		main(int size, char **args)
{
	t_list	*stack_a;
	t_list	*char_lst;

	if (size == 1)
		return (0);
	stack_a = 0;
	char_lst = parse_args(args, size);
	if(char_lst == 0)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	if(!init_stack(&stack_a, char_lst))
	{
		ft_lstclear(&stack_a, del_list);
		ft_lstclear(&char_lst, del_list);
	}
	while(stack_a)
	{
		printf("%d ", *(int *) (stack_a->content));
		stack_a = stack_a->next;
	}
	printf("\n");
	return (0);
}