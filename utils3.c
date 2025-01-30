/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:46:11 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 16:47:05 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_array(t_var *var)
{
	int i;
	t_list	*temp2;
	
	i = 0;
	var->val = malloc(sizeof(int) * ft_lstsize(var->ref));
	temp2 = var->ref;
	while (temp2)
	{
		var->val[i] = temp2->i;
		temp2 = temp2->next;
		i++;
	}
}

int	init_list(t_var *var, int argc, char **argv)
{
	int		i;
	int		temp;
	t_list	*e;

	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(argv[i]);
		if (check_char(argv[i], temp) == 1)
			return(ft_error(), 1);
		ft_lstadd_back(&(var->a), ft_lstnew(temp));
		e = ft_lstnew(temp);
		if (ft_lstadd_ref(&(var->ref), e) == 2)
			return (free(e), ft_error(), 1);
		i++;
	}
	init_array(var);
	return (0);
}

void	by_size(t_var *var)
{
	if (var->size == 2)
		for_2(var);
	else if (var->size == 3)
		for_3(var);
	else if (var->size == 4 || var->size == 5)
		for_4_and_5(var);
	else if (var->size < 100)
	{
		var->nbg = 5;
		more_than_9(var);
	}
	else if (var->size >= 100 && var->size < 500)
	{
		var->nbg = 8;
		more_than_9(var);
	}
	else if (var->size >= 500)
	{
		var->nbg = 14;
		more_than_9(var);
	}
}

int	check_list(t_var *var)
{
	t_list	*temp;

	temp = var->a;
	while (temp->next)
	{
		if (temp->i > temp->next->i)
			return (1);
		temp = temp->next;
	}
	return (0);
}