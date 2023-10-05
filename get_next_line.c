/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 13:16:21 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/05 13:16:21 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

static int	get_new_line_pos(const char *buff)
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

static int	get_str_len(const char *buff)
{
	int	index;

	index = 0;
	while (buff && buff[index])
		++index;
	return (index);
}

static char	*ft_memcpy(char *dest, const char *src, size_t len)
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

static int	update_buf(char **buff_ptr, int fd)
{
	char	*temp_buff;
	int		buff_count;
	int		read_bytes;

	while (get_new_line_pos(*buff_ptr) == -1)
	{
		buff_count = get_str_len(*buff_ptr);
		temp_buff = (char *)malloc((buff_count + BUFFER_SIZE + 1) * sizeof(char));
		if (!temp_buff)
			return (0);
		ft_memcpy(temp_buff, *buff_ptr, buff_count + 1);
		read_bytes = read(fd, (void *)(temp_buff + buff_count), BUFFER_SIZE);
		temp_buff[buff_count + read_bytes] = '\0';
		free(*buff_ptr);
		*buff_ptr = temp_buff;
		if (read_bytes == 0)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*output;
	char		*temp;
	int			index;

	if (!update_buf(&buff, fd) && get_str_len(buff) == 0)
		return (0);
	index = get_new_line_pos(buff);
	output = (char *)malloc((index + 1) * sizeof(char));
	if (!output)
		return (0);
	ft_memcpy(output, buff, index + 1);
	temp = (char *)malloc((get_str_len(buff) - index) * sizeof(char));
	if (!temp)
		return (0);
	ft_memcpy(temp, buff + index + 1, (get_str_len(buff) - index));
	free(buff);
	buff = temp;
	return (output);
}

int	main(void)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		printf("%s\n", str);
		free(str);
		str = get_next_line(0);
	}
	return (0);
}