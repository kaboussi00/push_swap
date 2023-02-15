/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils11.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:44:12 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/14 20:25:57 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
	return (0);
}

int	sorttroistop_b(t_list **b)
{
	t_var	tmp;

	tmp.tmp1 = (*b)->content;
	tmp.tmp2 = (*b)->next->content;
	tmp.tmp3 = (*b)->next->next->content;
	if (tmp.tmp3 > tmp.tmp1 && tmp.tmp3 < tmp.tmp2)
	{
		if (tmp.tmp2 > tmp.tmp1)
			sb(b);
		rb(b);
		sb(b);
		rrb(b);
		sb(b);
	}
	else if (tmp.tmp1 > tmp.tmp2 && tmp.tmp1 > tmp.tmp3)
	{
		if (tmp.tmp3 > tmp.tmp2)
		{
			rb(b);
			sb(b);
			rrb(b);
		}
	}
	else if (tmp.tmp2 > tmp.tmp1 && tmp.tmp2 > tmp.tmp3)
	{
		sb(b);
		if (tmp.tmp3 > tmp.tmp1)
		{
			rb(b);
			sb(b);
			rrb(b);
		}
	}
	return (0);
}

int	ft_sortbwithpivot(t_list **a, t_list **b, size_t len_b)
{
	t_list	*tmpb;
	t_var	tmp;
	size_t	i;

	tmp.ret_pa = 0;
	tmp.ret_rb = 0;
	i = -1;
	tmpb = (*b);
	tmp.pivot = sort_lst(*b, len_b);
	while (tmpb && ++i < len_b)
	{
		if ((tmpb)->content >= tmp.pivot)
		{
			pa(b, a);
			tmp.ret_pa += 1;
		}
		else if ((tmpb)->content < tmp.pivot)
		{
			rb(b);
			tmp.ret_rb += 1;
		}
		tmpb = tmpb->next;
	}
	return (sort_b(a, b, tmp.ret_rb));
}

int	sort_b(t_list	**a, t_list **b, size_t	len_b)
{
	if (len_b <= 3)
	{
		if (len_b == 2)
			sorttwob(*b);
		else if (len_b == 3)
		{
			if (ft_lstsize(*b) == 3)
				sorttrois_b(b);
			else
				sorttroistop(b);
		}
		return (0);
	}
	ft_sortbwithpivot(a, b, len_b);
	return (0);
}

// int	sort_b(t_list	**a, t_list **b, size_t	len_b)
// {
// 	if (len_b <= 3)
// 	{
// 		if (len_b == 2)
// 			sorttwob(*b);
// 		else if (len_b == 3)
// 		{
// 			if (ft_lstsize(*b) == 3)
// 				sorttrois_b(b);
// 			else
// 				sorttroistop_b(b);
// 		}
// 		return (0);
// 	}
// 	ft_sortwithpivot(a, b, len_b);
// 	return (0);
// }