/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:05:58 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/15 13:49:21 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opt	*lstnewstr(char *str)
{
	t_opt	*k;

	k = malloc(sizeof(t_opt));
	if (!k)
		return (NULL);
	k->str = p(str);
	k->next = NULL;
	return (k);
}

t_opt	*ft_last(t_opt *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_addback(t_opt **lst, t_opt *new)
{
	t_opt	*last;
	t_opt	*tmp;

	if (*lst)
	{
		tmp = *lst;
		last = ft_last(tmp);
		last->next = new;
	}
	else
		*lst = new;
}
