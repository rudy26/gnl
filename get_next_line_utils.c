/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbrantho <rbrantho@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:38:35 by rbrantho          #+#    #+#             */
/*   Updated: 2025/11/13 19:38:40 by rbrantho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_new_line(char *stash)
{
	if (!stash)
		return (0);
	while (*stash)
	{
		if (*stash == '\n')
			return (1);
		stash++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	while (s1 && *s1)
		res[i++] = *s1++;
	while (s2 && *s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	tmp = (char *)s;
	i = 0;
	if (!tmp)
		return (0);
	while (tmp[i])
	{
		if (tmp[i] == c)
			return (&tmp[i]);
		i++;
	}
	return (0);
}
