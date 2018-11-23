/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:56:09 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/11/23 20:44:29 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

static char		*update_str(const int fd, char *str)
{
	int ret;
	char buffer[BUFF_SIZE + 1];

	//	while (!ft_strchr(str, '\n'))
	//	{
	while (!(ft_strchr(str, '\n')))
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
		{
			buffer[ret] = '\0';
			str = ft_strjoin(str, buffer);
		}
		else 
			return (ret == 0 ? str : "error");
	}
	//	}

	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str = NULL;
	int				i;

	if (!line || !fd)
		return (-1);
	if (str == NULL)
		str = ft_strnew(0);
	str = update_str(fd, str);
	if (ft_strcmp(str, "error") == 0)
		return (-1);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i == 0)
		*line = ft_strnew(0);
	else
	{
		*line = ft_strsub(str, 0, i);
		str = str + i + 1;
	}
	return (1);
}
