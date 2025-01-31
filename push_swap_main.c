/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:14:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/31 11:25:39 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
