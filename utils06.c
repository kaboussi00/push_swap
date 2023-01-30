/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils06.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:52:15 by kaboussi          #+#    #+#             */
/*   Updated: 2023/01/30 16:45:46 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **a, t_list **b)
{
	if ((*a) && (*b))
	{
		rra(a);
		rrb(b);
	}
}

int	duplicate(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = lst;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp->content == tmp1->content)
				printerror();
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

