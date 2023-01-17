/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:18:38 by kaboussi          #+#    #+#             */
/*   Updated: 2023/01/16 15:06:17 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	int	tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next->content;
		(*a)->next->content = (*a)->content;
		(*a)->content = tmp;
	}
	ft_putstr("sa\n");
}

void	sb(t_list **b)
{
	int	tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->next->content;
		(*b)->next->content = (*b)->content;
		(*b)->content = tmp;
	}
	ft_putstr("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	if ((*a) && ((*a)->next) && (*b) && ((*b)->next))
	{
		sa(a);
		sb(b);
	}
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (*b)
	{
		tmp = (*b)->next;
		(*b)->next = NULL;
		ft_lstadd_front (a, ft_lstnew((*b)->content));
		(*b) = tmp;
	}
	ft_putstr("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (*a)
	{
		tmp = (*a)->next;
		(*a)->next = NULL;
		ft_lstadd_front (b, ft_lstnew((*a)->content));
		(*a) = tmp;
	}
	ft_putstr("pb\n");
}
