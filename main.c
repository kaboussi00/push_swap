#include "push_swap.h"

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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ra(t_list **a)
{
	t_list	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a);
		(*a) = tmp->next;
		ft_lstadd_back(a, ft_lstnew(tmp->content));
		free(tmp);
		tmp = NULL;
	}
	ft_putstr("ra\n");
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		free(lst);
	}
}

int	sorttwo_b(t_list	*lst)
{
	int	n;

	n = ft_lstsize(lst);
	if (n == 2)
	{
		if (lst->next->content > lst->content)
			sb(&lst);
	}
	return (0);
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
void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		x;

	tmp1 = *a;
	if ((*a) && (*a)->next)
	{
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp = ft_lstlast(*a);
		x = tmp->content;
		ft_lstadd_front((a), ft_lstnew(x));
		tmp1->next = NULL;
		ft_lstdelone(tmp);
	}
	ft_putstr("rra\n");
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

	tmp.tmp1b = (*b)->content;
	tmp.tmp2b = (*b)->next->content;
	tmp.tmp3b = (*b)->next->next->content;
	if (tmp.tmp3b > tmp.tmp1b && tmp.tmp3b > tmp.tmp2b)
	{
		if (tmp.tmp2b > tmp.tmp1b)
			sb(b);
		rb(b);
		sb(b);
		rrb(b);
		sb(b);
	}
	else if (tmp.tmp1b > tmp.tmp2b && tmp.tmp1b > tmp.tmp3b)
	{
		if (tmp.tmp3b > tmp.tmp2b)
		{
			rb(b);
			sb(b);
			rrb(b);
		}
	}
	else if (tmp.tmp2b > tmp.tmp1b && tmp.tmp2b > tmp.tmp3b)
	{
		sb(b);
		if (tmp.tmp3b > tmp.tmp1b)
		{
			rb(b);
			sb(b);
			rrb(b);
		}
	}
	return (0);
}

t_list	*ft_lstcopie(t_list	*lst, int size)
{
	t_list	*lstcopie;
	t_list	*tmp;
	int		ret;

	ret = 0;
	tmp = lst;
	lstcopie = NULL;
	if (!size)
		exit(0);
	while (tmp && ret < size)
	{
		ft_lstadd_back(&lstcopie, ft_lstnew(tmp->content));
		tmp = tmp->next;
		ret++;
	}
	return (lstcopie);
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

int	pivot(t_list	**lst, int size)
{
	t_list	*tmp;
	int		index;
	int		i;
	int		j;

	tmp = *lst;
	j = 1;
	size = ft_lstsize(tmp);
	i = size / 2 ;
	if (size % 2 == 0)
		index = i;
	else
		index = i + 1;
	while (j != index)
	{
		tmp = tmp->next;
		j++;
	}
	return (tmp->content);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (*b)
	{
		tmp = (*b);
		(*b) = tmp->next;
		ft_lstadd_front (a, ft_lstnew(tmp->content));
		free(tmp);
		tmp = NULL;
	}
	ft_putstr("pa\n");
}

int	ft_sortbwithpivot(t_list **b, t_list **a, size_t len_b)
{
	t_list	*tmpb;
	t_var	tmp;
	size_t	i;

	tmp.ret_pa = 0;
	tmp.ret_rb = 0;
	i = -1;
	tmpb = (*b);
	tmp.pivot = sort_lst(*b, len_b);
	while (tmpb && ++i < len_b)
	{
		if ((tmpb)->content >= tmp.pivot)
		{
			pa(a, b);
			tmp.ret_pa += 1;
		}
		else if ((tmpb)->content < tmp.pivot)
		{
			rb(b);
			tmp.ret_rb += 1;
		}
		tmpb = tmpb->next;
	}
	return (sort_b(b, a, tmp.ret_rb), sort_a(a, b, tmp.ret_pa));
}

int	sort_b(t_list	**b, t_list **a, size_t	len_b)
{
	if (len_b <= 3)
	{	
		if (len_b == 2)
			sorttwo_b(*b);
		else if (len_b == 3)
		{
			if (ft_lstsize(*b) == 3)
				sorttrois_b(b);
			else
				sorttroistop_b(b);
		}
		return (0);
	}
	ft_sortbwithpivot(b, a, len_b);
	return (0);
}


int main ()
{
	t_list *b;
	t_list *a;
	a = NULL;
	b = NULL;
	ft_lstadd_back(&b,ft_lstnew(1));
	ft_lstadd_back(&b,ft_lstnew(2));
	ft_lstadd_back(&b,ft_lstnew(3));
	ft_lstadd_back(&b,ft_lstnew(0));
	ft_lstadd_back(&b,ft_lstnew(4));
	ft_lstadd_back(&b,ft_lstnew(7));
	ft_lstadd_back(&b,ft_lstnew(5));
	// ft_lstadd_back(&a,ft_lstnew(6));
	// ft_lstadd_back(&a,ft_lstnew(215));
	// ft_lstadd_back(&a,ft_lstnew(221));
	// ft_lstadd_back(&a,ft_lstnew(32));
	// ft_lstadd_back(&a,ft_lstnew(54));
	// ft_lstadd_back(&a,ft_lstnew(65));
	// ft_lstadd_back(&a,ft_lstnew(3233));
	// ft_lstadd_back(&a,ft_lstnew(21));
	// ft_lstadd_back(&a,ft_lstnew(22222));
	// ft_lstadd_back(&a,ft_lstnew(89));
	// ft_lstadd_back(&b,ft_lstnew(-565));
	sort_b(&b, &a, 7);
	printf("-----------\n");
	puts("list b");
	while (b)
	{
		printf("%d\n",b->content);
		b = b->next;
	}
	puts("list a");
	while (a)
	{
		printf("%d\n",a->content);
		a = a->next;
	}
}