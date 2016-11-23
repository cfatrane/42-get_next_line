/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:51:49 by cfatrane          #+#    #+#             */
/*   Updated: 2016/11/23 20:16:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
//	static char	

	ret = read(fd, buf, BUFF_SIZE);
	if (fd == -1 || *line == NULL || ret == -1)
		return (-1);
	while (!(ft_strchr(*line , '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';

	}
	return (0);
}
