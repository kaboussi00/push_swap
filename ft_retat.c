/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:23:54 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/10 18:10:27 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr_a(t_list **a, t_var tmp, t_opt **optlst)
{
	int	i;
	int	j;

	i = 0;
	j = ft_lstsize(*a);
	if (j / 2 > tmp.ret_ra)
	{
		while (tmp.ret_ra > i++)
			rra(a, optlst);
	}
	else
	{
		while (j - tmp.ret_ra > i++)
			ra(a, optlst);
	}
	return (0);
}

int	rr_b(t_list **b, t_var tmp, t_opt **optlst)
{
	int	i;
	int	j;

	i = 0;
	j = ft_lstsize(*b);
	if (j / 2 > tmp.ret_rb)
	{
		while (tmp.ret_rb > i++)
			rrb(b, optlst);
	}
	else
	{
		while (j - tmp.ret_rb > i++)
			rb(b, optlst);
	}
	return (0);
}
