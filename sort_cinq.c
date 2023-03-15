/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cinq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:28:54 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/15 14:57:43 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_value(t_list **a, t_opt **optlst)
{
	int		tmp;
	int		tmp2;
	int		tmp3;
	int		tmp4;
	int		tmp5;

	tmp = (*a)->content;
	tmp2 = (*a)->next->content;
	tmp3 = (*a)->next->next->content;
	tmp4 = (*a)->next->next->next->content;
	tmp5 = (*a)->next->next->next->next->content;
	if (tmp5 < tmp4 && tmp5 < tmp3 && tmp5 < tmp2 && tmp5 < tmp)
		rra(a, optlst);
	else if (tmp4 < tmp3 && tmp4 < tmp2 && tmp4 < tmp && tmp4 < tmp5)
	{
		rra(a, optlst);
		rra(a, optlst);
	}
	else if (tmp3 < tmp && tmp3 < tmp2 && tmp3 < tmp4 && tmp3 < tmp5)
	{
		ra(a, optlst);
		ra(a, optlst);
	}
	else if (tmp2 < tmp3 && tmp2 < tmp && tmp2 < tmp4 && tmp2 < tmp5)
		sa(a, optlst);
}

int	sortcinq(t_list	**a, t_list	**b, t_opt **optlst)
{
	int		tmp;
	int		tmp2;
	int		tmp3;
	int		tmp4;
	int		tmp5;

	tmp = (*a)->content;
	tmp2 = (*a)->next->content;
	tmp3 = (*a)->next->next->content;
	tmp4 = (*a)->next->next->next->content;
	tmp5 = (*a)->next->next->next->next->content;
	min_value(a, optlst);
	pb(a, b, optlst);
	sortquatre(a, b, optlst);
	pa(a, b, optlst);
	return (0);
}
