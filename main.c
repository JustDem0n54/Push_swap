/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:14:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/20 16:20:54 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	n;

	res = 0;
	n = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (n * res);
}

int	ft_lstadd_ref(t_list **lst, t_list *new)
{
	t_list	*l;
	
	if (*lst == NULL)
		return(ft_lstadd_back(lst, new), 1);
	if (new->i < (*lst)->i)
		return(ft_lstadd_front(lst, new), 1);
	l = (*lst);
	while (l)
	{
		if (new->i > l->i && l->next == NULL)
		{
			l->next = new;
			new->next = NULL;
			return (1);
		}
		if (l->i < new->i && (l->next->i > new->i || l->next == NULL))
			return (new->next = l->next, l->next = new, 1);
		if (new->i == l->i)
			return(2);
		l = l->next;
	}
	return (0);
}

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

void	set_bounds(t_var *var)
{
	int	i;

	i = 0;
	var->mark = ft_calloc(var->nbg + 1, sizeof(int));
	while (i <= var->nbg)
	{
		var->mark[i] = var->val[(var->size - 1) * i / var->nbg];
		i++;
	}
	var->mark[var->nbg];
}

void	make_block(t_var *var)
{
	int size;
	int i;
	int count;
	
	size = ft_lstsize(var->a);
	i = size / 10;
	count = 0;
	while (var->a)
	{
		if (count == 20)
		{
			i = i + (size / 10);
			count = 0;
			if (i >= 50)
				return ;
		}
		else if (var->a->i >= var->val[size / 2] && var->a->i <= var->val[(size / 2) + i])
		{	
			pb(var);
			count++;
			ft_printf("%dcheck", i);
		}
		else if (var->a->i >= var->val[(size / 2) - i] && var->a->i < var->val[(size / 2)])
		{
			count++;
			pb(var);
			rb(var);
			ft_printf("%dcheck", i);
		}
		else
			ra(var);
	}
}

void	init_val(t_var *var, int argc)
{
	var = malloc(sizeof(t_var) * 1);
	var->a = NULL;
	var->b = NULL;
	var->ref = NULL;
	var->nbg = 0;
	var->mark = 0;
	var->size = argc - 1;
}

void	by_size(t_var *var)
{
	if (var->size == 2)
		for_2(var);
}

int	main(int argc, char **argv)
{
	t_var	*var;
	
	if (argc > 2)
	{
		init_val(var, argc);
		if (init_list(var, argc, argv) == 1)
			return (0);
		by_size(var);
	}
	if (init_list(var, argc, argv) == 1)
		return (0);
	if (argc == 3)
		for_2(var);
	make_block(var);
	// ft_printf("\n");
	while (var->b)
	{
		ft_printf("%d\n", var->b->i);
		var->b = var->b->next;
	}
	return (0);
}
