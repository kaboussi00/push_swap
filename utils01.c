/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:28:25 by kaboussi          #+#    #+#             */
/*   Updated: 2023/01/16 15:58:00 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	p = malloc(n * size);
	if (!p)
		return (NULL);
	ft_bzero(p, n * size);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(char *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*ptr = c;
		ptr++;
		i++;
	}
	return (s);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, int start, int len)
{
	char			*p;
	int				i;

	i = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		p = ft_calloc(len + 1, sizeof(char));
		if (!p)
			return (NULL);
		while (i < len)
			p[i++] = s[start++];
	}
	else
		p = malloc(1);
	if (!p)
		return (p);
	p[i] = '\0';
	return (p);
}
