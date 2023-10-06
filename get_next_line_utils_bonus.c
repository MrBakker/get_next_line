/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 12:35:39 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/06 12:36:44 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_new_line_pos(const char *buff)
{
	int	index;

	if (!buff)
		return (-1);
	index = 0;
	while (buff[index] && buff[index] != '\n')
		++index;
	if (buff[index] == '\n')
		return (index);
	return (-1);
}

int	ft_strlen(const char *buff)
{
	int	index;

	index = 0;
	while (buff && buff[index])
		++index;
	return (index);
}

char	*ft_memcpy(char *dest, const char *src, size_t len)
{
	size_t	index;
	char	*ptr;

	index = 0;
	ptr = (char *)dest;
	while (index < len - 1)
	{
		ptr[index] = src[index];
		++index;
	}
	ptr[index] = '\0';
	return (dest);
}
