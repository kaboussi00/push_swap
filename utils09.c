/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils09.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:18:01 by kaboussi          #+#    #+#             */
/*   Updated: 2023/01/30 19:58:59 by kaboussi         ###   ########.fr       */
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

int	sort_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*i;
	t_list	*j;
	int		ret;

	tmp = *lst;
	i = tmp;
	j = tmp->next;
	while (i)
	{
		j = i->next;
		while (j)
		{
			ret = i->content - j->content;
			if (ret > 0)
				ft_swap(&i->content, &j->content);
			else if (ret == 0)
				printerror();
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	pivot(t_list	**lst, int size)
{
	t_list	*tmp;
	int		ret;
	int		i;
	int		pivot;

	tmp = *lst;
	sort_lst(tmp);
	size = ft_lstsize(tmp);
	while (tmp)
	{
		i = size / 2 ;
		if (size % 2 == 0)
			pivot = i;
		else
			pivot = i + 1;
		tmp = tmp->next;
		return (pivot);
	}
	return (0);
}