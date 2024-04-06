/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:13:29 by julian            #+#    #+#             */
/*   Updated: 2024/04/06 16:26:23 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
} */
void	check_arguments(int argc, char **argv)
{
    if (argc != 2)
        ft_error("Error\nInvalid map1");
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
    {
		ft_error("Error\nInvalid map2");
	}
}

void	map_check(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map->full[i])
    {
        while (data->map->full[i][j])
        {
            if (data->map->full[i][j] != '1' && data->map->full[i][j] != '0' && data->map->full[i][j] != 'P' && data->map->full[i][j] != 'C' && data->map->full[i][j] != 'E')
                ft_error("Error\nInvalid map3");
            if (data->map->full[0][j] != '1' && data->map->full[data->map->height - 1][j] != '1')
                ft_error("Error\nInvalid map4");
            if (data->map->full[i][0] != '1' && data->map->full[i][data->map->width - 1] != '1')
                ft_error("Error\nInvalid map5");
            j++;
        }
        i++;
    }
}

/* void count_collectibles(t_data *data)
{
    int i;
    int j;

    i = 0;
    data->map->collectibles = 0;
    while (data->map->full[i])
    {
        j = 0;
        while (data->map->full[i][j])
        {
            if (data->map->full[i][j] == 'C')
                data->map->collectibles++;
            j++;
        }
        i++;
    }
} */

size_t count_height(char **full_map)
{
	size_t counter;
	int i;

	counter = 0;
	i = 0;
	while (full_map[i] != NULL)
	{
		counter++;
		i++;
	}
	return (counter);
}

/* size_t	count_height(char **full_map)
{
	int counter;
	int i;
	int j;
	
	i = 0;
	counter = 0;
	while (full_map[i])
	{
		j = 0;
		while (full_map[i][j] != '\0')
		{
			if (full_map[i][j] == '\0')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
} */

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
    data.map->full = malloc(count_height(argv) * ft_strlen((line + 1)));
	ft_printf("%s", "test1\n");
    if (!data.map->full)
        ft_error("Error\nMemory allocation failed");
	while (get_next_line(fd, &line) == 0)
    {
		if (line != NULL)
		{
			data.map->full[data.map->height] = line;
			data.map->height++;
		}
    }
	data.map->full[data.map->height] = NULL;
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
    data.map->full = malloc((count_height(argv) + 1) * sizeof(char*));  // Allocate memory for the lines, plus one for the NULL pointer at the end
    if (!data.map->full)
	{
        ft_error("Error\nMemory allocation failed");
	}
	ft_printf("%s", "test3\n");
	while (get_next_line(fd, &line) == 0)
	{
		if (line != NULL)
		{
			data.map->full[data.map->height] = line;
			data.map->height++;
		}
	}
	ft_printf("%s", "test4\n");
    data.map->full[data.map->height] = NULL;
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
    data.map->full = malloc((count_height(argv) + 1) * sizeof(char*));  // Allocate memory for the lines, plus one for the NULL pointer at the end
    if (!data.map->full)
	{
        ft_error("Error\nMemory allocation failed");
	}
	while (get_next_line(fd, &line) == 0 && line != NULL)
    {
        data.map->full[data.map->height] = line;
		ft_printf("%s", data.map->full[data.map->height]);
        data.map->height++;
    }
	data.map->full[data.map->height] = NULL;
	close(fd);
    //map_check(&data);
} */
void read_map(int argc, char **argv, t_data	*data)
{
	int		fd;
	char	*line = NULL;
	(void)argc;
	int i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error\nInvalid map6");
	ft_printf("%s", "test1\n");
	ft_printf("%s", "test2\n");
	i = 0;
	while ((get_next_line(fd, &line) == 0 && line != NULL))
	{
		data->map->full[i] = (char *)malloc((ft_strlen(line) + 1) * sizeof(char));
		if (!data->map->full[i])
			ft_error("Error\nInvalid map7");
		ft_strlcpy(data->map->full[i], line, ft_strlen(line) + 1);
		data->map->width = ft_strlen(line);
		i++;
		free(line);
	}
	data->map->full[i] = NULL;
	data->map->height = i;
/* 	int i = 0;
	while (data->map->full[i])
		ft_printf("%s", data->map->full[i++]); */
	close(fd);

	//free(data.map->full);
	//map_check(&data);
}

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
		data->map->full = malloc(ft_strlen(argv[1]) * (count_height(argv)));
        if (!data->map->full)
            ft_error("Error\nInvalid map");
        data->map->full[data->map->height] = line;
        data->map->full[data->map->height + 1] = NULL;
        data->map->height++;
		free(line);
    }
	free(data->map->full);
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
		data->map->full = malloc(ft_strlen(line) * (count_height(argv)));
		if (!data->map->full)
			ft_error("Error\nInvalid map");
		data->map->full[data->map->height] = line;
		data->map->full[data->map->height + 1] = NULL;
		data->map->height++;
		free(line);
	}
	free(data->map->full);
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