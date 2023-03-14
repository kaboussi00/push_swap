/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:18:01 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/14 12:59:50 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot(t_list	**lst, int size)
{
	t_list	*tmp;
	int		index;
	int		j;
	int		v;

	tmp = *lst;
	j = 1;
	size = ft_lstsize(tmp);
	index = size / 2 + 1;
	while (j != index)
	{
		tmp = tmp->next;
		j++;
	}
	v = tmp->content;
	free_lst(*lst);
	return (v);
}

t_list	*ft_lstcopie(t_list	*lst, int size)
{
	t_list	*lstcopie;
	t_list	*tmp;
	int		ret;

	ret = 0;
	tmp = lst;
	lstcopie = NULL;
	if (!size)
		exit(0);
	while (tmp && ret < size)
	{
		ft_lstadd_back(&lstcopie, ft_lstnew(tmp->content));
		tmp = tmp->next;
		ret++;
	}
	return (lstcopie);
}

int	sort_lst(t_list *lst, int size)
{
	t_list	*i;
	t_list	*j;
	int		ret;
	t_list	*lstcp;

	lstcp = ft_lstcopie(lst, size);
	i = lstcp;
	while (i)
	{
		j = i->next;
		while (j)
		{
			ret = i->content - j->content;
			if (ret > 0)
				ft_swap(&i->content, &j->content);
			j = j->next;
		}
		i = i->next;
	}
	return (pivot(&lstcp, size));
}
