/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:51:49 by cfatrane          #+#    #+#             */
/*   Updated: 2016/11/29 10:21:37 by cfatrane         ###   ########.fr       */
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

int	ft_check(char *save, char **line)
{	
	char	*fin;

	fin = ft_strchr(save, '\n');
	if (fin != NULL)
	{
		*fin = '\0';
//		printf("fin apres boucle = %s\n", fin);
//		printf("predub de save = %s\n\n", save);
		*line = ft_strdup(save);
		//		printf("postdub de save = %s\n\n", save);
		//	printf("ligne fin = %s\n =",  (&fin[1]));
		//	ft_putchar('\n');
		ft_strncpy(save, &fin[1], ft_strlen(&fin[1]) + 1);
		//	printf("postmem de save = %s\n\n", save);
		return (1);
	}
	//	printf("Line final = %s\n", *line);
	return (0);
}

int	get_next_line(const int fd, char **line)
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
			break ;
		buf[ret] = '\0';
		//		printf("save avant join = %s\n", save);
		//		printf("buf avant joinin= %s\n\n", buf);
		tmp = ft_strjoin(save, buf);
		//		printf("save apres join = %s\n", save);
		//		printf("buf apres joinin= %s\n\n", buf);
		free(save);
		save = tmp;
	}
	//	*line = ft_strcdup(save, '\n');
	//	tmp = ft_strchr(save, '\n');
	//	save = tmp + 1;
	//	printf("save = %s\n\n", save);
	//	printf("fin avant boucle = %s\n", fin);
	return (ft_check(save, line));
}
