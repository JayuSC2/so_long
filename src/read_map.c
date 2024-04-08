/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:13:29 by julian            #+#    #+#             */
/*   Updated: 2024/04/08 17:08:33 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arguments(int argc, char **argv)
{
    if (argc != 2)
        ft_error("Error: Usage: ./so_long <mapname>\n");
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
    {
		ft_error("Error: Map has to be .ber file\n");
	}
}

/* void count_collectibles(t_data *data)
{
    int i;
    int j;

    i = 0;
    data->map->collectibles = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'C')
                data->map->collectibles++;
            j++;
        }
        i++;
    }
} */

/* int	count_height(int argc, char **argv)
{
	int height;
	char *line = NULL;
	int fd;

	height = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) && line != NULL)
	{
		height++;
		free(line);
	}
	return (height);
} */

char	*read_map(t_data *data)
{
	char	*line;
	char	*temp;
	int		bytes_read;

	temp = (char *)malloc(1 + 1);
	if (!temp)
		return (NULL);
	line = ft_strdup("");
	//NULL CHECK
	bytes_read = 1;
	while (bytes_read > 0 && !(ft_strchr(line, EOF)))
	{
		bytes_read = read(data->fd, temp, 1);
		if (bytes_read == -1)
			//clear all and exit
			return (NULL);
		temp[bytes_read] = '\0';
		line = ft_strjoin(line, temp);
		if (!line)
			return (NULL);
	}
	return (free(temp), line);
}

// void read_map2(int argc, char **argv, t_data	*data)
// {
// 	int		fd;
// 	char	*line = NULL;
// 	(void)argc;
// 	int i;

// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		ft_error("Error\nInvalid map6");
// 	ft_printf("%s", "test1\n");
// 	ft_printf("%s", "test2\n");
// 	i = 0;
// 	while ((get_next_line(fd, &line) == 0 && line != NULL))
// 	{
// 		data->map[i] = malloc((ft_strlen(line) + 1) * sizeof(char));
// 		if (!data->map[i])
// 			ft_error("Error\nInvalid map7");
// 		ft_strlcpy(data->map[i], line, ft_strlen(line) + 1);
// 		data->width = ft_strlen(line);
// 		i++;
// 		free(line);
// 	}
// 	data->map[i] = NULL;
// 	data->height = i;
// 	close(fd);
// 	//free(data->map);
// }

/* void read_map(char **argv)
{
    int		fd;
    t_data	data;
    char	*line;

	line = NULL;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	{
    	ft_error("Error\nInvalid map6");
	}
	data.map->height = 0;
    data.map = malloc(count_height(argv) * ft_strlen((line + 1)));
	ft_printf("%s", "test1\n");
    if (!data.map)
        ft_error("Error\nMemory allocation failed");
	while (get_next_line(fd, &line) == 0)
    {
		if (line != NULL)
		{
			data.map[data.map->height] = line;
			data.map->height++;
		}
    }
	data.map[data.map->height] = NULL;
	close(fd);
    map_check(&data);
}
 */
 
/* void read_map(char **argv)
{
    int		fd;
    t_data	data;
    char	*line;

	line = NULL;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map6");
    data.map = malloc(sizeof(t_map));
	ft_printf("%s", "test1\n");
    if (!data.map)
	{
        ft_error("Error\nMemory allocation failed");
	}
	ft_printf("%s", "test2\n");
    data.map->height = 0;
    data.map = malloc((count_height(argv) + 1) * sizeof(char*));  // Allocate memory for the lines, plus one for the NULL pointer at the end
    if (!data.map)
	{
        ft_error("Error\nMemory allocation failed");
	}
	ft_printf("%s", "test3\n");
	while (get_next_line(fd, &line) == 0)
	{
		if (line != NULL)
		{
			data.map[data.map->height] = line;
			data.map->height++;
		}
	}
	ft_printf("%s", "test4\n");
    data.map[data.map->height] = NULL;
	close(fd);
    map_check(&data);
} */
/* void read_map(char **argv)
{
    int		fd;
    t_data	data;
    char	*line = NULL;

	fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	{
        ft_error("Error\nInvalid map6");
	}
	data.map->height = 0;
    data.map = malloc((count_height(argv) + 1) * sizeof(char*));  // Allocate memory for the lines, plus one for the NULL pointer at the end
    if (!data.map)
	{
        ft_error("Error\nMemory allocation failed");
	}
	while (get_next_line(fd, &line) == 0 && line != NULL)
    {
        data.map[data.map->height] = line;
		ft_printf("%s", data.map[data.map->height]);
        data.map->height++;
    }
	data.map[data.map->height] = NULL;
	close(fd);
    //map_check(&data);
} */

/* void	read_map (char **argv)
{
    int		fd;
	t_data *data = NULL;
	//int		ret;
    char	*line = NULL;
	
    fd = open(*argv, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map");
    data->map->height = 0;
	while ((get_next_line(fd, argv) == 0))
    {
		data->map = malloc(ft_strlen(argv[1]) * (count_height(argv)));
        if (!data->map)
            ft_error("Error\nInvalid map");
        data->map[data->map->height] = line;
        data->map[data->map->height + 1] = NULL;
        data->map->height++;
		free(line);
    }
	free(data->map);
    close(fd);
    map_check(data);
} */

/* void	read_map (char **argv)
{
	int		fd;
	t_data *data;
	//int		ret;
	char	*line;
	
	fd = open(*argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nInvalid map");
	data = malloc(sizeof(t_data));
	if (!data)
		ft_error("Error\nInvalid map");
	data->map->height = 0;
	ft_printf("%s", "test1\n");
	while ((get_next_line(fd, &line) == 0))
	{
		data->map = malloc(ft_strlen(line) * (count_height(argv)));
		if (!data->map)
			ft_error("Error\nInvalid map");
		data->map[data->map->height] = line;
		data->map[data->map->height + 1] = NULL;
		data->map->height++;
		free(line);
	}
	free(data->map);
	close(fd);
	map_check(data);
}
 */
/* #include <stdio.h>

int main(int argc, char **argv) 
{
	if (argc != 2) 
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	read_map(argv + 1);
	return (0);
} */

/* #include <stdio.h>

int main(void) 
{
	char *map[] = 
	{
		"11111",
		"00000",
		"PCE00",
		NULL
	};

	size_t height = count_height(map);
	size_t width = ft_strlen(map[0]);
	printf("Height: %zu\n", height);
	printf("Width: %zu\n", width);
	return (0);
} */