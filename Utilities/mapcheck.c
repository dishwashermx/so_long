/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:18:49 by ghwa              #+#    #+#             */
/*   Updated: 2023/09/27 10:57:34 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

int	tile_check(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->map_h)
	{
		x = 0;
		while (x < map->map_w)
		{
			if (map->map[y][x] == 'C')
				map->collectiblefound++;
			else if (map->map[y][x] == 'P')
			{
				map->pxpos = x;
				map->pypos = y;
				map->playerfound++;
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	rectangular_check(t_map *map)
{
	int	y;

	y = ft_strlen(map->map[0]);
	map->collectiblefound = 0;
	map->playerfound = 0;
	map->map_h = 0;
	map->steps = 0;
	map->map_w = y;
	while (map->map[map->map_h])
	{
		if (ft_strlen(map->map[map->map_h]) == map->map_w)
			map->map_h++;
		else
			return (0);
	}
	return (1);
}

int	walls_check(t_map *map)
{
	int	x;

	x = 0;
	while (x < map->map_w)
	{
		if (map->map[0][x] == '1' && map->map[map->map_h - 1][x] == '1')
			x++;
		else
			return (0);
	}
	x = 1;
	while (x < (map->map_h - 1))
	{
		if (map->map[x][0] == '1' && map->map[x][map->map_w - 1] == '1')
			x++;
		else
			return (0);
	}
	return (1);
}

int	path_check(t_map *map, int y, int x, int count)
{
	if (x < 0 || x >= map->map_w || y < 0 || y >= map->map_h)
		return (0);
	else if (map->map[y][x] == '1' || map->map[y][x] == 'X' \
		|| map->map[y][x] == '.' || map->map[y][x] == '$' \
		|| (map->map[y][x] == 'P' && count == 0))
		return (0);
	else if (map->map[y][x] == '0')
		map->map[y][x] = '.';
	else if (map->map[y][x] == 'C')
		map->map[y][x] = '$';
	else if (map->map[y][x] == 'E')
	{
		map->exitfound = 1;
		return (0);
	}
	path_check(map, y, x + 1, 0);
	path_check(map, y, x - 1, 0);
	path_check(map, y + 1, x, 0);
	path_check(map, y - 1, x, 0);
	if (map->exitfound == 1)
		return (1);
	return (0);
}

int	mapchecks(t_map *map)
{
	if (rectangular_check(map) == 0)
		return (mapfailed(1, map));
	if (tile_check(map) == 0)
		;
	if (map->playerfound != 1)
		return (mapfailed(2, map));
	if (map->collectiblefound <= 0)
		return (mapfailed(3, map));
	if (walls_check(map) == 0)
		return (mapfailed(4, map));
	if (path_check(map, map->pypos, map->pxpos, 1) == 0)
		return (mapfailed(5, map));
	return (1);
}
