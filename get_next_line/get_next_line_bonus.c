/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:01:35 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 08:38:31 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	read_buffer(int fd, char **stash, char *buffer)
{
	char	*tmp;
	int		byte;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	byte = read(fd, buffer, BUFFER_SIZE);
	if (byte < 0 || buffer == NULL)
	{
		free (*stash);
		*stash = (NULL);
		return (-1);
	}
	if (byte == 0)
		return (0);
	tmp = ft_strjoin(*stash, buffer);
	free(*stash);
	*stash = tmp;
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
	static char	*stash[MAX_FILES_OPENED];
	char		*result;
	char		*buffer;
	int			byte;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	byte = 1;
	while (ft_strchr(stash[fd], '\n') == NULL && byte > 0)
		byte = read_buffer(fd, &stash[fd], buffer);
	free (buffer);
	if (byte == -1)
		return (NULL);
	if (ft_strlen(stash[fd]) == 0)
		return (NULL);
	get_result(&stash[fd], &result);
	remove_result(&stash[fd]);
	return (result);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <filename1> <filename2> ...\n", argv[0]);
        return (1);
    }

    // 打开多个文件，并存储文件描述符
    int fds[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        fds[i - 1] = open(argv[i], O_RDONLY);
        if (fds[i - 1] == -1)
        {
            perror("Error opening file");
            return (1);
        }
    }

    // 从每个文件逐行读取并打印
    int files_remaining = argc - 1;
    while (files_remaining > 0)
    {
        for (int i = 0; i < argc - 1; i++)
        {
            if (fds[i] != -1) // 仅处理未结束的文件
            {
                char *line = get_next_line(fds[i]);
                if (line)
                {
                    printf("File %d: %s", i + 1, line);
                    free(line);
                }
                else
                {
                    // 文件读取结束，关闭并标记为已完成
                    close(fds[i]);
                    fds[i] = -1;
                    files_remaining--;
                }
            }
        }
    }

    return (0);
}*/
