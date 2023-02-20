/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:33:53 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/20 20:22:47 by kaboussi         ###   ########.fr       */
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
