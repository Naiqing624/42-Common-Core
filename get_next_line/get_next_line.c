/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:39:25 by marvin            #+#    #+#             */
/*   Updated: 2024/11/01 13:39:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buffer(int fd, char **stash, char *buffer)
{
	char	*tmp;
	ssize_t byte;

	//ft_bzero(buffer, BUFFER_SIZE + 1);
	byte = read(fd, buffer, BUFFER_SIZE);
	if (byte < 0)
	{
		free (*stash);
		*stash = (NULL);
		return (-1);
	}
	if (byte == 0)
		return (0);
	buffer[byte] = '\0';
	if (*stash == NULL)
        *stash = ft_strdup(buffer);  
    else
    {
        tmp = ft_strjoin(*stash, buffer);
        free(*stash);
        *stash = tmp;
    }
	return (byte);
}

static void	get_result(char **stash, char **result)
{
	char	*n;
	size_t	len;
	size_t	i;

	n = ft_strchr(*stash, '\n');
	len = ft_strlen(*stash) - ft_strlen(n) + 2;
	*result = (char *)malloc(len * sizeof(char));
	if (!result)
		return ;
	i = 0;
	while (i < len - 1)
	{
		(*result)[i] = (*stash)[i];
		i++;
	}
	(*result)[i] = '\0';
}

static void	remove_result(char **stash)
{
	char	*n;
	char	*tmp;

	n = ft_strchr(*stash, '\n');
	if (!n)
	{
		free (*stash);
		*stash = NULL;
		return ;
	}
	tmp = ft_strdup(n + 1);
	if (!tmp)
	{
		free (*stash);
		*stash = NULL;
		return ;
	}
	free (*stash);
	*stash = tmp;
	if (**stash == '\0')
	{
		free (*stash);
		*stash = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*result;
	char	*buffer;
	int	byte;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	byte = 1;
	while (ft_strchr(stash, '\n') == NULL && byte > 0)
		byte = read_buffer(fd, &stash, buffer);
	free (buffer);
	if (byte == -1 || (byte == 0 && (!stash || stash[0] == '\0')))
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
	get_result(&stash, &result);
	remove_result(&stash);
	return (result);
}
/*
#include <fcntl.h>

int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    //printf("File opened successfully.\n"); // 调试信息

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Read line: %s\n", line); // 输出每行
        free(line);
    }

    close(fd);
    printf("File closed.\n");

    return (0);
}*/