/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:37:04 by kaboussi          #+#    #+#             */
/*   Updated: 2023/01/31 19:16:52 by kaboussi         ###   ########.fr       */
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
char	*ft_substr(char const *s, int start, int len);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
int		ft_atoi(const char *str);
void	printerror(void);
int		ft_limits(int n);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_putstr(char *s);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
int		ft_lstsize(t_list *lst);
int		sorttwo(t_list	*lst);
int		sorttrois(t_list **lst);
int		sortquatre(t_list	**lst, t_list	**b);
int		minvalue(t_list **lst, t_list **b);
void	min_value(t_list **lst);
int		sortcinq(t_list	**lst, t_list	**b);
int		duplicate(t_list *lst);
int		ft_lstsize(t_list *lst);
int		pivot(t_list	**lst, int size);
t_list	*ft_lstcopie(t_list	*lst, int	size);

#endif