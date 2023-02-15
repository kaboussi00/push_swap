#include "push_swap.h"

// void	ft_swap(int *a, int *b)
// {
// 	int	tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}


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

t_list	*ft_lstnew(int content)
{
	t_list	*k;

	k = malloc(sizeof(t_list));
	if (!k)
		return (NULL);
	k->content = content;
	k->next = NULL;
	return (k);
}

void	rb(t_list **b)
{
	t_list	*tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b);
		(*b) = tmp->next;
		ft_lstadd_back(b, ft_lstnew(tmp->content));
		free(tmp);
		tmp = NULL;
	}
	ft_putstr("rb\n");
}

void	sb(t_list **b)
{
	int	tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->next->content;
		(*b)->next->content = (*b)->content;
		(*b)->content = tmp;
	}
	ft_putstr("sb\n");
}

void	ft_putstr(char *s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		x;

	tmp1 = *b;
	if ((*b) && (*b)->next)
	{
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp = ft_lstlast(*b);
		x = tmp->content;
		ft_lstadd_front((b), ft_lstnew(x));
		tmp1->next = NULL;
		ft_lstdelone(tmp);
	}
	ft_putstr("rrb\n");
}

void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		free(lst);
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	sorttrois_b(t_list **lst)
{
	t_var	tmp;

	tmp.tmp1 = (*lst)->content;
	tmp.tmp2 = (*lst)->next->content;
	tmp.tmp3 = (*lst)->next->next->content;
	if (tmp.tmp1 > tmp.tmp2 && tmp.tmp1 > tmp.tmp3)
	{
		if (tmp.tmp3 > tmp.tmp2)
		{
			sb(lst);
			rb(lst);
		}
	}
	else if (tmp.tmp3 > tmp.tmp2 && tmp.tmp3 > tmp.tmp1)
	{
		if (tmp.tmp2 > tmp.tmp1)
			sb(lst);
		rrb(lst);
	}
	else if (tmp.tmp2 > tmp.tmp1 && tmp.tmp2 > tmp.tmp3)
	{
		if (tmp.tmp1 > tmp.tmp3)
			sb(lst);
		else if (tmp.tmp3 > tmp.tmp1)
			rb(lst);
	}
	return (0);
}
void	ss(t_list **a, t_list **b)
{
	if ((*a) && ((*a)->next) && (*b) && ((*b)->next))
	{
		sa(a);
		sb(b);
	}
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (*b)
	{
		tmp = (*b)->next;
		(*b)->next = NULL;
		ft_lstadd_front (a, ft_lstnew((*b)->content));
		(*b) = tmp;
	}
	ft_putstr("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (*a)
	{
		tmp = (*a);
		(*a) = tmp->next;
		ft_lstadd_front (b, ft_lstnew(tmp->content));
		free(tmp);
		tmp = NULL;
	}
	ft_putstr("pb\n");
}

void	sa(t_list **a)
{
	int	tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next->content;
		(*a)->next->content = (*a)->content;
		(*a)->content = tmp;
	}
	ft_putstr("sa\n");
}

int	sorttroistop_b(t_list **b)
{
	t_var	tmp;

	tmp.tmp1 = (*b)->content;
	tmp.tmp2 = (*b)->next->content;
	tmp.tmp3 = (*b)->next->next->content;
	if (tmp.tmp3 > tmp.tmp1 && tmp.tmp3 < tmp.tmp2)
	{
		if (tmp.tmp1 > tmp.tmp2)
		{
			rb(b);
			sb(b);
			rrb(b);
			sb(b);
		}
		else if (tmp.tmp2 > tmp.tmp1)
		{
			sb(b);
			rb(b);
			sb(b);
			rrb(b);
			sb(b);
		}
	}
	else if (tmp.tmp1 > tmp.tmp2 && tmp.tmp1 > tmp.tmp3)
	{
		if (tmp.tmp3 > tmp.tmp2)
		{
			rb(b);
			sb(b);
			rrb(b);
		}
	}
	else if (tmp.tmp2 > tmp.tmp1 && tmp.tmp2 > tmp.tmp3)
	{
		if (tmp.tmp1 > tmp.tmp3)
			sb(b);
		if (tmp.tmp3 > tmp.tmp1)
		{
			sb(b);
			rb(b);
			sb(b);
			rrb(b);
		}
	}
	return (0);
}

