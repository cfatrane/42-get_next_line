/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:51:49 by cfatrane          #+#    #+#             */
/*   Updated: 2016/11/26 17:41:12 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*save;
	char		*join;
	int			ret;

	ret = read(fd, buf, BUFF_SIZE);
	if (fd < 0 || *line == NULL || ret == -1)
		return (-1);
	save = ft_strnew(1);
	while (!(ft_strchr(*line, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (ret == 0)
			return (0);
		join = ft_strjoin(save, buf);
		free (save);
	}
	return (0);
}
