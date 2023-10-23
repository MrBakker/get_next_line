/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 12:35:39 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/23 11:57:27 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_new_line(const char *buff, int include_0)
{
	int	index;

	index = 0;
	if (!buff)
		return (-1);
	while (buff[index] && buff[index] != '\n')
		++index;
	if (buff[index] == '\n' || include_0)
		return (index);
	return (-1);
}

int	ft_strlen(const char *buff)
{
	int	index;

	index = 0;
	if (!buff)
		return (0);
	while (buff && buff[index])
		++index;
	return (index);
}

void	ft_memcpy(const char *dest, const char *src, size_t len)
{
	size_t	index;
	char	*ptr;

	index = 0;
	if (len == 0 || !dest || !src)
		return ;
	ptr = (char *)dest;
	while (index + 1 < len)
	{
		ptr[index] = src[index];
		++index;
	}
	ptr[index] = '\0';
}

int	ft_max(int a, int b)
{
	return ((a < b) * b + (a >= b) * a);
}
