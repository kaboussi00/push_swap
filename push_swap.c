/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:41:33 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/14 13:00:33 by kaboussi         ###   ########.fr       */
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

void	free_lst(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = lst;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
		tmp2 = NULL;
	}
}

void	free_opt(t_opt *lst)
{
	t_opt	*tmp1;
	t_opt	*tmp2;

	tmp1 = lst;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2->str);
		tmp2->str = NULL;
		free(tmp2);
		tmp2 = NULL;
	}
}

void	ft_freee(t_list **a, t_list **b, t_opt **optlst, t_var v)
{
	free_lst(*a);
	free_lst(*b);
	free_opt(*optlst);
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
	{
		v.join = ft_strjoin(v.join, av[v.j]);
		v.join = ft_strjoin(v.join, " ");
	}
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
	// while (1)
	// 	;
}
