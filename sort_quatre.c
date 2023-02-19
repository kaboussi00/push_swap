/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils07.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:00:04 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/19 18:37:01 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minvalue(t_list **lst, t_list **b)
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
		rra(lst);
	else if (tmp3 < tmp && tmp3 < tmp2 && tmp3 < tmp4)
	{
		rra(lst);
		rra(lst);
	}
	else if (tmp2 < tmp3 && tmp2 < tmp && tmp2 < tmp4)
		sa(lst);
	pb(lst, b);
	return (0);
}

int	sortquatre(t_list	**lst, t_list	**b)
{
	int		tmp;
	int		tmp2;
	int		tmp3;
	int		tmp4;

	tmp = (*lst)->content;
	tmp2 = (*lst)->next->content;
	tmp3 = (*lst)->next->next->content;
	tmp4 = (*lst)->next->next->next->content;
	minvalue(lst, b);
	sorttrois(lst);
	pa(lst, b);
	return (0);
}
