/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:54:03 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/31 16:01:20 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	(*detect_entries(char *str))(t_var *var, int i)
{
	if (ft_strcmp(str, "ra\n") == 0)
		return (ra);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (rb);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (rr);
	else if (ft_strcmp(str, "sa\n") == 0)
		return (sa);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (sb);
	else if (ft_strcmp(str, "ss\n") == 0)
		return (ss);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (pa);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (pb);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (rra);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (rrb);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (rrr);
	else
		return (NULL);
}

void	ft_lstclear_check(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->c);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_list	*ft_lstnew_check(char *str)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->c = str;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	stock_instruction(t_var *var)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		ft_lstadd_back(&(var->inst), ft_lstnew_check(str));
	}
}

int	do_instruction(t_var *var)
{
	t_list	*temp;
	void	(*exec)(t_var *, int);

	temp = var->inst;
	while (temp)
	{
		exec = detect_entries(temp->c);
		if (!exec)
			return (ft_error(), 1);
		exec(var, 0);
		temp = temp->next;
	}
	return (0);
}
