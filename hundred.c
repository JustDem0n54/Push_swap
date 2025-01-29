/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:12:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/29 17:27:14 by nrontard         ###   ########.fr       */
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
	int i;

	i = 0;
	var->count = ft_calloc((var->nbg), sizeof(int));
	while(var->ref)
	{
		if (var->ref->i >= var->mark[i] && var->ref->i < var->mark[i + 1])
		{	
			var->count[i]++;
			var->ref = var->ref->next;
		}
		else
			i++;
	}
}

int	check_value(t_var *var, int nb)
{
	if (var->a)
	{
		if ((var->a->i >= var->mark[nb]) && var->a->i < var->mark[nb + 1])
		{
			(var->count[nb])--;
			return(1);
		}
	}
	return(0);
}

void	make_block(t_var *var)
{
	int i;
	int j;

	i = var->nbg / 2;
	j = (var->nbg / 2) - 1;
	while (var->a)
	{
		if (check_value(var, i) == 1)
		{
			pb(var);
			if (var->count[i] == 0)
				i++;
		}
		if (check_value(var, j) == 1)
		{
			pb(var);
			rb(var);
			if (var->count[j] == 0)
				j--;
		}
		else
			ra(var);
	}
}

int	check_max(t_var *var, int max)
{
	int i;
	t_list *temp;
	t_list *temp2;

	i = 0;
	temp = var->b;
	temp2 = ft_lstlast(var->b);
	while (i < (var->size +1)/ 2)
	{
		if (temp->i == var->val[max])
		{
			var->rule1 = 1;
			return(i);
		}
		if (temp2->i == var->val[max])
		{
			var->rule1 = 2;
			return(1 + i);
		}
		temp = temp->next;
		temp2 = temp2->prev;
		i++;
	}
	return(0);
}

int	check_min(t_var *var, int min)
{
	int i;
	t_list *temp;
	t_list *temp2;

	i = 0;
	temp = var->b;
	temp2 = ft_lstlast(var->b);
	while (i < (var->size +1)/ 2)
	{
		if (temp->i == var->val[min])
		{
			var->rule1 = 1;
			return(i);
		}
		if (temp2->i == var->val[min])
		{
			var->rule1 = 2;
			return(1 + i);
		}
		temp = temp->next;
		temp2 = temp2->prev;
		i++;
	}
	return(0);
}

void	for_min(t_var *var, int min)
{
	int i;
	
	i = check_min(var, min);
	if (var->rule1 == 1)
	{
		while (i-- != 0)
			rb(var);
		pa(var);
		ra(var);
	}
	else if (var->rule1 == 2)
	{
		while (i-- != 0)
			rrb(var);
		pa(var);
		ra(var);
	}
}

void	for_max(t_var *var, int max)
{
	int i;

	i = check_max(var, max);
	if (var->rule1 == 1)
	{
		while (i-- != 0)
			rb(var);
		pa(var);
	}
	else if (var->rule1 == 2)
	{
		while (i-- != 0)
			rrb(var);
		pa(var);
	}
}
void	sort_it(t_var *var)
{
	int max;
	int numg;
	int min;

	numg = 0;
	while (var->b)
	{
		max = var->val[var->size - (var->nbg * numg)];
		min = var->val[var->size - (var->nbg * (numg + 1))];
		while (var->b->i >= min)
		{
			if ((check_min(var, min) + 2) < check_max(var, max))
			{
				for_min(var, min);
				min++;
			}
			else
			{
				for_max(var, max);
				max--;
			}
		}
		numg++;
	}
}
