/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreurs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:46:06 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/19 18:35:19 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	n;

	s = 1;
	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			(s *= -1);
		i++;
	}
	if (str[i] < 48 || str[i] > 57)
		printerror();
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + str[i++] - 48;
	if ((str[i] < 48 || str[i] > 57) && str[i])
		printerror();
	return (ft_limits(n * s));
}

void	printerror(void)
{
	write (2, "error\n", 6);
	exit(0);
}

int	ft_limits(int n)
{
	if (n >= -2147483648 && n <= 2147483647)
		return (n);
	else
		printerror();
	return (0);
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
