/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils12.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:02:34 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/14 20:10:58 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorttwo_b(t_list	*lst)
{
	int	n;

	n = ft_lstsize(lst);
	if (n == 2)
	{
		if (lst->next->content > lst->content)
			sb(&lst);
	}
	return (0);
}

int	sorttrois_b(t_list **lst)
{
	t_var	tmp;

	tmp.tmp1 = (*lst)->content;
	tmp.tmp2 = (*lst)->next->content;
	tmp.tmp3 = (*lst)->next->next->content;
	if (tmp.tmp1 > tmp.tmp2 && tmp.tmp1 > tmp.tmp3)
	{
		if (tmp.tmp3 > tmp.tmp2)
		{
			sb(lst);
			rb(lst);
		}
	}
	else if (tmp.tmp3 > tmp.tmp2 && tmp.tmp3 > tmp.tmp1)
	{
		if (tmp.tmp2 > tmp.tmp1)
			sb(lst);
		rrb(lst);
	}
	else if (tmp.tmp2 > tmp.tmp1 && tmp.tmp2 > tmp.tmp3)
	{
		if (tmp.tmp1 > tmp.tmp3)
			sb(lst);
		else if (tmp.tmp3 > tmp.tmp1)
			rb(lst);
	}
	return(0);
}

int	sorttroistop(t_list **b)
{
	t_var	tmp;

	tmp.tmp1 = (*b)->content;
	tmp.tmp2 = (*b)->next->content;
	tmp.tmp3 = (*b)->next->next->content;
	if (tmp.tmp3 < tmp.tmp1 && tmp.tmp3 < tmp.tmp2)
	{
		if (tmp.tmp1 < tmp.tmp2)
			sb(b);
	}
	else if (tmp.tmp1 < tmp.tmp2 && tmp.tmp1 < tmp.tmp3)
	{
		sb(b);
		rb(b);
		sb(b);
		rrb(b);
		if (tmp.tmp2 < tmp.tmp3)
			sb(b);
	}
	else if (tmp.tmp2 < tmp.tmp1 && tmp.tmp2 < tmp.tmp3)
	{
		rb(b);
		sb(b);
		rrb(b);
		if (tmp.tmp1 < tmp.tmp3)
			sb(b);
	}
	return (0);
}