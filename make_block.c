/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:12:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 19:15:50 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	more_than_9(t_var *var)
{
	set_mark(var);
	count_mark(var);
	make_block(var);
	sort_it(var);
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
	var->mark[var->nbg]++;
}

void	count_mark(t_var *var)
{
	int	i;
	int y;

	i = 0;
	y = 0;
	var->count = ft_calloc((var->nbg), sizeof(int));
	while (y <= var->size - 1)
	{
		if (var->val[y] >= var->mark[i] && var->val[y] < var->mark[i + 1])
		{
			var->count[i]++;
			y++;
		}
		else
			i++;
	}
}

int	check_value(t_var *var, int nb)
{
	if (var->a)
	{
		if (nb < 0)
			return (0);
		if ((var->a->i >= var->mark[nb]) && var->a->i < var->mark[nb + 1])
		{
			(var->count[nb])--;
			return (1);
		}
	}
	return (0);
}

void	make_block(t_var *var)
{
	int	i;
	int	j;

	i = var->nbg / 2;
	j = (var->nbg / 2) - 1;
	while (var->a)
	{
		if (check_value(var, i) == 1)
		{
			pb(var, 1);
			if (var->count[i] == 0)
				i++;
		}
		else if (check_value(var, j) == 1)
		{
			pb(var, 1);
			rb(var, 1);
			if (var->count[j] == 0)
				j--;
		}
		else
			ra(var, 1);
	}
}
