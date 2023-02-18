/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:18:38 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/18 11:50:35 by kaboussi         ###   ########.fr       */
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
		tmp = (*b);
		(*b) = tmp->next;
		ft_lstadd_front (a, ft_lstnew(tmp->content));
		free(tmp);
		tmp = NULL;
	}
	ft_putstr("pa\n");
}



void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (*a)
	{
		tmp = (*a);
		(*a) = tmp->next;
		ft_lstadd_front (b, ft_lstnew(tmp->content));
		free(tmp);
		tmp = NULL;
	}
	ft_putstr("pb\n");
}
