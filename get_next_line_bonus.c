/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 12:38:19 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/06 21:11:56 by jbakker       ########   odam.nl         */
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

int ft_strlen(const char *ptr)
{
	int	index;

	index = 0;
	while (ptr[index])
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

void	update_buffer(char **buff_ptr, int fd)
{
	char	*temp_buff;
	int		chars_read;

	chars_read = 1;printf("hi");
	while (get_new_line(*buff_ptr, 0) == -1 && chars_read)
	{
		temp_buff = (char *)malloc((ft_strlen(*buff_ptr) + BUFFER_SIZE + 1));
		if (!temp_buff)
			return ;
		ft_memcpy(temp_buff, *buff_ptr, ft_strlen(*buff_ptr) + 1);
		chars_read = read(fd, (temp_buff + ft_strlen(*buff_ptr)), BUFFER_SIZE);
		temp_buff[ft_strlen(*buff_ptr) + chars_read] = '\0';
		free(*buff_ptr);
		*buff_ptr = temp_buff;
		if (chars_read == 0)
			return ;
	}
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*output;
	char		*temp_buff;
	int			end;

	update_buffer(&buff, fd);
	
	end = get_new_line(buff, 1);
	if (end == 0 && !buff[0])
		return (buff);
	output = (char *)malloc((end + 1) * sizeof(char));
	ft_memcpy(output, buff, end + 1);
	temp_buff = (char *)malloc((ft_strlen(buff) - end) * sizeof(char));
	if (!temp_buff)
		return (NULL);
	ft_memcpy(temp_buff, (void *)(buff + end + 1), ft_strlen(buff) - end);
	free(buff);
	buff = temp_buff;
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
