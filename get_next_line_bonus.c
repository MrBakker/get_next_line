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
	char	*temp_buff;

	temp_buff = NULL;
	if (ft_strlen(*buff) - split > 0)
	{
		temp_buff = (char *)malloc((ft_strlen(*buff) - split) * sizeof(char));
		if (!temp_buff)
			return (NULL);
		ft_memcpy(temp_buff, (void *)(*buff + split + 1), ft_strlen(*buff) - split);
	}
	free(*buff);
	return (temp_buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[8192];
	char		*output;
	int			end;

	update_buffer(&buff[fd], fd);
	end = get_new_line(buff[fd], 1);
	if (end <= 0 && (!buff[fd] || !buff[fd][0]))
	{
		free(buff[fd]);
		return (NULL);
	}
	output = (char *)malloc((end + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ft_memcpy(output, buff[fd], end + 1);
	buff[fd] = replace_buffer(&buff[fd], end);
	return (output);
}

// int	main(void)
// {
// 	char	*str;

// 	int fd1 = open("input.txt", O_RDONLY);
// 	int fd2 = open("input2.txt", O_RDONLY);
// 	int fd3 = open("input3.txt", O_RDONLY);
// 	str = get_next_line(fd1);
// 	while (str)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 		str = get_next_line(fd1);
// 	}
// 	free(str);

// 	str = get_next_line(fd2);
// 	while (str)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 		str = get_next_line(fd2);
// 	}
// 	free(str);

// 	str = get_next_line(fd3);
// 	while (str)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 		str = get_next_line(fd3);
// 	}
// 	free(str);

// 	return (0);
// }
