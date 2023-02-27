/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:23:29 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/27 20:16:05 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sortbwithpivot(t_list **a, t_list **b, size_t len_b, t_opt **optl)
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
		if ((tmpb)->content > tmp.pivot)
		{
			pa(a, b, optl);
			tmp.ret_pa += 1;
		}
		else if ((tmpb)->content <= tmp.pivot)
		{
			rb(b, optl);
			tmp.ret_rb += 1;
		}
		tmpb = tmpb->next;
	}
	sort_a(a, b, tmp.ret_pa, optl);
	return (rr_b(b, tmp, optl), sort_b(a, b, tmp.ret_rb, optl), tmp.ret_pa);
}

int	sort_b(t_list	**a, t_list **b, size_t	len_b, t_opt **optlst)
{
	int	k;

	if (len_b <= 3)
	{
		if (len_b == 2)
			sorttwo_b(b, optlst);
		else if (len_b == 3)
		{
			if (ft_lstsize(*b) == 3)
			{
				sorttrois_b(b, optlst);
			}
			else
			{
				sorttroistop_b(b, optlst);
			}
		}
		return (0);
	}
	k = ft_sortbwithpivot(a, b, len_b, optlst);
	back_to_b(a, b, k, optlst);
	return (0);
}
