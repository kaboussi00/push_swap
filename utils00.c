/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:25:40 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/12 13:20:12 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	len1;
	size_t	len2;
	char	*p;	

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!p)
		return (NULL);
	j = 0;
	while (s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	free(s1);
	return (p);
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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*p;
	int		i;

	len = ft_strlen(str);
	p = malloc(len * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = ('\0');
	return (p);
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
