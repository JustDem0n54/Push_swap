/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:14:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 18:33:41 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	var->val = NULL;
	var->size = argc - 1;
	var->rule1 = 0;
	var->rule2 = 0;
	return (var);
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
