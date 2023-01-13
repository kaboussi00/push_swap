/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:37:04 by kaboussi          #+#    #+#             */
/*   Updated: 2023/01/13 20:13:00 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h> 
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;
int		ft_strlen(const char *str);
void	*ft_memset(char *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
int		ft_atoi(const char *str);
void	printerror(void);
int		ft_limits(int n);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif