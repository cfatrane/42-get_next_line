/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:51:49 by cfatrane          #+#    #+#             */
/*   Updated: 2016/11/29 13:48:46 by cfatrane         ###   ########.fr       */
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

	fin = ft_strchr(save, '\n');
//	printf("fin = %s\n", fin);
	if (fin != NULL)
	{
		*fin = '\0';
	//	printf("taille de save before avec chr= %zu\n", ft_strlen(save));
		*line = ft_strdup(save);
		ft_strncpy(save, &fin[1], ft_strlen(&fin[1]) + 1);
	//	printf("taille de save after avec chr= %zu\n", ft_strlen(save));
		return (1);
	}
	else if (ft_strlen(save) > 0)
	{
	//	printf("taille de save = %zu\n", ft_strlen(save));
	//	printf("save du check = %s\n\n", save);
	//	i++;
		*line = ft_strdup(save);
	//	printf("line du check = %s\n\n", *line);
		*save = '\0';
	//	printf("save AFTER check = %s\n\n", save);
	//	printf("taille de save after= %zu\n", ft_strlen(save));
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
	//	printf("buf de la boucle = %s\n", buf);
	//	printf("save de la boucle = %s\n", save);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (ft_check(save, line));
		//	return (ft_check(save, line));
		buf[ret] = '\0';
		tmp = ft_strjoin(save, buf);
		free(save);
		save = tmp;
	}
	//	printf("save du main = %s\n\n", save);
	//	*line = ft_strcdup(save, '\n');
	//	tmp = ft_strchr(save, '\n');
	//	save = tmp + 1;
	return (ft_check(save, line));
}
