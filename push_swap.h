/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:29:58 by emyildir          #+#    #+#             */
/*   Updated: 2024/05/07 05:49:10 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
#include <stdio.h>

typedef struct s_stack {
	int		*nums;	
}	t_stack;

t_list	*parse_args(char **args, int size);
void	del_list(void *content);

