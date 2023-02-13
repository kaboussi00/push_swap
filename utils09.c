/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils09.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:18:01 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/13 12:16:17 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	pivot(t_list	**lst, int size)
{
	t_list	*tmp;
	int		index;
	int		i;
	int		j;

	tmp = *lst;
	j = 1;
	size = ft_lstsize(tmp);
	i = size / 2 ;
	if (size % 2 == 0)
		index = i;
	else
		index = i + 1;
	while (j != index)
	{
		tmp = tmp->next;
		j++;
	}
	return (tmp->content);
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
	t_list	*tmp;
	t_list	*i;
	t_list	*j;
	int		ret;
	t_list	*lstcp;

	lstcp = ft_lstcopie(lst, size);
	tmp = lstcp;
	i = tmp;
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
