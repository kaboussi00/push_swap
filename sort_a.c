/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:44:12 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/12 19:38:13 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_sortawithpivot(t_list **a, t_list **b, size_t len_a, t_opt **optlst)
{
	t_list	*tmpa;
	t_var	tmp;

	tmp.ret_pb = 0;
	tmp.ret_ra = 0;
	tmp.i = -1;
	tmpa = (*a);
	tmp.pivot = sort_lst(*a, len_a);
	while (tmpa && ++tmp.i < len_a)
	{
		if ((tmpa)->content < tmp.pivot)
		{
			pb(a, b, optlst);
			tmp.ret_pb += 1;
		}
		else if ((tmpa)->content >= tmp.pivot)
		{
			ra(a, optlst);
			tmp.ret_ra += 1;
		}
		tmpa = tmpa->next;
	}
	rr_a(a, tmp, optlst);
	sort_a(a, b, tmp.ret_ra, optlst);
	return (sort_b(a, b, tmp.ret_pb, optlst), tmp.ret_pb);
}

int	sort_a(t_list	**a, t_list **b, size_t	len_a, t_opt **optlst)
{
	int		k;

	if (len_a <= 3)
	{
		if (len_a == 2)
			sorttwo(*a, optlst);
		else if (len_a == 3)
		{
			if (ft_lstsize(*a) == 3)
				sorttrois(a, optlst);
			else
				sorttroistop(a, optlst);
		}
		return (0);
	}
	k = ft_sortawithpivot(a, b, len_a, optlst);
	back_to_a(a, b, k, optlst);
	return (0);
}
