/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:41:33 by kaboussi          #+#    #+#             */
/*   Updated: 2023/01/30 16:49:48 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	*join;
	char	**split;
	t_list	*a;
	t_list	*b;

	b = NULL;
	i = 1;
	join = ft_strdup("");
	if (ac == 1)
		return (0);
	else if (ac > 2)
	{
		while (ac > i)
		{
			join = ft_strjoin(join, ft_strjoin(av[i], " "));
			i++;
		}
		split = ft_split(join, ' ');
		i = 0;
		while (split[i])
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(split[i++])));
		duplicate(a);
		sortcinq(&a, &b);
		while (a)
		{
			printf("%d\n",a->content);
			a = a->next;
		}
	}
}
