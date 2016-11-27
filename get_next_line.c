/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:51:49 by cfatrane          #+#    #+#             */
/*   Updated: 2016/11/27 14:52:02 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	multifd()
{

}*/

int	gnl(char **line, char *save)
{
	char *eol;

	eol = ft_strchr(save, '\n');
	if (eol != NULL)
	{
		*eol = '\0';
		*line = ft_strdup(save);
		ft_memmove(save, &eol[1], ft_strlen(&eol[1]) + 1);
		return (1);
	}
	if (ft_strlen(save) > 0)
	{
		*line = ft_strdup(save);
		*save = '\0';
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*save = NULL;
	char		*tmp;
	int			ret;

	if (fd == -1 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (save == NULL)
		save = ft_strnew(0);
	while (!(ft_strchr(save, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		tmp = ft_strjoin(save, buf);
		free(save);
		save = tmp;
	}
	return (gnl(line, save));
}
