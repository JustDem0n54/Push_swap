/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:22:11 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 15:34:36 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int				i;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_var
{
	t_list	*a;
	t_list	*b;
	t_list	*ref;
	int		*val;
	int		nbg;
	int		*mark;
	int		size;
	int		*count;
	int		rule1;
	int		rule2;
}	t_var;

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int a);
void	sa(t_var *var);
void	sb(t_var *var);
void	ss(t_var *var);
void	ra(t_var *var);
void	rb(t_var *var);
void	rr(t_var *var);
void	pb(t_var *var);
void	pa(t_var *var);
void	rra(t_var *var);
void	rrb(t_var *var);
void	rrr(t_var *var);
int		ft_lstsize(t_list *lst);
void	make_block(t_var *var);
void	count_mark(t_var *var);
void	more_than_9(t_var *var);
void	set_mark(t_var *var);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_lstadd_ref(t_list **lst, t_list *new);
void	for_3(t_var *var);
void	for_4_and_5(t_var *var);
void	for_2(t_var *var);
void	inesert_after_1(t_var *var);
void	inesert_before_last(t_var *var);
void	sort_it(t_var *var);
int		check_distance(t_var *var, int max);
int		check_list(t_var *var);
void	ft_lstclear(t_list **lst);
void	pb_4_5(t_var *var, int i);
char	*ft_itoa(int n);
size_t	ft_strlenint(long n);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_error(void);
void	ft_free(t_var *var);
int		check_char(char *str, int temp);

#endif