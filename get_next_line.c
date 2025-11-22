/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbrantho <rbrantho@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:38:31 by rbrantho          #+#    #+#             */
/*   Updated: 2025/11/13 19:38:42 by rbrantho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*take_line(char *tmp)
{
	int		i;
	char	*line;

	i = 0;
	if (!tmp[0])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save(char *stash)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	free(stash);
	return (rest);
}

char	*read_and_stash(int fd, char *stash, int *readed_ptr)
{
	char	*buff;
	char	*tmp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!found_new_line(stash) && *readed_ptr > 0)
	{
		*readed_ptr = read(fd, buff, BUFFER_SIZE);
		if (*readed_ptr == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[*readed_ptr] = '\0';
		tmp = ft_strjoin(stash, buff);
		free(stash);
		stash = tmp;
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			cwc;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cwc = 1;
	stash = read_and_stash(fd, stash, &cwc);
	if (!stash)
		return (NULL);
	line = take_line(stash);
	stash = save(stash);
	return (line);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("tes2.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }