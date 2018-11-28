/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:56:09 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/11/28 19:51:51 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static void		update_str(const int fd, char **str)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = ft_strjoin(*str, buffer);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
		if (ft_strchr(*str, '\n'))
			break ;
	}
}

int				get_next_line(const int fd, char **line)
{
	static char		*str = NULL;
	int				i;


	if (read(fd, 0, 0) == -1 || BUFF_SIZE <= 0)
		return (-1);
	if (str == NULL)
		str = ft_strnew(0);
	if (!ft_strchr(str, '\n'))
		update_str(fd, &str);
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
