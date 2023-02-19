/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:36:21 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/19 16:05:14 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorttwo(t_list	*lst)
{
	int	n;

	n = ft_lstsize(lst);
	if (n == 2)
	{
		if (lst->next->content < lst->content)
			sa(&lst);
	}
	return (0);
}

int	sorttrois(t_list **lst)
{
	int		tmp;
	int		tmp2;
	int		tmp3;

	tmp = (*lst)->content;
	tmp2 = (*lst)->next->content;
	tmp3 = (*lst)->next->next->content;
	if (tmp3 > tmp && tmp3 > tmp2)
	{
		if (tmp > tmp2)
			sa(lst);
	}
	else if (tmp2 > tmp3 && tmp2 > tmp)
	{
		rra(lst);
		if (tmp < tmp3)
			sa(lst);
	}
	else if (tmp > tmp2 && tmp > tmp3)
	{
		ra(lst);
		if (tmp2 > tmp3)
			sa(lst);
	}
	return (0);
}

int	sorttroistop(t_list **a)
{
	t_var	tmp;

	tmp.tmp1 = (*a)->content;
	tmp.tmp2 = (*a)->next->content;
	tmp.tmp3 = (*a)->next->next->content;
	if (tmp.tmp3 > tmp.tmp1 && tmp.tmp3 > tmp.tmp2)
	{
		if (tmp.tmp1 > tmp.tmp2)
			sa(a);
	}
	else if (tmp.tmp1 > tmp.tmp2 && tmp.tmp1 > tmp.tmp3)
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
		if (tmp.tmp2 > tmp.tmp3)
			sa(a);
	}
	else if (tmp.tmp2 > tmp.tmp1 && tmp.tmp2 > tmp.tmp3)
	{
		ra(a);
		sa(a);
		rra(a);
		if (tmp.tmp1 > tmp.tmp3)
			sa(a);
	}
	// utilsorttroistop(a, tmp);
	return (0);
}

int	utilsorttroistop(t_list **a, t_var	tmp)
{
	if (tmp.tmp2 > tmp.tmp1 && tmp.tmp2 > tmp.tmp3)
	{
		ra(a);
		sa(a);
		rra(a);
		if (tmp.tmp1 > tmp.tmp3)
			sa(a);
	}
	return (0);
}
