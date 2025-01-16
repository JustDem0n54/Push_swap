/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:22:11 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/16 17:13:25 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int		i;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_var
{
	t_list *a;
	t_list *b;
	t_list *ref;
	int *val;
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
int	ft_lstsize(t_list *lst);

# endif