/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 13:16:21 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/09 13:14:35 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

void	update_buffer(char **buff_ptr, int fd)
{
	char	*temp_buff;
	int		chars_read;

	chars_read = 1;
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
		if (chars_read <= 0)
			return ;
	}
}

char	*replace_buffer(char **buff, int split)
{
	char	*t_buf;

	t_buf = NULL;
	if (ft_strlen(*buff) - split > 0)
	{
		t_buf = (char *)malloc((ft_strlen(*buff) - split) * sizeof(char));
		if (!t_buf)
			return (NULL);
		ft_memcpy(t_buf, (void *)(*buff + split + 1), ft_strlen(*buff) - split);
	}
	free(*buff);
	return (t_buf);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*output;
	int			end;

	update_buffer(&buff, fd);
	end = get_new_line(buff, 1);
	if (end <= 0 && (!buff || !buff[0]))
	{
		free(buff);
		return (NULL);
	}
	output = (char *)malloc((end + 2) * sizeof(char));
	if (!output)
		return (NULL);
	ft_memcpy(output, buff, end + 2);
	buff = replace_buffer(&buff, end);
	return (output);
}

// int	main(void)
// {
// 	char	*str;

// 	int fd1 = open("input.txt", O_RDONLY);
// 	str = get_next_line(fd1);
// 	while (str)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 		str = get_next_line(fd1);
// 	}
// 	free(str);
// 	return (0);
// }