int	sort_lst(t_list *lst, int size)
{
	t_list	*tmp;
	t_list	*i;
	t_list	*j;
	int		ret;
	t_list	*lstcp;

	lstcp = ft_lstcopie(lst, size);
	tmp = lstcp;
	i = tmp;
	while (i)
	{
		j = i->next;
		while (j)
		{
			ret = i->content - j->content;
			if (ret > 0)
				ft_swap(&i->content, &j->content);
			j = j->next;
		}
		i = i->next;
	}
	return (pivot(&lstcp, size));
}

int	ft_sortabwithpivot(t_list **a, t_list **b, size_t len_a)
{
	t_list	*tmpa;
	t_var	tmp;
	size_t	i;

	tmp.ret_pb = 0;
	tmp.ret_ra = 0;
	i = -1;
	tmpa = (*a);
	tmp.pivot = sort_lst(*a, len_a);
	while (tmpa && ++i < len_a)
	{
		if ((tmpa)->content < tmp.pivot)
		{
			pb(a, b);
			tmp.ret_pb += 1;
		}
		else if ((tmpa)->content >= tmp.pivot)
		{
			ra(a);
			tmp.ret_ra += 1;
		}
		tmpa = tmpa->next;
	}
	return (sort_b(a, b, tmp.ret_ra));
}

int	sort_b(t_list	**a, t_list **b, size_t	len_b)
{
	if (len_b <= 3)
	{
		if (len_b == 2)
			sorttwob(*b);
		else if (len_b == 3)
		{
			if (ft_lstsize(*b) == 3)
				sorttrois_b(b);
			else
				sorttroistop_b(b);
		}
		return (0);
	}
	ft_sortwithpivot(a, b, len_b);
	return (0);
}
// int	sorttwo_b(t_list	*lst)
// {
// 	int	n;

// 	n = ft_lstsize(lst);
// 	if (n == 2)
// 	{
// 		if (lst->next->content > lst->content)
// 			sa(&lst);
// 	}
// 	return (0);
// }

int main ()
{
	t_list *b;
	t_list *a;
	a = NULL;
	b = NULL;
	ft_lstadd_back(&b,ft_lstnew(3));
	ft_lstadd_back(&b,ft_lstnew(2));
	ft_lstadd_back(&b,ft_lstnew(1));
	// ft_lstadd_back(&b,ft_lstnew(5));
	// ft_lstadd_back(&b,ft_lstnew(254));
	// ft_lstadd_back(&b,ft_lstnew(22));
	// ft_lstadd_back(&b,ft_lstnew(2359));
	// ft_lstadd_back(&b,ft_lstnew(236));
	// ft_lstadd_back(&b,ft_lstnew(215));
	// ft_lstadd_back(&b,ft_lstnew(221));
	// ft_lstadd_back(&b,ft_lstnew(32));
	// ft_lstadd_back(&b,ft_lstnew(54));
	// ft_lstadd_back(&b,ft_lstnew(65));
	// ft_lstadd_back(&b,ft_lstnew(3233));
	// ft_lstadd_back(&b,ft_lstnew(21));
	// ft_lstadd_back(&b,ft_lstnew(22222));
	// ft_lstadd_back(&b,ft_lstnew(89));
	// // ft_lstadd_back(&b,ft_lstnew(-565));
	sort_b(&a, &b ,4);
	printf("-----------\n");
	while (b)
	{
		printf("%d\n",b->content);
		b = b->next;
	}
}