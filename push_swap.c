/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:41:33 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/15 15:32:34 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prt_opt(t_opt	*optlst)
{
	while (optlst)
	{
		ft_putstr(optlst->str);
		optlst = optlst->next;
	}
}

void	sort(t_list **a, t_list **b, t_opt **op, t_var v)
{
	if (!check_sort(*a))
		exit(0);
	if (v.j == 2)
		sorttwo(*a, op);
	if (v.j == 3)
		sorttrois(a, op);
	if (v.j == 4)
		sortquatre(a, b, op);
	if (v.j == 5)
		sortcinq(a, b, op);
	if (v.j > 5)
		sort_a(a, b, v.j, op);
}

int	main(int ac, char **av)
{
	t_var	v;
	t_list	*a;
	t_list	*b;
	t_opt	*op;

	op = NULL;
	a = NULL;
	b = NULL;
	v.j = 0;
	if (ac == 1)
		return (0);
	v.join = p("");
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
	sort(&a, &b, &op, v);
	opt_replace(&op);
	return (opt_delete(&op), prt_opt(op), ft_freee(&a, &b, &op, v), 0);
}
