/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:56:09 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/11/25 00:21:50 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static char		*update_str(const int fd, char *str)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = ft_strjoin(str, buffer);
		ft_strdel(&str);
		str = tmp;
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str = NULL;
	char			*tmp;
	int				i;

	if (!line || fd == -1 || BUFF_SIZE <= 0)
		return (-1);
	if (str == NULL)
		str = ft_strnew(0);
	if (!ft_strchr(str, '\n'))
		str = update_str(fd, str);
	i = 0;
	if (str[i])
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (i == 0)
			*line = ft_strdup("");
		else
			*line = ft_strsub(str, 0, i);
		str = str + i + 1;
		return (1);
	}
	return (0);
}
