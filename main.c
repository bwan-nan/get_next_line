/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:18:33 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/11/28 18:39:12 by bwan-nan         ###   ########.fr       */
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
	i = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		while (i != 70)
		{
			get_next_line(fd, &line);
			printf("%s\n", line);
			i++;
		}
		close(fd);
	}
	return (0);
}
