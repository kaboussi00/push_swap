/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils11.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:44:12 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/18 12:25:01 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_sortawithpivot(t_list **a, t_list **b, size_t len_a)
{
	t_list	*tmpa;
	t_var	tmp;
	size_t	i;

	tmp.ret_pb = 0;
	tmp.ret_ra = 0;
	i = -1;
	tmpa = (*a);
	tmp.pivot = sort_lst(*a, len_a);
	while (tmpa && ++i < len_a)
	{
		if ((tmpa)->content < tmp.pivot)
		{
			pb(a, b);
			tmp.ret_pb += 1;
		}
		else if ((tmpa)->content >= tmp.pivot)
		{
			ra(a);
			tmp.ret_ra += 1;
		}
		tmpa = tmpa->next;
	}
	return (sort_a(a, b, tmp.ret_ra), sort_b(a, b, tmp.ret_pb));
}

int	sort_a(t_list	**a, t_list **b, size_t	len_a)
{
	if (len_a <= 3)
	{
		if (len_a == 2)
			sorttwo(*a);
		else if (len_a == 3)
		{
			if (ft_lstsize(*a) == 3)
				sorttrois(a);
			else
				sorttroistop(a);
		}
		return (0);
	}
	ft_sortawithpivot(a, b, len_a);
	return (0);
}
