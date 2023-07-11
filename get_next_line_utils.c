/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwong <lwong@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:06:24 by lwong             #+#    #+#             */
/*   Updated: 2023/07/05 14:31:29 by lwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *String)
{
	int		i;

	i = 0;
	while (String[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *String, int Char)
{
	char	*s;
	int		i;

	if (!String)
		return (NULL);
	i = 0;
	s = (char *)String;
	while (s[i])
	{
		if (s[i] == Char)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*zeroed_mem_block;

	zeroed_mem_block = malloc(elementCount * elementSize);
	if (!zeroed_mem_block)
	{
		return (NULL);
	}
	ft_bzero(zeroed_mem_block, elementCount * elementSize);
	return (zeroed_mem_block);
}

char	*ft_strjoin(const char *original, const char *addendum)
{
	int		total_length;
	char	*joint_string;
	int		i;

	total_length = ft_strlen(original) + ft_strlen(addendum);
	joint_string = ft_calloc(total_length + 1, sizeof(char));
	i = 0;
	if (!joint_string || !original || !addendum)
		return (NULL);
	while (original[i])
	{
		joint_string[i] = original[i];
		i++;
	}
	i = 0;
	while (addendum[i])
	{
		joint_string[ft_strlen(original) + i] = addendum[i];
		i++;
	}
	joint_string[total_length] = 0;
	return (joint_string);
}
