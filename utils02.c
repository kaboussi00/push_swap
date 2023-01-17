/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:55:37 by kaboussi          #+#    #+#             */
/*   Updated: 2023/01/16 15:51:25 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_calcul_mot(char const *s, char c)
{
	int	i;
	int	ret;
	int	calcul;

	i = 0;
	ret = 0;
	calcul = 0;
	while (s[i])
	{
		if (s[i] != c && calcul == 0)
		{
			calcul = 1;
			ret++;
		}
		else if (s[i] == c)
			calcul = 0;
		i++;
	}
	return (ret);
}

static char	**ft_free(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	return (NULL);
}

static char	**ft_print(const char *s, char **sp, char c)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j != 0)
			sp[k++] = ft_substr(s, i, j);
		if (j != 0 && !sp[k - 1])
			return (ft_free(sp));
		i += j;
	}
	return (sp);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = ft_calloc(ft_calcul_mot(s, c) + 1, sizeof(char *));
	if (!p)
		return (NULL);
	p = ft_print(s, p, c);
	return (p);
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
