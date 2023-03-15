/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quatre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:00:04 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/15 14:59:45 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minvalue(t_list **a, t_list **b, t_opt **optlst)
{
	int		tmp;
	int		tmp2;
	int		tmp3;
	int		tmp4;

	tmp = (*a)->content;
	tmp2 = (*a)->next->content;
	tmp3 = (*a)->next->next->content;
	tmp4 = (*a)->next->next->next->content;
	if (tmp4 < tmp && tmp4 < tmp2 && tmp4 < tmp3)
		rra(a, optlst);
	else if (tmp3 < tmp && tmp3 < tmp2 && tmp3 < tmp4)
	{
		rra(a, optlst);
		rra(a, optlst);
	}
	else if (tmp2 < tmp3 && tmp2 < tmp && tmp2 < tmp4)
		sa(a, optlst);
	pb(a, b, optlst);
	return (0);
}

int	sortquatre(t_list	**a, t_list	**b, t_opt **optlst)
{
	int		tmp;
	int		tmp2;
	int		tmp3;
	int		tmp4;

	tmp = (*a)->content;
	tmp2 = (*a)->next->content;
	tmp3 = (*a)->next->next->content;
	tmp4 = (*a)->next->next->next->content;
	minvalue(a, b, optlst);
	sorttrois(a, optlst);
	pa(a, b, optlst);
	return (0);
}
