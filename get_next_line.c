/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:56:09 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/11/21 17:24:42 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char buffer;
	char *str;

	while (read(fd, &buffer, 1))
	{
		*str = buffer;
		ft_strjoin(*line, str);
	}
	return (1);
}
