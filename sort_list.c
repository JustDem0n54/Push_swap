/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:04:40 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 19:11:37 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_pose(t_var *var, int nb)
{
	int		i;
	t_list	*temp;
	t_list	*temp2;

	i = 0;
	temp = var->b;
	temp2 = ft_lstlast(var->b);
	while (i < (var->size +1) / 2)
	{
		if (temp->i == var->val[nb])
		{
			var->rule1 = 1;
			return (i);
		}
		if (temp2->i == var->val[nb])
		{
			var->rule1 = 2;
			return (1 + i);
		}
		temp = temp->next;
		temp2 = temp2->prev;
		i++;
	}
	return (0);
}

void	for_min(t_var *var, int min)
{
	int	i;

	i = check_pose(var, min);
	if (var->rule1 == 1)
	{
		while (i-- != 0)
			rb(var, 1);
		pa(var, 1);
		ra(var, 1);
	}
	else if (var->rule1 == 2)
	{
		while (i-- != 0)
			rrb(var, 1);
		pa(var, 1);
		ra(var, 1);
	}
}

void	for_max(t_var *var, int max)
{
	int	i;

	i = check_pose(var, max);
	if (var->rule1 == 1)
	{
		while (i-- != 0)
			rb(var, 1);
		pa(var, 1);
	}
	else if (var->rule1 == 2)
	{
		while (i-- != 0)
			rrb(var, 1);
		pa(var, 1);
	}
}

int	define_pose(t_var *var, int nbg)
{
	int	i;

	i = 0;
	if (nbg < 0)
		return (0);
	while (var->val[i] <= var->mark[nbg])
	{
		if (i == var->size - 1)
			return (var->size);
		i++;
	}
	return (i);
}

void	sort_it(t_var *var)
{
	int	max;
	int	nbg;
	int	min;

	nbg = var->nbg;
	while (var->b)
	{
		max = define_pose(var, nbg) - 1;
		min = define_pose(var, nbg - 1);
		while (max >= min)
		{
			if ((check_pose(var, min) + 2) <= check_pose(var, max))
				for_min(var, min++);
			else
				for_max(var, max--);
		}
		while (check_list(var) == 1)
			rra(var, 1);
		nbg--;
	}
}
