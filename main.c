/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:14:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/16 17:19:03 by nrontard         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_var	*var;
	void	*tem;
	int		i;

	var = malloc(sizeof(t_var) * 1);
	var->a = NULL;
	var->b = NULL;
	var->ref = NULL;
	tem = NULL;
	i = 0;
	if (init_list(var, argc, argv) == 1)
		return (0);
	while (var->ref)
	{
		ft_printf("%d\n", var->ref->i);
		var->ref = var->ref->next;
	}
	ft_printf("\n");
	while (i < ft_lstsize(var->a))
	{
		ft_printf("%d\n", var->val[i]);
		i++;
	}
	return (0);
}
