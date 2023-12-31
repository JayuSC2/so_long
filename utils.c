/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:21:59 by julian            #+#    #+#             */
/*   Updated: 2024/01/02 17:09:28 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
		write (fd, s, ft_strlen(s));
}

void	ft_error(char *str)
{
    ft_putstr_fd(str, 2);
    exit(1);
}

int get_next_line(int fd, char **line)
{
    char *buf;
    int ret;
    int i;

    i = 0;
    buf = malloc(sizeof(char) * 2);
    if (!buf)
        return (-1);
    ret = read(fd, buf, 1);
    if (ret == -1)
        return (-1);
    buf[1] = '\0';
    while (ret > 0 && buf[0] != '\n')
    {
        line[0][i] = buf[0];
        ret = read(fd, buf, 1);
        if (ret == -1)
            return (-1);
        buf[1] = '\0';
        i++;
    }
    line[0][i] = '\0';
    free(buf);
    return (ret);
}

int main(int argc, char **argv)
{
    int fd;
    int ret;
    char *line;

    /* if (argc != 2)
        ft_error("Error\nInvalid map"); */
    fd = open("gnltest.txt", O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map");
    line = malloc(sizeof(char) * 2); // Allocate memory for line
    if (!line)
        ft_error("Error\nMemory allocation failed");
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    printf("%s\n", line);
    free(line);
    close(fd);
    return (0);
}