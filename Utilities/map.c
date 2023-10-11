/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:01:04 by ghwa              #+#    #+#             */
/*   Updated: 2023/10/11 11:49:09 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

char	*readmap(int fd, t_map *map)
{
	char	*temp_array;

	temp_array = get_next_line(fd);
	while (temp_array != NULL)
	{
		map->temp_map = ft_strjoin(map->temp_map, temp_array);
		free (temp_array);
		temp_array = get_next_line(fd);
	}
	close(fd);
	map->map = ft_split(map->temp_map, '\n');
	return (map->temp_map);
}

void	set_tiles(t_map *map)
{
	int	size;

	size = map->img_width;
	map->img_water = mlx_xpm_file_to_image(map->mlx, map->water, &size, &size);
	map->img_grass = mlx_xpm_file_to_image(map->mlx, map->grass, &size, &size);
	map->img_dirt = mlx_xpm_file_to_image(map->mlx, map->dirt, &size, &size);
	map->img_p = mlx_xpm_file_to_image(map->mlx, map->player, &size, &size);
	map->img_fruit = mlx_xpm_file_to_image(map->mlx, map->apple, &size, &size);
	map->img_house = mlx_xpm_file_to_image(map->mlx, map->house, &size, &size);
}

int	initpaths(t_map *map)
{
	char	*arraymap1;

	map->house = "./Sprites/Tiles/house.xpm";
	map->apple = "./Sprites/Tiles/apple.xpm";
	map->water = "./Sprites/Tiles/water.xpm";
	map->dirt = "./Sprites/Tiles/dirt.xpm";
	map->grass = "./Sprites/Tiles/grass.xpm";
	map->player = "./Sprites/Char/down1-resized.xpm";
	map->temp_map = ft_strdup("\n");
	set_tiles(map);
	arraymap1 = readmap(map->fd, map);
	free (arraymap1);
	return (0);
}

void	put_tiles(t_map *map, int x, int y)
{
	int	size;

	size = map->img_width;
	if (map->map[y][x] == '1' || map->map[y][x] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->img_water, x * 32, y * 32);
	else if (map->map[y][x] == '.' || map->map[y][x] == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->img_grass, x * 32, y * 32);
	else if (map->map[y][x] == 'C' || map->map[y][x] == '$')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->img_fruit, x * 32, y * 32);
	else if (map->map[y][x] == 'X')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->img_dirt, x * 32, y * 32);
	else if (map->map[y][x] == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->img_p, x * 32, y * 32);
	else if (map->map[y][x] == 'W')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->img_house, x * 32, y * 32);
	else if (map->map[y][x] == '\0')
		;
	else
		mapfailed(8);
}

void	initmap(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map_h)
	{
		x = 0;
		while (x <= map->map_w)
		{
			put_tiles(map, x, y);
			x++;
		}
		y++;
	}
}
