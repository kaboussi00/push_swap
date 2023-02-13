#include "push_swap.h"

// void	ft_swap(int *a, int *b)
// {
// 	int	tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

// int	ft_lstsize(t_list *lst)
// {
// 	int	size;

// 	size = 0;
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		size++;
// 	}
// 	return (size);
// }

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

// int	pivot(t_list	**lst, int size)
// {
// 	t_list	*tmp;
// 	int		index;
// 	int		i;
// 	int		j;
// 	t_list	*pivot;

// 	tmp = *lst;
// 	j = 1;
// 	size = ft_lstsize(tmp);
// 	i = size / 2 ;
// 	if (size % 2 == 0)
// 		index = i;
// 	else
// 		index = i + 1;
// 	while (j != index)
// 	{
// 		tmp = tmp->next;
// 		j++;
// 	}
// 	return (tmp->content);
// }

// // int	sort_lst(t_list *lst, int	size)
// // {
// // 	t_list	*tmp;
// // 	t_list	*i;
// // 	t_list	*j;
// // 	int		ret;
// // 	int		lstcopie;

// // 	ft_lstcopie(&lstcopie, size);
// // 	tmp = lstcopie;
// // 	i = tmp;
// // 	while (i)
// // 	{
// // 		j = i->next;
// // 		while (j)
// // 		{
// // 			ret = i->content - j->content;
// // 			if (ret > 0)
// // 				ft_swap(&i->content, &j->content);
// // 			else if (ret == 0)
// // 				printerror();
// // 			j = j->next;
// // 		}
// // 		i = i->next;
// // 	}
// // 	return (pivot(&lstcopie, size));
// // }

// t_list	*ft_lstcopie(t_list	*lst, int size)
// {
// 	t_list	*lstcopie;
// 	t_list	*tmp;
// 	int		ret;

// 	ret = 0;
// 	tmp = lst;
// 	lstcopie = NULL;
// 	if (!size)
// 		exit(0);
// 	while (tmp && ret < size)
// 	{
// 		ft_lstadd_back(&lstcopie, ft_lstnew(tmp->content));
// 		tmp = tmp->next;
// 		ret++;
// 	}
// 	return (lstcopie);
// }

// int	sort_lst(t_list *lst, int	size)
// {
// 	t_list	*tmp;
// 	t_list	*i;
// 	t_list	*j;
// 	int		ret;
// 	t_list	*lstcp;

// 	lstcp = ft_lstcopie(lst, size);
// 	tmp = lstcp;
// 	i = tmp;
// 	while (i)
// 	{
// 		j = i->next;
// 		while (j)
// 		{
// 			ret = i->content - j->content;
// 			if (ret > 0)
// 				ft_swap(&i->content, &j->content);
// 			j = j->next;
// 		}
// 		i = i->next;
// 	}
// 	return (pivot(&lstcp, size));
// }


// void	printerror(void)
// {
// 	write (2, "error\n", 6);
// 	exit(0);
// }

int	sorttroistop(t_list **a, t_list **b, size_t len_a)
{
	t_var	tmp;

	tmp.tmp1 = (*a)->content;
	tmp.tmp2 = (*a)->next->content;
	tmp.tmp3 = (*a)->next->next->content;
	if (tmp.tmp3 > tmp.tmp1 && tmp.tmp3 > tmp.tmp2)
		if (tmp.tmp1 > tmp.tmp2)
			sa(a);
	else if (tmp.tmp1 > tmp.tmp2 && tmp.tmp1 > tmp.tmp3)
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
		if (tmp.tmp2 > tmp.tmp3)
			sa(a);
	}
	else if (tmp.tmp2 > tmp.tmp1 && tmp.tmp2 > tmp.tmp3)
	{
		ra(a);
		sa(a);
		rra(a);
		if (tmp.tmp1 > tmp.tmp3)
			sa(a);
	}
}


int main ()
{
	t_list *b;
	b = NULL;
	ft_lstadd_back(&b,ft_lstnew(29));
	ft_lstadd_back(&b,ft_lstnew(9));
	ft_lstadd_back(&b,ft_lstnew(1));
	ft_lstadd_back(&b,ft_lstnew(5));
	ft_lstadd_back(&b,ft_lstnew(254));
	ft_lstadd_back(&b,ft_lstnew(22));
	ft_lstadd_back(&b,ft_lstnew(2359));
	ft_lstadd_back(&b,ft_lstnew(236));
	ft_lstadd_back(&b,ft_lstnew(215));
	ft_lstadd_back(&b,ft_lstnew(221));
	ft_lstadd_back(&b,ft_lstnew(32));
	ft_lstadd_back(&b,ft_lstnew(54));
	ft_lstadd_back(&b,ft_lstnew(65));
	ft_lstadd_back(&b,ft_lstnew(3233));
	ft_lstadd_back(&b,ft_lstnew(21));
	ft_lstadd_back(&b,ft_lstnew(22222));
	ft_lstadd_back(&b,ft_lstnew(89));
	// ft_lstadd_back(&b,ft_lstnew(-565));
	printf("%d\n",sort_troistop(b,4));
	printf("-----------\n");
	while (b)
	{
		printf("%d\n",b->content);
		b = b->next;
	}
}