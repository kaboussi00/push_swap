/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisatiom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:45:47 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/28 20:51:16 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimisation(t_opt	**lst)
{
	t_opt	*tmp;

	tmp = *lst;
	while (lst)
	{
		if (tmp->str == strcmp(tmp->str ,PA) && tmp->next->str == strcmp(tmp->next->str ,PB))
		{
			ft_lstdelone(tmp->str);
			ft_lstdelone(tmp->next->str);
		}
		else if (tmp->str == "pb" && tmp->next->str == "pa")
		{
			ft_lstdelone(tmp->str);
			ft_lstdelone(tmp->next->str);
		}
		else if (tmp->str == "pb" && tmp->next->str == "pa")
		{
			ft_lstdelone(tmp->str);
			ft_lstdelone(tmp->next->str);
		}
		else if (tmp->str == "rra" && tmp->next->str == "ra")
		{
			ft_lstdelone(tmp->str);
			ft_lstdelone(tmp->next->str);
		}
		else if (tmp->str == "ra" && tmp->next->str == "rra")
		{
			ft_lstdelone(tmp->str);
			ft_lstdelone(tmp->next->str);
		}
		else if (tmp->str == "ra" && tmp->next->str == "rra")
		{
			ft_lstdelone(tmp->str);
			ft_lstdelone(tmp->next->str);
		}
		tmp->next = tmp->next->next->next->str;
		
	}
}
