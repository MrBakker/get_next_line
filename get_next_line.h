/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 13:15:33 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/06 12:39:46 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*replace_buffer(char **buff, int split);
char	*ft_memcpy(char *dest, const char *src, size_t len);

int		ft_strlen(const char *buff);
int		get_new_line(const char *buff, int include_0);

void	update_buffer(char **buff_ptr, int fd);

#endif