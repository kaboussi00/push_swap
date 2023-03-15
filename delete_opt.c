/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:45:47 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/15 13:49:44 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_del_sa_sb(t_opt	**lst)
{
	t_opt	*t;
	t_opt	*t2;
	t_opt	*t3;
	t_opt	*t4;

	t = *lst;
	t2 = t->next;
	t3 = t->next->next;
	if (((!ft_strcmp(t2->str, SA) && !ft_strcmp(t->str, SB))) || \
		(!ft_strcmp(t2->str, SB) && !ft_strcmp(t->str, SA)))
		return (*lst = t3, del(t2), del(t), 1);
	while (t && t->next && t->next->next)
	{
		t2 = t->next;
		t3 = t->next->next;
		t4 = t->next->next->next;
		if (((!ft_strcmp(t2->str, SA) && !ft_strcmp(t3->str, SB))) || \
		(!ft_strcmp(t2->str, SB) && !ft_strcmp(t3->str, SA)))
			return (t->next = t4, del(t2), del(t3), 1);
		t = t->next;
	}
	return (0);
}

int	ft_del_ra_rra(t_opt	**lst)
{
	t_opt	*t;
	t_opt	*t2;
	t_opt	*t3;
	t_opt	*t4;

	t = *lst;
	t2 = t->next;
	t3 = t->next->next;
	if (((!ft_strcmp(t2->str, RA) && !ft_strcmp(t->str, RRA))) || \
		(!ft_strcmp(t2->str, RRA) && !ft_strcmp(t->str, RA)))
		return (*lst = t3, del(t2), del(t), 1);
	while (t && t->next && t->next->next)
	{
		t2 = t->next;
		t3 = t->next->next;
		t4 = t->next->next->next;
		if (((!ft_strcmp(t2->str, RA) && !ft_strcmp(t3->str, RRA))) || \
		(!ft_strcmp(t2->str, RRA) && !ft_strcmp(t3->str, RA)))
			return (t->next = t4, del(t2), del(t3), 1);
		t = t->next;
	}
	return (0);
}

int	ft_del_rb_rrb(t_opt	**lst)
{
	t_opt	*t;
	t_opt	*t2;
	t_opt	*t3;
	t_opt	*t4;

	t = *lst;
	t2 = t->next;
	t3 = t->next->next;
	if (((!ft_strcmp(t2->str, RB) && !ft_strcmp(t->str, RRB))) || \
		(!ft_strcmp(t2->str, RRB) && !ft_strcmp(t->str, RB)))
		return (*lst = t3, del(t2), del(t), 1);
	while (t && t->next && t->next->next)
	{
		t2 = t->next;
		t3 = t->next->next;
		t4 = t->next->next->next;
		if (((!ft_strcmp(t2->str, RB) && !ft_strcmp(t3->str, RRB))) || \
		(!ft_strcmp(t2->str, RRB) && !ft_strcmp(t3->str, RB)))
			return (t->next = t4, del(t2), del(t3), 1);
		t = t->next;
	}
	return (0);
}

int	ft_del_pa_pb(t_opt	**lst)
{
	t_opt	*t;
	t_opt	*t2;
	t_opt	*t3;
	t_opt	*t4;

	t = *lst;
	t2 = t->next;
	t3 = t->next->next;
	if (((!ft_strcmp(t2->str, PA) && !ft_strcmp(t->str, PB))) || \
		(!ft_strcmp(t2->str, PB) && !ft_strcmp(t->str, PA)))
		return (*lst = t3, del(t2), del(t), 1);
	while (t && t->next && t->next->next)
	{
		t2 = t->next;
		t3 = t->next->next;
		t4 = t->next->next->next;
		if (((!ft_strcmp(t2->str, PA) && !ft_strcmp(t3->str, PB))) || \
		(!ft_strcmp(t2->str, PB) && !ft_strcmp(t3->str, PA)))
			return (t->next = t4, del(t2), del(t3), 1);
		t = t->next;
	}
	return (0);
}

void	opt_delete(t_opt **lst)
{
	int	l;
	int	o;
	int	v;
	int	e;

	while (1)
	{
		l = 0;
		o = 0;
		v = 0;
		e = 0;
		if (*lst && (*lst)->next)
			l = ft_del_pa_pb(lst);
		if (*lst && (*lst)->next)
			o = ft_del_ra_rra(lst);
		if (*lst && (*lst)->next)
			v = ft_del_rb_rrb(lst);
		if (*lst && (*lst)->next)
			e = ft_del_sa_sb(lst);
		if (l == 0 && o == 0 && v == 0 && e == 0)
			break ;
	}
}
