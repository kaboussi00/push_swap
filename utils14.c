/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils14.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:38:15 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/18 15:28:36 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	back_to_a(t_list **a, t_list **b, int k)
{
	int	i;

	i = 0;
	while (k > i)
	{
		pa(a, b);
		i++;
	}
	return (0);
}

int	back_to_b(t_list **a, t_list **b, int k)
{
	int	i;

	i = 0;
	while (k > i)
	{
		pb(a, b);
		i++;
	}
	return (0);
}