/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_hundred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:30:03 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/29 11:02:06 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_2(t_var *var)
{
	if (var->a->next->i < var->a->i)
		ra(var);
}

void	for_3(t_var *var)
{
	if (var->a->next->i > ft_lstlast(var->a)->i && var->a->i < var->a->next->i)
	{
		rra(var);
		if (var->a->i > var->a->next->i)
			sa(var);
	}
	else if (var->a->i > var->a->next->i && var->a->i > ft_lstlast(var->a)->i)
	{
		ra(var);
		if (var->a->i > var->a->next->i)
			sa(var);
	}
	else if (var->a->i < ft_lstlast(var->a)->i
			&& var->a->next->i < ft_lstlast(var->a)->i)
	{
		if (var->a->i > var->a->next->i)
			sa(var);
	}
}

void	for_4_and_5(t_var *var)
{
	int i;
	
	i = 1;
	if (var->size == 5)
		i = 2;
	while (i > 0)
	{
		if (var->a->i == var->val[0] || var->a->i == var->val[1])
		{
			pb(var);
			i--;
		}
		else
			ra(var);
	}
	for_3(var);
	if (var->b->i < var->b->next->i)
		rb(var);
	pa(var);
	pa(var);
}
