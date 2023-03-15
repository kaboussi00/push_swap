/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:48 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/15 14:22:11 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = lst;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
		tmp2 = NULL;
	}
}

void	free_opt(t_opt *lst)
{
	t_opt	*tmp1;
	t_opt	*tmp2;

	tmp1 = lst;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2->str);
		tmp2->str = NULL;
		free(tmp2);
		tmp2 = NULL;
	}
}

void	ft_freee(t_list **a, t_list **b, t_opt **optlst, t_var v)
{
	free_lst(*a);
	free_lst(*b);
	free_opt(*optlst);
	free(v.join);
	ft_free(v.split);
}

int	check_sort(t_list *a)
{
	t_list	*tmp;
	t_list	*i;
	t_list	*j;

	tmp = a;
	i = tmp;
	j = tmp->next;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content - j->content > 0)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
