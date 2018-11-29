/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:18:33 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/11/29 14:19:03 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;

	line = NULL;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			printf("%s\n", line);
		}
		close(fd);
	}
	return (0);
}
