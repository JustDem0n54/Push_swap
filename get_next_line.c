/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:24:09 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/31 11:24:28 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*create_storage(char *str)
{
	size_t	i;
	size_t	pos;

	i = -1;
	pos = -1;
	while (str[++pos])
		if (str[pos] == '\n')
			break ;
	if (str[pos])
		pos++;
	while (str[(++i) + pos])
		str[i] = str[i + pos];
	while (pos)
	{
		str[pos + i - 1] = 0;
		pos--;
	}
	if (!str[0])
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*read_check(char *str, int fd, char *buff)
{
	int		size_rd;
	char	*temp;

	size_rd = 1;
	while (ft_strchr(str, '\n') == 0 && size_rd != 0)
	{
		size_rd = read(fd, buff, BUFFER_SIZE);
		if (size_rd == -1)
		{
			free(str);
			return (NULL);
		}
		buff[size_rd] = '\0';
		temp = str;
		str = ft_strjoin(str, buff, size_rd);
		free (temp);
	}
	if (size_rd == 0 && str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	if (size_rd == 0 && str && str[0] != '\0')
		return (str);
	return (str);
}

char	*ft_strcpy(char *str)
{
	size_t	i;
	int		len;
	char	*buff;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len])
		len++;
	i = 0;
	buff = malloc((len + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		buff[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*storage = NULL;
	char		buff[BUFFER_SIZE + 1];

	if (BUFFER_SIZE == 0)
		return (NULL);
	storage = read_check(storage, fd, buff);
	if (!storage)
		return (NULL);
	str = ft_strcpy(storage);
	if (str == NULL)
		return (NULL);
	storage = create_storage(storage);
	return (str);
}
