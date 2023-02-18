/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils13.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:23:29 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/18 12:32:23 by kaboussi         ###   ########.fr       */
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
	return (sort_b(a, b, tmp.ret_rb), sort_a(a, b, tmp.ret_pa));
}

int	sort_b(t_list	**a, t_list **b, size_t	len_b)
{
	if (len_b <= 3)
	{
		if (len_b == 2)
			sorttwo_b(*b);
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