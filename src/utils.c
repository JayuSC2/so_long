/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:21:59 by julian            #+#    #+#             */
/*   Updated: 2024/04/11 15:35:54 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_free(char **strarray)
// {
// 	int	i;

// 	i = 0;
// 	if (strarray == NULL)
// 		return ;
// 	while (strarray[i])
// 		free(strarray[i++]);
// 	free(strarray);
// }
void	calculate_map_dimensions(t_data *data)
{
	int	height;
	int	width;
	
	height = 0;
	while (data->map[height] != NULL)
		height++;
	data->height = height;

	width = 0;
	if (data->map[0] != NULL) 
	{
		while (data->map[0][width])
			width++;
	}
	data->width = width;
}

void	ft_error(char *str)
{
    ft_putstr_fd(str, 2);
    //exit(1);
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