/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:12:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/22 17:14:22 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	more_than_9(t_var *var)
{
	set_mark(var);
	count_mark(var);
	make_block(var);
}

void	set_mark(t_var *var)
{
	int	i;

	i = 0;
	var->mark = ft_calloc(var->nbg + 1, sizeof(int));
	while (i <= var->nbg)
	{
		var->mark[i] = var->val[(var->size - 1) * i / var->nbg];
		i++;
	}
}

void	count_mark(t_var *var)
{
	int i;

	i = 0;
	var->count = ft_calloc((var->nbg), sizeof(int));
	while(var->ref)
	{
		if (var->ref->i >= var->mark[i] && var->ref->i <= var->mark[i + 1])
			var->count[i]++;
		else
			i++;
		var->ref = var->ref->next;
	}
}

void	make_block(t_var *var)
{
	int i;
	int j;

	i = var->nbg / 2;
	j = (var->nbg / 2) - 1;
	while (i < var->nbg)
	{
		if (var->a->i >= var->mark[i] && var->a->i <= var->mark[i + 1])
		{
			pb(var);
			var->count[i]--;
			if (var->count[i] == 0)
				i++;
		}
		if (var->a->i >= var->mark[j] && var->a->i < var->mark[j + 1])
		{
			pb(var);
			rb(var);
			var->count[j]--;
			if (var->count[j] == 0)
				j--;
		}
		else
			ra(var);
	}
}