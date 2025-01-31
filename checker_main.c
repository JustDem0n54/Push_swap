/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:51:24 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/31 16:02:49 by nrontard         ###   ########.fr       */
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
			return (ft_lstclear_check(&var->inst), ft_free(var), 1);
		stock_instruction(var);
		if (do_instruction(var) == 1)
			return (ft_lstclear_check(&var->inst), ft_free(var), 1);
		if (check_list(var) == 0 && var->b == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_lstclear_check(&var->inst);
		ft_free(var);
	}
}
