/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:14:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/14 17:55:24 by nrontard         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		i;
	int		temp;
	t_var	*var;
	void	*tem;

	var = malloc(sizeof(t_var) * 1);
	var->a = NULL;
	var->b = NULL;
	tem = NULL;
	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(argv[i]);
		ft_lstadd_back(&(var->a), ft_lstnew(temp));
		i++;
	}
	while (var->a)
	{
		ft_printf("%d\n", var->a->i);
		var->a = var->a->next;
	}
	ft_printf("\n");
	while (var->b)
	{
		ft_printf("%d\n", var->b->i);
		var->b = var->b->next;
	}
}
