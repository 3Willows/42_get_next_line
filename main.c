/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwong <lwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:11:27 by lwong             #+#    #+#             */
/*   Updated: 2023/07/05 20:06:46 by lwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	main(void)
{
	int		fd;
	char	*line;

	fd = open("testfile.txt", O_RDONLY);

	if (fd == -1)
	{
		return (1);
	}
	line = NULL;
	line = get_next_line(fd);
	// while (line != NULL)
	// {
		printf("%s", line);
	// 	line = get_next_line(fd);
	// }
	free(line);
	close(fd);
	return (0);
}
