/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:07:16 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/12 18:01:26 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_replace_rr(t_opt **lst)
{
	t_opt	*t;
	t_opt	*s;
	t_opt	*t2;

	t = *lst;
	s = t->next;
	t2 = t->next->next;
	if ((!ft_strcmp(t->str, RA) && !ft_strcmp(s->str, RB)) || \
		(!ft_strcmp(t->str, RB) && !ft_strcmp(s->str, RA)))
		return (t->next = t2, ft_lstdel(s), free(t2->str), t2->str = ft_strdup("rr\n"), 1);
	while (t && t->next && t->next->next)
	{
		s = t->next;
		t2 = t->next->next;
		if ((!ft_strcmp(s->str, RA) && !ft_strcmp(t2->str, RB)) || \
			(!ft_strcmp(s->str, RB) && !ft_strcmp(t2->str, RA)))
			return (t->next = t2, ft_lstdel(s), free(t2->str), t2->str = ft_strdup("rr\n"), 1);
		t = t->next;
	}
	return (0);
}

int	ft_replace_ss(t_opt **lst)
{
	t_opt	*t;
	t_opt	*s;
	t_opt	*t2;

	t = *lst;
	s = t->next;
	t2 = t->next->next;
	if ((!ft_strcmp(t->str, SA) && !ft_strcmp(s->str, SB)) || \
		(!ft_strcmp(t->str, SB) && !ft_strcmp(s->str, SA)))
		return (t->next = t2, ft_lstdel(s), free(t->str), t->str = ft_strdup("ss\n"), 1);
	while (t && t->next && t->next->next)
	{
		s = t->next;
		t2 = t->next->next;
		if ((!ft_strcmp(s->str, SA) && !ft_strcmp(t2->str, SB)) || \
			(!ft_strcmp(s->str, SB) && !ft_strcmp(t2->str, SA)))
			return (t->next = t2, ft_lstdel(s), free(t2->str), t2->str = ft_strdup("ss\n"), 1);
		t = t->next;
	}
	return (0);
}

int	ft_replace_rrr(t_opt **lst)
{
	t_opt	*t;
	t_opt	*s;
	t_opt	*t2;

	t = *lst;
	s = t->next;
	t2 = t->next->next;
	if ((!ft_strcmp(t->str, RRA) && !ft_strcmp(s->str, RRB)) || \
		(!ft_strcmp(t->str, RRB) && !ft_strcmp(s->str, RRA)))
		return (t->next = t2, ft_lstdel(s), free(t->str), t->str = ft_strdup("rrr\n"), 1);
	while (t && t->next && t->next->next)
	{
		s = t->next;
		t2 = t->next->next;
		if ((!ft_strcmp(s->str, RRA) && !ft_strcmp(t2->str, RRB)) || \
			(!ft_strcmp(s->str, RRB) && !ft_strcmp(t2->str, RRA)))
			return (t->next = t2, ft_lstdel(s), free(t2->str), t2->str = ft_strdup("rrr\n"), 1);
		t = t->next;
	}
	return (0);
}

void	opt_replace(t_opt **lst)
{
	int	l;
	int	o;
	int	v;

	while (1)
	{
		l = 0;
		o = 0;
		v = 0;
		l = ft_replace_rrr(lst);
		o = ft_replace_rr(lst);
		v = ft_replace_ss(lst);
		if (l == 0 && o == 0 && v == 0)
			break ;
	}
}
