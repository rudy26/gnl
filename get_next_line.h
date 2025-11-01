/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbrantho <rbrantho@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:35:35 by rbrantho          #+#    #+#             */
/*   Updated: 2025/11/01 14:51:33 by rbrantho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_last(t_list *stash);
int		newline(t_list *stash);
void	generate_line(char **line, t_list *stash);
void	free_stash(t_list *stash);
char	*get_next_line(int fd);
void	read_stash(int fd, t_list **stash);
void	add_stash(t_list **stash, char *buff, int reade);
void	extract_line(t_list *stash, char **line);
void	clean(t_list **stash);
int		ft_strlen(char *str);
#endif