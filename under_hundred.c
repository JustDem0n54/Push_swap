/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_hundred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:30:03 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 15:33:59 by nrontard         ###   ########.fr       */
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

void	pb_4_5(t_var *var, int i)
{
	while (i > 0)
	{
		if (var->size == 5
			&& (var->a->i == var->val[0] || var->a->i == var->val[1]))
		{
			pb(var);
			i--;
		}
		else if (var->size == 4 && var->a->i == var->val[0])
		{
			pb(var);
			i--;
		}
		else
			ra(var);
	}
}

void	for_4_and_5(t_var *var)
{
	int	i;

	i = 1;
	if (var->size == 5)
		i = 2;
	pb_4_5(var, i);
	for_3(var);
	if (var->size == 5 && var->b->i < var->b->next->i)
		rb(var);
	if (var->size == 5)
		pa(var);
	pa(var);
}

int	check_char(char *str, int temp)
{
	char *comp;

	comp = ft_itoa(temp);
	if (ft_strcmp(comp, str) != 0)
	{
		free(comp);
		return (1);
	}
	free(comp);
	return(0);
}