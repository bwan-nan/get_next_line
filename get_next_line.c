/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:56:09 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/11/30 15:40:28 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static void		ft_
static a_list	*ft_lstcreate(const int fd, a_list **list)
{
	a_list *tmp;

	if (!(tmp = (a_list *)malloc(sizeof(a_list))))
		return (NULL);
	tmp->fd = fd;
	tmp->str = NULL;
	tmp->next = *list;
	return (tmp);
}

static void		update_str(const int fd, char **str)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buffer);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
	}
}

int				get_next_line(const int fd, char **line)
{
	static a_list	*list = NULL;
	a_list			*elem;
	char			*tmp;
	int				i;

	if (read(fd, 0, 0) == -1 || BUFF_SIZE <= 0)
		return (-1);
	elem = list;
	while (elem)
	{
		if (elem->fd == fd)
			break ;
		elem = elem->next;
	}
	if (elem == NULL)
	{
		if (!(elem = ft_lstcreate(fd, &list)))
			return (-1);
		list = elem;
	}
	if (elem->str == NULL)
		elem->str = ft_strnew(0);
	if (!ft_strchr(elem->str, '\n'))
		update_str(fd, &(elem->str));
	i = 0;
	tmp = elem->str;
	if (elem->str[i])
	{
		while (elem->str[i] && elem->str[i] != '\n')
			i++;
		if (i == 0)
			*line = ft_strnew(0);
		else
			*line = ft_strsub(elem->str, 0, i);
		if (ft_strchr(elem->str, '\n'))
			elem->str = ft_strdup(ft_strchr(elem->str, '\n') + 1);
		else
			elem->str = ft_strnew(0);
		free(tmp);
		return (1);
	}
	return (0);
}
