/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:52:02 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 19:13:34 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_var *var, int i)
{
	t_list	*temp;

	if (var->a != NULL && var->a->next != NULL)
	{
		temp = ft_lstlast(var->a);
		temp->next = var->a;
		temp->prev->next = NULL;
		temp->prev = NULL;
		var->a->prev = temp;
		var->a = temp;
		if (i == 1)
			ft_printf("rra\n");
	}
}

void	rrb(t_var *var, int i)
{
	t_list	*temp;

	if (var->b != NULL && var->b->next != NULL)
	{
		temp = ft_lstlast(var->b);
		temp->next = var->b;
		temp->prev->next = NULL;
		temp->prev = NULL;
		var->b->prev = temp;
		var->b = temp;
		if (i == 1)
			ft_printf("rrb\n");
	}
}

void	rrr(t_var *var, int i)
{
	t_list	*temp;

	if (var->b != NULL && var->b->next != NULL)
	{
		temp = ft_lstlast(var->b);
		temp->next = var->b;
		temp->prev->next = NULL;
		temp->prev = NULL;
		var->b->prev = temp;
		var->b = temp;
	}
	if (var->a != NULL && var->a->next != NULL)
	{
		temp = ft_lstlast(var->a);
		temp->next = var->a;
		temp->prev->next = NULL;
		temp->prev = NULL;
		var->a->prev = temp;
		var->a = temp;
	}
	if (i == 1)
		ft_printf("rrr\n");
}
