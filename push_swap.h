/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:37:04 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/15 14:41:52 by kaboussi         ###   ########.fr       */
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
# include "get_next_line/get_next_line.h"

# define PA "pa\n"
# define PB "pb\n"
# define RB "rb\n"
# define RA "ra\n"
# define RRB "rrb\n"
# define RRA "rra\n"
# define SA "sa\n"
# define SB "sb\n"
# define RR "rr\n"
# define RRR "rrr\n"
# define SS "ss\n"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;
typedef struct s_opt
{
	char				*str;
	struct s_opt		*next;
}					t_opt;
typedef struct s_var
{
	int		j;
	char	*join;
	char	**split;
	int		j_oin;
	size_t	i;
	int		tmp1;
	int		tmp2;
	int		tmp3;
	int		tmp1b;
	int		tmp2b;
	int		tmp3b;
	int		tmp1_b;
	int		tmp2_b;
	int		tmp3_b;
	int		ret_pb;
	int		ret_ra;
	int		ret_pa;
	int		ret_rb;
	int		pivot;
}					t_var;
//utils
int		ft_strlen(const char *str);
void	*ft_memset(char *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, int start, int len);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char *s1, char const *s2);
char	*p(const char *str);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_putstr(char *s);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_swap(int *a, int *b);
char	*p(const char *str);
t_opt	*ft_last(t_opt *lst);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_lstsize(t_list *lst);
//les erreurs
int		ft_atoi(const char *str);
void	printerror(void);
int		ft_limits(long n);
int		duplicate(t_list *lst);
// les instructions
void	sa(t_list **a, t_opt **optlst);
void	sb(t_list **b, t_opt **optlst);
void	ss(t_list **a, t_list **b, t_opt **optlst);
void	pa(t_list **a, t_list **b, t_opt **optlst);
void	pb(t_list **a, t_list **b, t_opt **optlst);
void	ra(t_list **a, t_opt **optlst);
void	rb(t_list **b, t_opt **optlst);
void	rr(t_list **a, t_list **b, t_opt **optlst);
void	rra(t_list **a, t_opt **optlst);
void	rrb(t_list **b, t_opt **optlst);
void	rrr(t_list **a, t_list **b, t_opt **optlst);
//sort_functions
int		sorttwo(t_list	*lst, t_opt **optlst);
int		sortquatre(t_list **lst, t_list **b, t_opt **optlst);
int		minvalue(t_list **lst, t_list **b, t_opt **optlst);
void	min_value(t_list **lst, t_opt **optlst);
int		sortcinq(t_list	**lst, t_list	**b, t_opt **optlst);
int		pivot(t_list	**lst, int size);
int		sort_lst(t_list *lst, int size);
t_list	*ft_lstcopie(t_list	*lst, int size);
int		sorttwo_b(t_list	**lst, t_opt **optlst);
int		sorttrois(t_list **lst, t_opt **optlst);
int		sorttrois_b(t_list **lst, t_opt **optlst);
int		utilssortrois_b(t_list **lst, t_var	tmp, t_opt **optlst);
int		sorttroistop(t_list **a, t_opt **optlst);
int		utilsorttroistop(t_list **a, t_var	tmp, t_opt **optlst);
int		sorttroistop_b(t_list **b, t_opt **optlst);
int		utilssortroistop_b(t_list **b, t_var	tmp, t_opt **optlst);
int		ft_sortawithpivot(t_list **a, t_list **b, size_t len_a, t_opt **optlst);
int		ft_sortbwithpivot(t_list **a, t_list **b, size_t len_b, t_opt **optlst);
int		sort_a(t_list	**a, t_list **b, size_t	len_a, t_opt **optlst);
int		sort_b(t_list	**a, t_list **b, size_t	len_b, t_opt **optlst);
int		back_to_a(t_list **a, t_list **b, int k, t_opt **optlst);
int		back_to_b(t_list **a, t_list **b, int k, t_opt **optlst);
int		rr_a(t_list **a, t_var tmp, t_opt **optlst);
int		rr_b(t_list **b, t_var tmp, t_opt **optlst);
void	prt_opt(t_opt	*optlst);
int		check_sort(t_list *a);
// optimisation_replace
void	ft_addback(t_opt **lst, t_opt *new);
t_opt	*lstnewstr(char *str);
int		ft_replace_rrr(t_opt	**lst);
int		ft_replace_ss(t_opt **lst);
int		ft_replace_rr(t_opt **lst);
void	opt_replace(t_opt **lst);
// optimisation_delet
int		ft_del_pa_pb(t_opt	**lst);
int		ft_del_sa_sb(t_opt	**lst);
int		ft_del_ra_rra(t_opt	**lst);
int		ft_del_rb_rrb(t_opt	**lst);
void	opt_delete(t_opt **lst);
//free functions
void	free_lst(t_list *lst);
void	free_opt(t_opt *lst);
char	**ft_free(char **sp);
void	del(t_opt *lst);
int		ft_dellst(t_list *lst);
void	ft_freee(t_list **a, t_list **b, t_opt **optlst, t_var v);

#endif