/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils05.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:57:05 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/14 13:52:09 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a);
		(*a) = tmp->next;
		ft_lstadd_back(a, ft_lstnew(tmp->content));
		free(tmp);
		tmp = NULL;
	}
	ft_putstr("ra\n");
}

void	rb(t_list **b)
{
	t_list	*tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b);
		(*b) = tmp->next;
		ft_lstadd_back(b, ft_lstnew(tmp->content));
		free(tmp);
		tmp = NULL;
	}
	ft_putstr("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	if ((*a) && (*b))
	{
		ra(a);
		rb(b);
	}
}

void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		x;

	tmp1 = *a;
	if ((*a) && (*a)->next)
	{
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp = ft_lstlast(*a);
		x = tmp->content;
		ft_lstadd_front((a), ft_lstnew(x));
		tmp1->next = NULL;
		ft_lstdelone(tmp);
	}
	ft_putstr("rra\n");
}

void	rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		x;

	tmp1 = *b;
	if ((*b) && (*b)->next)
	{
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp = ft_lstlast(*b);
		x = tmp->content;
		ft_lstadd_front((b), ft_lstnew(x));
		tmp1->next = NULL;
		ft_lstdelone(tmp);
	}
	ft_putstr("rrb\n");
}
