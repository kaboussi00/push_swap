/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructin_a_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:52:15 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/19 18:36:23 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **a, t_list **b)
{
	if ((*a) && (*b))
	{
		ra(a);
		rb(b);
	}
}

void	rrr(t_list **a, t_list **b)
{
	if ((*a) && (*b))
	{
		rra(a);
		rrb(b);
	}
}

void	ss(t_list **a, t_list **b)
{
	if ((*a) && ((*a)->next) && (*b) && ((*b)->next))
	{
		sa(a);
		sb(b);
	}
}
