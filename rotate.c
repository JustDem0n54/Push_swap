/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:28:16 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/16 13:37:42 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_var *var)
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
	}
}

void	rb(t_var *var)
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
	}
}

void	rr(t_var *var)
{
	ra(var);
	rb(var);
}
