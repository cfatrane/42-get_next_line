/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:51:49 by cfatrane          #+#    #+#             */
/*   Updated: 2016/11/29 12:57:40 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*int	multifd()
  {

  }*/
/*char	*ft_strcdup(const char *s1, char c)
  {
  char	*s2;
  size_t	i;

  i = 0;
  if (!(s2 = ft_strnew(ft_strlen(s1))))
  return (NULL);
  while (s1[i] != '\0' && s1[i] != c)
  {
  s2[i] = s1[i];
  i++;
  }
  return (s2);
  }*/

static int	ft_check(char *save, char **line)
{
	char	*fin;
	static int		i;

	i = 0;
	if (i == 0)
		i++;
	fin = ft_strchr(save, '\n');
//	printf("fin = %s\n", fin);
	if (fin != NULL)
	{
		*fin = '\0';
		*line = ft_strdup(save);
		ft_strncpy(save, &fin[1], ft_strlen(&fin[1]) + 1);
		return (1);
	}
	else if (save != NULL)
	{
		printf("taille de save = %zu\n", ft_strlen(save));
		printf("save = %s\n", &save[i]);
		i++;
		*line = ft_strdup(save);
		*save = '\0';
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*save = NULL;
	char		*tmp;
	int			ret;

	if (!(save))
		save = ft_strnew(0);
	if (fd == -1 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while (!(ft_strchr(save, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (ft_check(save, line));
		buf[ret] = '\0';
		tmp = ft_strjoin(save, buf);
		free(save);
		save = tmp;
	}
	//	*line = ft_strcdup(save, '\n');
	//	tmp = ft_strchr(save, '\n');
	//	save = tmp + 1;
	return (ft_check(save, line));
}
