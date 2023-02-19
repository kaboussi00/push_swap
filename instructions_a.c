/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:57:05 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/19 18:34:45 by kaboussi         ###   ########.fr       */
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

