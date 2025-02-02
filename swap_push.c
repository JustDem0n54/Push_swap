/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:30:03 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 19:13:57 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_var *var, int i)
{
	int	temp;

	if (var->a != NULL && var->a->next != NULL)
	{
		temp = var->a->i;
		var->a->i = var->a->next->i;
		var->a->next->i = temp;
		if (i == 1)
			ft_printf("sa\n");
	}
}

void	sb(t_var *var, int i)
{
	int	temp;

	if (var->b != NULL && var->b->next != NULL)
	{
		temp = var->b->i;
		var->b->i = var->b->next->i;
		var->b->next->i = temp;
		if (i == 1)
			ft_printf("sb\n");
	}
}

void	ss(t_var *var, int i)
{
	int	temp;

	if (var->a != NULL && var->a->next != NULL)
	{
		temp = var->a->i;
		var->a->i = var->a->next->i;
		var->a->next->i = temp;
	}
	if (var->b != NULL && var->b->next != NULL)
	{
		temp = var->b->i;
		var->b->i = var->b->next->i;
		var->b->next->i = temp;
	}
	if (i == 0)
		ft_printf("ss\n");
}

void	pb(t_var *var, int i)
{
	void	*temp;

	temp = NULL;
	if (var->a != NULL)
	{
		ft_lstadd_front(&var->b, ft_lstnew(var->a->i));
		temp = var->a;
		var->a = var->a->next;
		free(temp);
		if (i == 1)
			ft_printf("pb\n");
	}
}

void	pa(t_var *var, int i)
{
	void	*temp;

	temp = NULL;
	if (var->b != NULL)
	{
		temp = NULL;
		ft_lstadd_front(&var->a, ft_lstnew(var->b->i));
		temp = var->b;
		var->b = var->b->next;
		free(temp);
		if (i == 1)
			ft_printf("pa\n");
	}
}
