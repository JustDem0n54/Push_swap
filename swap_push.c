/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:30:03 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/14 17:20:04 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_var *var)
{
	int	temp;

	if (var->a != NULL && var->a->next != NULL)
	{
		temp = var->a->i;
		var->a->i = var->a->next->i;
		var->a->next->i = temp;
	}
}

void	sb(t_var *var)
{
	int	temp;

	if (var->b != NULL && var->b->next != NULL)
	{
		temp = var->b->i;
		var->b->i = var->b->next->i;
		var->b->next->i = temp;
	}
}

void	ss(t_var *var)
{
	sa(var);
	sb(var);
}

void	pb(t_var *var)
{
	void	*temp;

	temp = NULL;
	if (var->a != NULL)
	{
		ft_lstadd_front(&var->b, ft_lstnew(var->a->i));
		temp = var->a;
		var->a = var->a->next;
		free(temp);
	}
}

void	pa(t_var *var)
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
	}
}
