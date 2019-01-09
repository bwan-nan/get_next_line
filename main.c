/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:25:59 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/01/09 19:29:22 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	char	*line;

	line = NULL;
	if (ac != 2)
		ft_putendl("usage: ./GNL file_name");
	else
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			ft_putendl(line);
			ft_strdel(&line);
		}
		close(fd);
	}
	return (0);
}
