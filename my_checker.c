/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:55:09 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/15 14:24:16 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_instruction(t_list **a, t_list **b, char *str, t_opt **optlst)
{
	if (!ft_strcmp(str, PA))
		pa(a, b, optlst);
	else if (!ft_strcmp(str, PB))
		pb(a, b, optlst);
	else if (!ft_strcmp(str, SA))
		sa(a, optlst);
	else if (!ft_strcmp(str, SB))
		sb(b, optlst);
	else if (!ft_strcmp(str, RA))
		ra(a, optlst);
	else if (!ft_strcmp(str, RB))
		rb(b, optlst);
	else if (!ft_strcmp(str, RRA))
		rra(a, optlst);
	else if (!ft_strcmp(str, RRB))
		rrb(b, optlst);
	else if (!ft_strcmp(str, RRR))
		rrr(a, b, optlst);
	else if (!ft_strcmp(str, SS))
		ss(a, b, optlst);
	else if (!ft_strcmp(str, RR))
		rr(a, b, optlst);
	else
		printerror();
}

int	read_file(t_list **a, t_list **b, t_opt **optlst)
{
	char	*str;

	str = get_next_line(0);
	if (str)
		check_instruction(a, b, str, optlst);
	while (str)
	{
		free (str);
		str = get_next_line(0);
		if (str)
			check_instruction(a, b, str, optlst);
	}
	return (0);
}

int	check_sort1(t_list *a)
{
	t_list	*tmp;
	t_list	*i;
	t_list	*j;

	tmp = a;
	i = tmp;
	j = tmp->next;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content - j->content > 0)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

void	check(t_list **a, t_list **b, t_opt **optlst)
{
	read_file(a, b, optlst);
	if (!check_sort1(*a) && !*b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int ac, char **av)
{
	t_var	v;
	t_list	*a;
	t_list	*b;
	t_opt	*optlst;

	optlst = NULL;
	b = NULL;
	a = NULL;
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
	v.j = -1;
	while (v.split[++v.j])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(v.split[v.j])));
	duplicate(a);
	check(&a, &b, &optlst);
}
