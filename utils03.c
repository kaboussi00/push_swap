/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:01:53 by kaboussi          #+#    #+#             */
/*   Updated: 2023/01/16 15:51:35 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	t_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		last = ft_lstlast(tmp);
		last->next = new;
	}
	else
		*lst = new;
}

void	ft_putstr(char *s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		free(lst);
	}
}
