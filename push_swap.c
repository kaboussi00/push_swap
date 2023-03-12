/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:41:33 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/11 17:42:01 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prt_opt(t_opt	*optlst)
{
	while (optlst)
	{
		printf("%s", optlst->str);
		optlst = optlst->next;
	}
}

void	ft_freee(t_list **a, t_list **b, t_opt **optlst, t_var v)
{
	free(*a);
	free(*b);
	free(*optlst);
	free(v.join);
	ft_free(v.split);
}

int	main(int ac, char **av)
{
	t_var	v;
	t_list	*a;
	t_list	*b;
	t_opt	*optlst;

	optlst = NULL;
	a = NULL;
	b = NULL;
	v.j = 0;
	if (ac == 1)
		return (0);
	v.join = ft_strdup("");
	while (++v.j < ac)
		v.join = ft_strjoin(v.join, ft_strjoin(av[v.j], " "));
	v.split = ft_split(v.join, ' ');
	v.j = 0;
	while (v.split[v.j])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(v.split[v.j++])));
	duplicate(a);
	sort_a(&a, &b, v.j, &optlst);
	opt_replace(&optlst);
	opt_delete(&optlst);
	prt_opt(optlst);
	ft_freee(&a, &b, &optlst, v);
	while (1)
		;
}
