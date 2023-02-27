/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_two_trs_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:02:34 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/24 16:47:50 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorttwo_b(t_list	**lst, t_opt **optlst)
{
	if (*lst && (*lst)->next)
	{
		if ((*lst)->next->content > (*lst)->content)
			sb(lst, optlst);
	}
	return (0);
}

int	sorttrois_b(t_list **lst, t_opt **optlst)
{
	t_var	tmp;

	tmp.tmp1_b = (*lst)->content;
	tmp.tmp2_b = (*lst)->next->content;
	tmp.tmp3_b = (*lst)->next->next->content;
	if (tmp.tmp1_b > tmp.tmp2_b && tmp.tmp1_b > tmp.tmp3_b)
	{
		if (tmp.tmp3_b > tmp.tmp2_b)
		{
			sb(lst, optlst);
			rb(lst, optlst);
		}
	}
	else if (tmp.tmp3_b > tmp.tmp2_b && tmp.tmp3_b > tmp.tmp1_b)
	{
		if (tmp.tmp2_b > tmp.tmp1_b)
			sb(lst, optlst);
		rrb(lst, optlst);
	}
	utilssortrois_b(lst, tmp, optlst);
	return (0);
}

int	utilssortrois_b(t_list **lst, t_var	tmp, t_opt **optlst)
{
	if (tmp.tmp2_b > tmp.tmp1_b && tmp.tmp2_b > tmp.tmp3_b)
	{
		if (tmp.tmp1_b > tmp.tmp3_b)
			sb(lst, optlst);
		else if (tmp.tmp3_b > tmp.tmp1_b)
			rb(lst, optlst);
	}
	return (0);
}

int	sorttroistop_b(t_list **b, t_opt **optlst)
{
	t_var	tmp;

	tmp.tmp1 = (*b)->content;
	tmp.tmp2 = (*b)->next->content;
	tmp.tmp3 = (*b)->next->next->content;
	if (tmp.tmp3 > tmp.tmp1 && tmp.tmp3 > tmp.tmp2)
	{
		if (tmp.tmp2 > tmp.tmp1)
			sb(b, optlst);
		rb(b, optlst);
		sb(b, optlst);
		rrb(b, optlst);
		sb(b, optlst);
	}
	else if (tmp.tmp1 > tmp.tmp2 && tmp.tmp1 > tmp.tmp3)
	{
		if (tmp.tmp3 > tmp.tmp2)
		{
			rb(b, optlst);
			sb(b, optlst);
			rrb(b, optlst);
		}
	}
	utilssortroistop_b(b, tmp, optlst);
	return (0);
}

int	utilssortroistop_b(t_list **b, t_var	tmp, t_opt **optlst)
{
	if (tmp.tmp2 > tmp.tmp1 && tmp.tmp2 > tmp.tmp3)
	{
		sb(b,optlst);
		if (tmp.tmp3 > tmp.tmp1)
		{
			rb(b, optlst);
			sb(b, optlst);
			rrb(b, optlst);
		}
	}
	return (0);
}
