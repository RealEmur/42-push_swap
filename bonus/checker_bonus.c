/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 00:08:00 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/10 18:38:54 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

int	exit_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(0);
}

int	is_operation(char	*str)
{
	return (\
		ft_strncmp(str, "sa\n", 4) == 0 || \
		ft_strncmp(str, "sb\n", 4) == 0 || \
		ft_strncmp(str, "ss\n", 4) == 0 || \
		ft_strncmp(str, "pa\n", 4) == 0 || \
		ft_strncmp(str, "pb\n", 4) == 0 || \
		ft_strncmp(str, "ra\n", 4) == 0 || \
		ft_strncmp(str, "rb\n", 4) == 0 || \
		ft_strncmp(str, "rr\n", 4) == 0 || \
		ft_strncmp(str, "rra\n", 5) == 0 || \
		ft_strncmp(str, "rrb\n", 5) == 0 || \
		ft_strncmp(str, "rrr\n", 5) == 0 \
	);
}

int	do_operations(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = 0;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		else if (!is_operation(line))
		{
			free(line);
			return (0);
		}
		line[ft_strlen(line) - 1] = '\0';
		do_action(stack_a, stack_b, line, 0);
		free(line);
	}
	return (1);
}

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
	int		res;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*char_lst;

	if (size == 1)
		return (0);
	stack_a = 0;
	stack_b = 0;
	char_lst = parse_args(args, size);
	if (char_lst == 0)
		exit_error();
	if (!init_stack_a(&stack_a, char_lst))
		ft_lstclear(&stack_a, free);
	ft_lstclear(&char_lst, free);
	res = do_operations(&stack_a, &stack_b);
	if (res && is_stack_sorted(stack_a, "asc") && !stack_b)
		ft_printf("OK\n");
	else if (res)
		ft_printf("KO\n");
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	if (!res)
		exit_error();
	return (0);
}
