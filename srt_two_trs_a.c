/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_two_trs_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:36:21 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/24 16:44:23 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorttwo(t_list	*lst, t_opt **optlst)
{
	if (lst->next->content < lst->content)
		sa(&lst, optlst);
	return (0);
}

int	sorttrois(t_list **lst, t_opt **optlst)
{
	int		tmp;
	int		tmp2;
	int		tmp3;

	tmp = (*lst)->content;
	tmp2 = (*lst)->next->content;
	tmp3 = (*lst)->next->next->content;
	if (tmp3 > tmp && tmp3 > tmp2)
	{
		if (tmp > tmp2)
			sa(lst, optlst);
	}
	else if (tmp2 > tmp3 && tmp2 > tmp)
	{
		rra(lst, optlst);
		if (tmp < tmp3)
			sa(lst, optlst);
	}
	else if (tmp > tmp2 && tmp > tmp3)
	{
		ra(lst, optlst);
		if (tmp2 > tmp3)
			sa(lst, optlst);
	}
	return (0);
}

int	sorttroistop(t_list **a, t_opt **optlst)
{
	t_var	tmp;

	tmp.tmp1 = (*a)->content;
	tmp.tmp2 = (*a)->next->content;
	tmp.tmp3 = (*a)->next->next->content;
	if (tmp.tmp3 > tmp.tmp1 && tmp.tmp3 > tmp.tmp2)
	{
		if (tmp.tmp1 > tmp.tmp2)
			sa(a, optlst);
	}
	else if (tmp.tmp1 > tmp.tmp2 && tmp.tmp1 > tmp.tmp3)
	{
		sa(a, optlst);
		ra(a, optlst);
		sa(a, optlst);
		rra(a, optlst);
		if (tmp.tmp2 > tmp.tmp3)
			sa(a, optlst);
	}
	utilsorttroistop(a, tmp, optlst);
	return (0);
}

int	utilsorttroistop(t_list **a, t_var	tmp, t_opt **optlst)
{
	if (tmp.tmp2 > tmp.tmp1 && tmp.tmp2 > tmp.tmp3)
	{
		ra(a, optlst);
		sa(a, optlst);
		rra(a, optlst);
		if (tmp.tmp1 > tmp.tmp3)
			sa(a, optlst);
	}
	return (0);
}
