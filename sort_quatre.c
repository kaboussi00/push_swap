/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quatre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:00:04 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/24 16:39:59 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minvalue(t_list **lst, t_list **b, t_opt **optlst)
{
	int		tmp;
	int		tmp2;
	int		tmp3;
	int		tmp4;

	tmp = (*lst)->content;
	tmp2 = (*lst)->next->content;
	tmp3 = (*lst)->next->next->content;
	tmp4 = (*lst)->next->next->next->content;
	if (tmp4 < tmp && tmp4 < tmp2 && tmp4 < tmp3)
		rra(lst, optlst);
	else if (tmp3 < tmp && tmp3 < tmp2 && tmp3 < tmp4)
	{
		rra(lst, optlst);
		rra(lst, optlst);
	}
	else if (tmp2 < tmp3 && tmp2 < tmp && tmp2 < tmp4)
		sa(lst, optlst);
	pb(lst, b, optlst);
	return (0);
}

int	sortquatre(t_list	**lst, t_list	**b, t_opt **optlst)
{
	int		tmp;
	int		tmp2;
	int		tmp3;
	int		tmp4;

	tmp = (*lst)->content;
	tmp2 = (*lst)->next->content;
	tmp3 = (*lst)->next->next->content;
	tmp4 = (*lst)->next->next->next->content;
	minvalue(lst, b, optlst);
	sorttrois(lst, optlst);
	pa(lst, b, optlst);
	return (0);
}
