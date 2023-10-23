/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 12:37:44 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/23 12:00:28 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*replace_buffer(char **buff, int split);

int		ft_max(int a, int b);
int		ft_strlen(const char *buff);
int		get_new_line(const char *buff, int include_0);

void	ft_memcpy(const char *dest, const char *src, size_t len);
void	update_buffer(char **buff_ptr, int fd);

#endif