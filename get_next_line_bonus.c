/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 12:38:19 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/06 12:38:33 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	update_buf(char **buff_ptr, int fd)
{
	char	*temp_buff;
	int		buff_count;
	int		read_bytes;

	while (get_new_line_pos(*buff_ptr) == -1)
	{
		buff_count = ft_strlen(*buff_ptr);
		temp_buff = (char *)malloc((buff_count + BUFFER_SIZE + 1));
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

	if (!update_buf(&buff, fd) && ft_strlen(buff) == 0)
		return (0);
	index = get_new_line_pos(buff);
	output = (char *)malloc((index + 1) * sizeof(char));
	if (!output)
		return (0);
	ft_memcpy(output, buff, index + 1);
	temp = (char *)malloc((ft_strlen(buff) - index) * sizeof(char));
	if (!temp)
		return (0);
	ft_memcpy(temp, buff + index + 1, (ft_strlen(buff) - index));
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
