/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:46:06 by kaboussi          #+#    #+#             */
/*   Updated: 2023/01/13 20:07:56 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	{
		p[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		p[j++] = s2[i++];
	}
	return (p);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*p;
	int		i;

	len = ft_strlen(str);
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	return (p);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	n;

	s = 1;
	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			(s *= -1);
		i++;
	}
	if (str[i] < 48 || str[i] > 57)
		printerror();
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + str[i++] - 48;
	if ((str[i] < 48 || str[i] > 57) && str[i])
		printerror();
	return (ft_limits(n * s));
}

void	printerror(void)
{
	write (2, "error\n", 6);
	exit(0);
}

int	ft_limits(int n)
{
	if (n >= -2147483648 && n <= 2147483647)
		return (n);
	else
		printerror();
	return (0);
}
