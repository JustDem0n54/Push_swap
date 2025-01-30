/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:24:08 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/30 18:47:01 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *storage, char *buff, int size)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = (char *)ft_calloc((ft_strlen(storage) + size + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	if (storage != NULL)
	{
		while (storage[i])
		{
			str[i] = storage[i];
			i++;
		}
	}
	j = -1;
	if (buff != NULL)
	{
		while (buff[++j])
			str[i + j] = buff[j];
	}
	str[(ft_strlen(storage) + size)] = '\0';
	return (str);
}
