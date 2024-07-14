/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 00:14:24 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/10 20:39:04 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../lib/libft/libft.h"

int		is_stack_sorted(t_list *stack, char *type);
void	do_action(t_list **stack_a, t_list **stack_b, char *move, int print);
t_list	*parse_args(char **args, int size);

#endif