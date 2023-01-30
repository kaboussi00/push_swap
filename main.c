#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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

void	printerror(void)
{
	write (2, "error\n", 6);
	exit(0);
}

int	sort_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*i;
	t_list	*j;
	int		ret;

	tmp = *lst;
	i = tmp;
	j = tmp->next;
	while (i)
	{
		j = i->next;
		while (j)
		{
			ret = i->content - j->content;
			if (ret > 0)
				ft_swap(&i->content, &j->content);
			else if (ret == 0)
				printerror();
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	pivot(t_list	**lst, int size)
{
	t_list	*tmp;
	int		index;
	int		i;
	int		j;
	t_list	*pivot;

	tmp = *lst;
	j = 1;
	sort_lst(&tmp);
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

int main ()
{
	t_list *b;
	b = NULL;
	ft_lstadd_back(&b,ft_lstnew(29));
	ft_lstadd_back(&b,ft_lstnew(9));
	ft_lstadd_back(&b,ft_lstnew(1));
	ft_lstadd_back(&b,ft_lstnew(5));
	ft_lstadd_back(&b,ft_lstnew(254));
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
	// ft_lstadd_back(&b,ft_lstnew(-565));
	printf("%d\n",pivot(&b,4));
	// while (b)
	// {
	// 	printf("%d\n",b->content);
	// 	b = b->next;
	// }
}