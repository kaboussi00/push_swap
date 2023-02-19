/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils08.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:28:54 by kaboussi          #+#    #+#             */
/*   Updated: 2023/01/21 19:54:52 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_value(t_list **lst)
{
	int		tmp;
	int		tmp2;
	int		tmp3;
	int		tmp4;
	int		tmp5;

	tmp = (*lst)->content;
	tmp2 = (*lst)->next->content;
	tmp3 = (*lst)->next->next->content;
	tmp4 = (*lst)->next->next->next->content;
	tmp5 = (*lst)->next->next->next->next->content;
	if (tmp5 < tmp4 && tmp5 < tmp3 && tmp5 < tmp2 && tmp5 < tmp)
		rra(lst);
	else if (tmp4 < tmp3 && tmp4 < tmp2 && tmp4 < tmp && tmp4 < tmp5)
	{
		rra(lst);
		rra(lst);
	}
	else if (tmp3 < tmp && tmp3 < tmp2 && tmp3 < tmp4 && tmp3 < tmp5)
	{
		ra(lst);
		ra(lst);
	}
	else if (tmp2 < tmp3 && tmp2 < tmp && tmp2 < tmp4 && tmp2 < tmp5)
		sa(lst);
}

int	sortcinq(t_list	**lst, t_list	**b)
{
	int		tmp;
	int		tmp2;
	int		tmp3;
	int		tmp4;
	int		tmp5;

	tmp = (*lst)->content;
	tmp2 = (*lst)->next->content;
	tmp3 = (*lst)->next->next->content;
	tmp4 = (*lst)->next->next->next->content;
	tmp5 = (*lst)->next->next->next->next->content;
	min_value(lst);
	pb(lst, b);
	sortquatre(lst, b);
	pa(lst, b);
	return (0);
}
