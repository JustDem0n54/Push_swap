/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:15:03 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 15:24:39 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n > 0)
	{
		*str++ = 0;
		n--;
	}
}

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count == 0 || size == 0 || count * size / size != count)
	{
		str = malloc(0);
		return (str);
	}
	str = (void *)malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

int	ft_lstadd_ref(t_list **lst, t_list *new)
{
	t_list	*l;

	if ((*lst) == NULL)
		return (ft_lstadd_back(lst, new), 1);
	if (new->i < (*lst)->i)
		return (ft_lstadd_front(lst, new), 1);
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
			return (2);
		l = l->next;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
