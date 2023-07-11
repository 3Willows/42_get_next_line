/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwong <lwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:06:06 by lwong             #+#    #+#             */
/*   Updated: 2023/07/05 14:35:51 by lwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_join(char *original, char *addendum)
{
	char	*temp;

	temp = ft_strjoin(original, addendum);
	free(original);
	return (temp);
}

char	*read_file(int fd, char *unedited)
{
	char	*buffer;
	int		bytes_read;

	if (!unedited)
		unedited = ft_calloc(42, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 42;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(unedited);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		unedited = ft_free_join(unedited, buffer);
		if (ft_strchr(buffer, 10))
			break ;
	}
	free(buffer);
	return (unedited);
}

char	*ft_result(char *unedited)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!unedited[i])
		return (NULL);
	while (unedited[i] && unedited[i] != 10)
		i++;
	result = ft_calloc(i + 2, sizeof(char));
	while (j < i)
	{
		result[j] = unedited[j];
		j++;
	}
	if (unedited[j] && unedited[j] == 10)
	{
		result[j] = 10;
		j++;
	}
	result[j] = 0;
	return (result);
}

char	*ft_remainder(char *unedited)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (unedited[i] && unedited[i] != 10)
	{
		i++;
	}
	if (!unedited[i])
	{
		free(unedited);
		return (NULL);
	}
	remainder = ft_calloc(ft_strlen(unedited) - i + 1, sizeof(char));
	if (!remainder)
		return (NULL);
	while (unedited[i + 1 + j])
	{
		remainder[j] = unedited[i + 1 + j];
		j++;
	}
	free(unedited);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	result = ft_result(buffer);
	buffer = ft_remainder(buffer);
	return (result);
}
