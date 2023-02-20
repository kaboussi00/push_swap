/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:23:29 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/20 21:10:55 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("pivot_b : %d\n", tmp.pivot);
	while (tmpb && ++i < len_b)
	{
		if ((tmpb)->content > tmp.pivot)
		{
			pa(a, b);
			tmp.ret_pa += 1;
		}
		else if ((tmpb)->content <= tmp.pivot)
		{
			rb(b);
			tmp.ret_rb += 1;
		}
		tmpb = tmpb->next;
	}
	sort_a(a, b, tmp.ret_pa);
	return (rr_b(b, tmp), sort_b(a, b, tmp.ret_rb), tmp.ret_pa);
}

int	sort_b(t_list	**a, t_list **b, size_t	len_b)
{
	int	k;

	if (len_b <= 3)
	{
		if (len_b == 2)
			sorttwo_b(b);
		else if (len_b == 3)
		{
			if (ft_lstsize(*b) == 3)
			{
				sorttrois_b(b);
			}
			else
			{
				sorttroistop_b(b);
			}
		}
		return (0);
	}
	k = ft_sortbwithpivot(a, b, len_b);
	back_to_b(a, b, k);
	return (0);
}
