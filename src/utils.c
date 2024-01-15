/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:21:59 by julian            #+#    #+#             */
/*   Updated: 2024/01/11 18:12:24 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
    ft_putstr_fd(str, 2);
    exit(1);
}

/* int main(int argc, char **argv)
{
    int fd;
    int ret;
    char *line;

    if (argc != 2)
        ft_error("Error\nInvalid map");
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
} */