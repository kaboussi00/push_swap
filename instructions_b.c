/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:18:38 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/11 16:30:57 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **b, t_opt **optlst)
{
	int	tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->next->content;
		(*b)->next->content = (*b)->content;
		(*b)->content = tmp;
	}
	ft_addback(optlst, lstnewstr("sb\n"));
}

void	rb(t_list **b, t_opt **optlst)
{
	t_list	*tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b);
		(*b) = tmp->next;
		ft_lstadd_back(b, ft_lstnew(tmp->content));
	}
	ft_addback(optlst, lstnewstr("rb\n"));
}

void	pb(t_list **a, t_list **b, t_opt **optlst)
{
	t_list	*tmp;

	tmp = NULL;
	if (*a)
	{
		tmp = (*a);
		(*a) = tmp->next;
		ft_lstadd_front (b, ft_lstnew(tmp->content));
	}
	ft_addback(optlst, lstnewstr("pb\n"));
}

void	rrb(t_list **b, t_opt **optlst)
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
	}
	ft_addback(optlst, lstnewstr("rrb\n"));
}
