/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:28:16 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 19:13:44 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_var *var, int i)
{
	t_list	*temp;
	t_list	*temp2;

	temp = NULL;
	temp2 = NULL;
	if (var->a != NULL && var->a->next != NULL)
	{
		temp = var->a;
		var->a = var->a->next;
		temp2 = ft_lstlast(var->a);
		temp2->next = temp;
		temp->next = NULL;
		temp->prev = temp2;
		var->a->prev = NULL;
		if (i == 1)
			ft_printf("ra\n");
	}
}

void	rb(t_var *var, int i)
{
	t_list	*temp;
	t_list	*temp2;

	temp = NULL;
	temp2 = NULL;
	if (var->b != NULL && var->b->next != NULL)
	{
		temp = var->b;
		var->b = var->b->next;
		temp2 = ft_lstlast(var->b);
		temp2->next = temp;
		temp->next = NULL;
		temp->prev = temp2;
		var->b->prev = NULL;
		if (i == 1)
			ft_printf("rb\n");
	}
}

void	rr(t_var *var, int i)
{
	t_list	*temp;
	t_list	*temp2;

	temp = NULL;
	temp2 = NULL;
	if ((var->a != NULL && var->a->next != NULL)
		&& (var->b != NULL && var->b->next != NULL))
	{
		temp = var->a;
		var->a = var->a->next;
		temp2 = ft_lstlast(var->a);
		temp2->next = temp;
		temp->next = NULL;
		temp->prev = temp2;
		var->a->prev = NULL;
		temp = var->b;
		var->b = var->b->next;
		temp2 = ft_lstlast(var->b);
		temp2->next = temp;
		temp->next = NULL;
		temp->prev = temp2;
		var->b->prev = NULL;
		if (i == 1)
			ft_printf("rr\n");
	}
}
