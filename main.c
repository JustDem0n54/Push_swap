/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:14:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/22 17:24:46 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_list(t_var *var, int argc, char **argv)
{
	int	i;
	int	temp;
	t_list	*mem;

	i = 1;
	temp = 0;
	while (i < argc)
	{
		temp = ft_atoi(argv[i]);
		ft_lstadd_back(&(var->a), ft_lstnew(temp));
		if (ft_lstadd_ref(&(var->ref), ft_lstnew(temp)) == 2)
			return(1);
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

void	for_2(t_var *var)
{
	if (var->a->next->i < var->a->i)
		ra(var);
}

t_var	*init_val(int argc)
{
	t_var *var;

	var = malloc(sizeof(t_var) * 1);
	var->a = NULL;
	var->b = NULL;
	var->ref = NULL;
	var->nbg = 0;
	var->mark = 0;
	var->count = 0;
	var->size = argc - 1;
	return (var);
}

void	by_size(t_var *var)
{
	if (var->size == 2)
		for_2(var);
	// if (var->size > 2 && var->size < 10)
	// 	for_3_or_more(var);
	if (var->size > 9 && var->size < 100)
	{
		var->nbg = 5;
		more_than_9(var);
	}
	if (var->size >= 100 && var->size < 500)
	{
		var->nbg = 8;
		more_than_9(var);
	}
	if (var->size >= 500)
	{
		var->nbg = 16;
		more_than_9(var);
	}
}

void	for_3_or_more(t_var *var)
{
	
}

int	main(int argc, char **argv)
{
	t_var	*var;
	
	var = NULL;
	if (argc > 2)
	{
		var = init_val(argc);
		if (init_list(var, argc, argv) == 1)
			return (0);
		by_size(var);
	}
	while (var->b)
	{
		ft_printf("%d\n", var->b->i);
		var->b = var->b->next;
	}
	ft_printf("\n");
	while (var->a)
	{
		ft_printf("%d\n", var->a->i);
		var->a = var->a->next;
	}
	return (0);
}
