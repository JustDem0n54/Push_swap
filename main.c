/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:14:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 15:34:18 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_list(t_var *var, int argc, char **argv)
{
	int		i;
	int		temp;
	t_list	*mem;

	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(argv[i]);
		if (check_char(argv[i], temp) == 1)
			return(ft_error(), 1);
		ft_lstadd_back(&(var->a), ft_lstnew(temp));
		if (ft_lstadd_ref(&(var->ref), ft_lstnew(temp)) == 2)
			return (ft_error(), 1);
		i++;
	}
	i = 0;
	var->val = malloc(sizeof(int) * ft_lstsize(var->ref));
	mem = var->ref;
	while (mem)
	{
		var->val[i] = mem->i;
		mem = mem->next;
		i++;
	}
	return (0);
}

t_var	*init_val(int argc)
{
	t_var	*var;

	var = malloc(sizeof(t_var) * 1);
	var->a = NULL;
	var->b = NULL;
	var->ref = NULL;
	var->nbg = 0;
	var->mark = 0;
	var->count = 0;
	var->size = argc - 1;
	var->rule1 = 0;
	var->rule2 = 0;
	return (var);
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

int	main(int argc, char **argv)
{
	t_var	*var;

	var = NULL;
	if (argc >= 2)
	{
		var = init_val(argc);
		if (init_list(var, argc, argv) == 1)
		{
			ft_free(var);
			return (0);
		}
		if (check_list(var) == 1)
			by_size(var);
		ft_free(var);
	}
	return (0);
}
