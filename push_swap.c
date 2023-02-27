/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:41:33 by kaboussi          #+#    #+#             */
/*   Updated: 2023/02/27 20:18:24 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int ac, char **av)
// {
// 	int		j;
// 	char	*join;
// 	char	**split;
// 	t_list	*a;
// 	t_list	*b;
// 	t_opt	*optlst;

// 	b = NULL;
// 	optlst = NULL;
// 	j = 1;
// 	join = ft_strdup("");
// 	if (ac == 1)
// 		return (0);
// 	else if (ac > 2)
// 	{
// 		while (ac > j)
// 		{
// 			join = ft_strjoin(join, ft_strjoin(av[j], " "));
// 			j++;
// 		}
// 		split = ft_split(join, ' ');
// 		j = 0;
// 		while (split[j])
// 			ft_lstadd_back(&a, ft_lstnew(ft_atoi(split[j++])));
// 		duplicate(a);
// 		if (j == 2)
// 			sorttwo(a, &optlst);
// 		else if (j == 3)
// 			sorttrois(&a, &optlst);
// 		else if (j == 4)
// 			sortquatre(&a, &b, &optlst);
// 		else if (j == 5)
// 			sortcinq(&a, &b, &optlst);
// 		if (j > 5)
// 			sort_a(&a, &b, j, &optlst);
// 		// puts("stack_a");
// 		// while (a)
// 		// {
// 		// 	printf("%d\n", a->content);
// 		// 	a = a->next;
// 		// }
// 		// puts("stack_b");
// 		// while (b)
// 		// {
// 		// 	printf("%d\n", b->content);
// 		// 	b = b->next;
// 		// }
// 	}
// }

int	main(int ac, char **av)
{
	int		j;
	int		k;
	char	*join;
	char	**split;
	t_list	*a;
	t_list	*b;
	t_opt	*optlst;

	optlst = NULL;
	b = NULL;
	j = 1;
	k = 0;
	join = ft_strdup("");

	if (ac == 1)
		return (0);
	else if (ac > 2)
	{
		while (ac > j)
		{
			join = ft_strjoin(join, ft_strjoin(av[j], " "));
			j++;
		}
		split = ft_split(join, ' ');
		while (split[k])
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(split[k++])));
		duplicate(a);
		sort_a(&a, &b, k, &optlst);
		while (optlst)
		{
			printf("%s", optlst->str);
			optlst = optlst->next;
		}
		// puts("stack_a");
		// while (a)
		// {
		// 	printf("%d\n", a->content);
		// 	a = a->next;
		// }
		// puts("stack_b");
		// while (b)
		// {
		// 	printf("%d\n", b->content);
		// 	b = b->next;
		// }
	}
}
