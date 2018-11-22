/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:56:09 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/11/22 14:24:46 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

static char		is_end_of_line(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char		*update_str(const int fd, char *str)
{
	int ret;
	char buffer;

	if (!(ret = read(fd, &buffer, BUFF_SIZE)))
		return (0);
	str = ft_strjoin(str, &buffer);

	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str = "";
	int		str_len;


	do 
	{
		if (!(str = update_str(fd, str)))
			return (0);
	}
	while (is_end_of_line(str) != 1);
	str_len = ft_strlen(str);
	str[str_len] = '\0';

	printf("%s", str);

	return (1);
}
