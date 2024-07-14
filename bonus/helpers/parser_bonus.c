/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:41:46 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/10 20:36:28 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	is_valid_part(t_list **lst, char *str)
{
	t_list	*list;
	char	*num_str;
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	i = ft_atoi(str);
	num_str = ft_itoa(i);
	if (!num_str || ft_strncmp(str, num_str, ft_strlen(str)))
		return (free(num_str), 0);
	free(num_str);
	list = *lst;
	while (list)
	{
		if (ft_atoi(list->content) == i)
			return (0);
		list = list->next;
	}
	return (1);
}

int	add_parts_to_list(t_list **lst, char **args)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!is_valid_part(lst, args[i]))
			return (0);
		tmp = ft_lstnew((void *) args[i]);
		if (!tmp)
			return (0);
		ft_lstadd_back(lst, tmp);
		args[i++] = 0;
	}
	return (i);
}

t_list	*parse_args(char **args, int size)
{
	t_list	*char_lst;
	char	**splitted;
	int		i;

	char_lst = 0;
	i = 1;
	while (i < size)
	{
		splitted = ft_split(args[i], ' ');
		if (!splitted || !add_parts_to_list(&char_lst, splitted))
		{
			i = 0;
			ft_lstclear(&char_lst, free);
			while (splitted[i])
				free(splitted[i++]);
			free(splitted);
			return (0);
		}
		i++;
		free(splitted);
	}
	return (char_lst);
}
