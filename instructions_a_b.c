/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:52:15 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/24 16:42:56 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **a, t_list **b, t_opt **optlst)
{
	if ((*a) && (*b))
	{
		ra(a, optlst);
		rb(b, optlst);
	}
}

void	rrr(t_list **a, t_list **b, t_opt **optlst)
{
	if ((*a) && (*b))
	{
		rra(a, optlst);
		rrb(b, optlst);
	}
}

void	ss(t_list **a, t_list **b, t_opt **optlst)
{
	if ((*a) && ((*a)->next) && (*b) && ((*b)->next))
	{
		sa(a, optlst);
		sb(b, optlst);
	}
}
