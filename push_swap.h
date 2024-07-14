/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:29:58 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/10 01:39:39 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TARGET_LOWER_BIGGEST 1
# define TARGET_BIGGER_LOWEST 2

# include "lib/libft/libft.h"

typedef struct s_action
{
	int	cost;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_action;

int			stack_len(t_list *stack);
int			min(int num1, int num2);
int			get_min_in_stack(t_list *stack);
int			get_max_in_stack(t_list *stack);
int			get_max_num_index(t_list *stack);
int			get_min_num_index(t_list *stack);
int			is_stack_sorted(t_list *stack, char *type);
int			get_target_index(int num, t_list *stack, int target);
void		sort(t_list **stack_a, t_list **stack_b);
void		do_action(t_list **stack_a, t_list **stack_b, char *move, \
int print);
void		set_stack_actions(t_action *act, int s_index, \
int s_size, char stack);
void		set_rrs(t_action *act);
void		set_cost(t_action *act);
t_list		*parse_args(char **args, int size);
t_action	get_cheapest_action(t_list	*stack_a, t_list *stack_b);
t_action	get_action(int sa_len, int sa_index, int sb_len, int sb_index);

#endif
