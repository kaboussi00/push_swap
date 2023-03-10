/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:52:00 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/10 16:54:07 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	t_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		last = ft_lstlast(tmp);
		last->next = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_opt	*lstnewstr(char *str)
{
	t_opt	*k;

	k = malloc(sizeof(t_opt));
	if (!k)
		return (NULL);
	k->str = ft_strdup(str);
	k->next = NULL;
	return (k);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int				i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)str1;
	st2 = (unsigned char *)str2;
	while (st1[i] != '\0' || st2[i] != '\0')
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}

void	ft_addback(t_opt **lst, t_opt *new)
{
	t_opt	*last;
	t_opt	*tmp;

	if (*lst)
	{
		tmp = *lst;
		last = ft_last(tmp);
		last->next = new;
	}
	else
		*lst = new;
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*p;
	int		i;

	len = ft_strlen(str);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

t_opt	*ft_last(t_opt *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_lstdel(t_opt *lst)
{
	if (lst)
	{
		free(lst);
		lst = NULL;
	}
}

// int	ft_del_sa_sb(t_opt	**lst)
// {
// 	t_opt	*t;
// 	t_opt	*t2;
// 	t_opt	*t3;
// 	t_opt	*t4;

// 	t = *lst;
// 	t2 = t->next;
// 	t3 = t->next->next;
// 	if (((!ft_strcmp(t2->str, SA) && !ft_strcmp(t->str, SB))) || \
// 		(!ft_strcmp(t2->str, SB) && !ft_strcmp(t->str, SA)))
// 		return (ft_lstdel(t2), ft_lstdel(t), *lst = t3, 1);
// 	while (t && t->next && t->next->next)
// 	{
// 		t2 = t->next;
// 		t3 = t->next->next;
// 		t4 = t->next->next->next;
// 		if (((!ft_strcmp(t2->str, SA) && !ft_strcmp(t3->str, SB))) || \
// 		(!ft_strcmp(t2->str, SB) && !ft_strcmp(t3->str, SA)))
// 			return (ft_lstdel(t2), ft_lstdel(t3), t->next = t4, 1);
// 		t = t->next;
// 	}
// 	return (0);
// }

// int	ft_del_ra_rra(t_opt	**lst)
// {
// 	t_opt	*t;
// 	t_opt	*t2;
// 	t_opt	*t3;
// 	t_opt	*t4;

// 	t = *lst;
// 	t2 = t->next;
// 	t3 = t->next->next;
// 	if (((!ft_strcmp(t2->str, RA) && !ft_strcmp(t->str, RRA))) || \
// 		(!ft_strcmp(t2->str, RRA) && !ft_strcmp(t->str, RA)))
// 		return (ft_lstdel(t2), ft_lstdel(t), *lst = t3, 1);
// 	while (t && t->next && t->next->next)
// 	{
// 		t2 = t->next;
// 		t3 = t->next->next;
// 		t4 = t->next->next->next;
// 		if (((!ft_strcmp(t2->str, RA) && !ft_strcmp(t3->str, RRA))) || \
// 		(!ft_strcmp(t2->str, RRA) && !ft_strcmp(t3->str, RA)))
// 			return (ft_lstdel(t2), ft_lstdel(t3), t->next = t4, 1);
// 		t = t->next;
// 	}
// 	return (0);
// }

// int	ft_del_rb_rrb(t_opt	**lst)
// {
// 	t_opt	*t;
// 	t_opt	*t2;
// 	t_opt	*t3;
// 	t_opt	*t4;

// 	t = *lst;
// 	t2 = t->next;
// 	t3 = t->next->next;
// 	if (((!ft_strcmp(t2->str, RB) && !ft_strcmp(t->str, RRB))) || \
// 		(!ft_strcmp(t2->str, RRB) && !ft_strcmp(t->str, RB)))
// 		return (ft_lstdel(t2), ft_lstdel(t), *lst = t3, 1);
// 	while (t && t->next && t->next->next)
// 	{
// 		t2 = t->next;
// 		t3 = t->next->next;
// 		t4 = t->next->next->next;
// 		if (((!ft_strcmp(t2->str, RB) && !ft_strcmp(t3->str, RRB))) || \
// 		(!ft_strcmp(t2->str, RRB) && !ft_strcmp(t3->str, RB)))
// 			return (ft_lstdel(t2), ft_lstdel(t3), t->next = t4, 1);
// 		t = t->next;
// 	}
// 	return (0);
// }

// int	ft_del_pa_pb(t_opt	**lst)
// {
// 	t_opt	*t;
// 	t_opt	*t2;
// 	t_opt	*t3;
// 	t_opt	*t4;

// 	t = *lst;
// 	t2 = t->next;
// 	t3 = t->next->next;
// 	if (((!ft_strcmp(t2->str, PA) && !ft_strcmp(t->str, PB))) || \
// 		(!ft_strcmp(t2->str, PB) && !ft_strcmp(t->str, PA)))
// 		return (ft_lstdel(t2), ft_lstdel(t), *lst = t3, 1);
// 	while (t && t->next && t->next->next)
// 	{
// 		t2 = t->next;
// 		t3 = t->next->next;
// 		t4 = t->next->next->next;
// 		if (((!ft_strcmp(t2->str, PA) && !ft_strcmp(t3->str, PB))) || \
// 		(!ft_strcmp(t2->str, PB) && !ft_strcmp(t3->str, PA)))
// 			return (ft_lstdel(t2), ft_lstdel(t3), t->next = t4, 1);
// 		t = t->next;
// 	}
// 	return (0);
// }


// void	opt_delete(t_opt **lst)
// {
// 	int	l;
// 	int	o;
// 	int	v;
// 	int	e;

// 	while (1)
// 	{
// 		l = 0;
// 		o = 0;
// 		v = 0;
// 		e = 0;
// 		if (*lst && (*lst)->next)
// 			l = ft_del_pa_pb(lst);
// 		if (*lst && (*lst)->next)
// 			o = ft_del_ra_rra(lst);
// 		if (*lst && (*lst)->next)
// 			v = ft_del_rb_rrb(lst);
// 		if (*lst && (*lst)->next)
// 			e = ft_del_sa_sb(lst);
// 		if (l == 0 && o == 0 && v == 0 && e == 0)
// 			break ;
// 	}
// }

// void	ft_replace_rrr(t_opt	**lst)
// {
// 	t_opt	*tmp;
// 	t_opt	*tmp1;
// 	t_opt	*tmp2;

// 	tmp = *lst;
// 	tmp1 = tmp->next;
// 	tmp2 = tmp->next->next;
// 	if (((!ft_strcmp(tmp2->str, RA) && !ft_strcmp(tmp->str, RRA))) || \
// 		(!ft_strcmp(tmp2->str, RRA) && !ft_strcmp(tmp->str, RA)))
// 		return (ft_lstdel(tmp1), tmp2->str = ft_strdup("rrr\n"), 1);
// 	while (tmp && tmp->next)
// 	{
		
// 		if ((!ft_strcmp(tmp1->str, RRA) && !ft_strcmp(tmp2->next->str, RRB)) || \
// 		(!ft_strcmp(tmp1->str, RRB) && !ft_strcmp(tmp2->str, RRA)))
// 		{
// 			free(tmp1);
// 			tmp1 = NULL;
// 			tmp2->str = ft_strdup("rrr\n");
// 		}
// 		tmp = tmp->next;
// 	}
// }

// void	ft_replace_rrr(t_opt	**lst)
// {
// 	t_opt	*tmp;
// 	t_opt	*tmp1;
// 	t_opt	*tmp2;

// 	tmp = *lst;
// 	tmp1 = tmp->next;
// 	tmp2 = tmp->next->next;
// 	while (tmp)
// 	{
// 		if ((!ft_strcmp(tmp1->str, RRA) && !ft_strcmp(tmp2->next->str, RRB)) || \
// 		(!ft_strcmp(tmp1->str, RRB) && !ft_strcmp(tmp2->str, RRA)))
// 		{
// 			free(tmp1);
// 			tmp1 = NULL;
// 			tmp2->str = ft_strdup("rrr\n");
// 		}
// 		tmp = tmp->next;
// 	}
// }

int	ft_replace_rrr(t_opt	**lst)
{
	t_opt	*tmp;
	t_opt	*tmp1;
	t_opt	*tmp2;

	tmp = *lst;
	tmp1 = tmp->next;
	if ((!ft_strcmp(tmp->str, RRA) && !ft_strcmp(tmp1->str, RRB)) || \
		(!ft_strcmp(tmp->str, RRB) && !ft_strcmp(tmp1->str, RRA)))
	{
		tmp->next = tmp1->next;
		free (tmp1);
		tmp1 = NULL;
		tmp->str = ft_strdup("rrr\n");
		return (1);
	}
	while (tmp && tmp->next && tmp->next->next)
	{
		tmp1 = tmp->next;
		tmp2 = tmp->next->next;
		if ((!ft_strcmp(tmp1->str, RRA) && !ft_strcmp(tmp2->str, RRB)) || \
			(!ft_strcmp(tmp1->str, RRB) && !ft_strcmp(tmp2->str, RRA)))
		{
			free(tmp1);
			tmp1 = NULL;
			tmp2->str = ft_strdup("rrr\n");
			tmp->next = tmp2;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_replace_ss(t_opt **lst)
{
	t_opt	*tmp;
	t_opt	*tmp1;
	t_opt	*tmp2;
	
	tmp = *lst;
	tmp1 = tmp->next;
	if ((!ft_strcmp(tmp->str, SA) && !ft_strcmp(tmp1->str, SB)) || \
		(!ft_strcmp(tmp->str, SB) && !ft_strcmp(tmp1->str, SA)))
	{
		tmp->next = tmp1->next;
		free (tmp1);
		tmp1 = NULL;
		tmp->str = ft_strdup("ss\n");
		return (1);
	}
	while (tmp && tmp->next && tmp->next->next)
	{
		tmp1 = tmp->next;
		tmp2 = tmp->next->next;
		if ((!ft_strcmp(tmp1->str, SA) && !ft_strcmp(tmp2->str, SB)) || \
			(!ft_strcmp(tmp1->str, SB) && !ft_strcmp(tmp2->str, SA)))
		{
			free(tmp1);
			tmp1 = NULL;
			tmp2->str = ft_strdup("ss\n");
			tmp->next = tmp2;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_replace_rr(t_opt **lst)
{
	t_opt	*t;
	t_opt	*t1;
	t_opt	*t2;
	
	t = *lst;
	t1 = t->next;
	if ((!ft_strcmp(t->str, RA) && !ft_strcmp(t1->str, RB)) || \
		(!ft_strcmp(t->str, RB) && !ft_strcmp(t1->str, RA)))
	{
		t->next = t1->next;
		ft_lstdel(t1);
		t->str = ft_strdup("rr\n");
		return (t->next = t1->next, ft_lstdel(t1), t->str = ft_strdup("rr\n"), 1);
	}
	while (t && t->next && t->next->next)
	{
		t1 = t->next;
		t2 = t->next->next;
		if ((!ft_strcmp(t1->str, RA) && !ft_strcmp(t2->str, RB)) || \
			(!ft_strcmp(t1->str, RB) && !ft_strcmp(t2->str, RA)))
			return (ft_lstdel(t1), t2->str = ft_strdup("rr\n"), t->next = t2, 1);
		t = t->next;
	}
	return (0);
}

void	opt_replace(t_opt **lst)
{
	int	l;
	int	o;
	int	v;
	
	while (1)
	{
		l = 0;
		o = 0;
		v = 0;
		l = ft_replace_rrr(lst);
		o = ft_replace_rr(lst);
		v = ft_replace_ss(lst);
		if ( l == 0 && o == 0 && v == 0)
			break ;
	}
}

int main()
{
	t_opt   *a;
	t_opt   *b;

	a = NULL;
	b = NULL;
	ft_addback(&a,lstnewstr("sa\n"));
	ft_addback(&a,lstnewstr("sb\n"));
	ft_addback(&a,lstnewstr("rra\n"));
	ft_addback(&a,lstnewstr("rrb\n"));
	ft_addback(&a,lstnewstr("rb\n"));
	ft_addback(&a,lstnewstr("ra\n"));
	ft_addback(&a,lstnewstr("pb\n"));
	ft_addback(&a,lstnewstr("sa\n"));
	ft_addback(&a,lstnewstr("sb\n"));
	ft_addback(&a,lstnewstr("rra\n"));
	ft_addback(&a,lstnewstr("rrb\n"));
	ft_addback(&a,lstnewstr("rb\n"));
	ft_addback(&a,lstnewstr("ra\n"));
	ft_addback(&a,lstnewstr("sb\n"));
	ft_addback(&a,lstnewstr("ps\n"));
	ft_addback(&a,lstnewstr("pa\n"));
	ft_addback(&a,lstnewstr("pa\n"));
	ft_addback(&a,lstnewstr("pb\n"));
	ft_addback(&a,lstnewstr("rra\n"));
	ft_addback(&a,lstnewstr("pa\n"));
	ft_addback(&a,lstnewstr("sa\n"));
	ft_addback(&a,lstnewstr("pa\n"));
	ft_addback(&a,lstnewstr("sb\n"));
	ft_addback(&a,lstnewstr("ps\n"));
	ft_addback(&a,lstnewstr("pa\n"));
	ft_addback(&a,lstnewstr("pb\n"));
	opt_replace(&a);
	while (a)
	{
		printf("%s",a->str);
		a = a->next;
	}
}