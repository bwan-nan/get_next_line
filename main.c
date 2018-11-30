/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:18:33 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/11/30 15:30:46 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		i;

	line = NULL;
	if (ac > 1)
	{
		fd1 = open(av[1], O_RDONLY);
		get_next_line(fd1, &line);
		printf("%s\n", line);
		ft_strdel(&line);
		get_next_line(fd1, &line);
		printf("%s\n", line);
		ft_strdel(&line);


		fd2 = open(av[2], O_RDONLY);
		get_next_line(fd2, &line);
		printf("%s\n", line);
		ft_strdel(&line);
		
		get_next_line(fd1, &line);
		printf("%s\n", line);
		ft_strdel(&line);
		
		get_next_line(fd2, &line);
		printf("%s\n", line);
		ft_strdel(&line);



		close(fd1);
		close(fd2);
	}
	return (0);
}
