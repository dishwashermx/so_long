/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:43:40 by ghwa              #+#    #+#             */
/*   Updated: 2023/10/10 12:27:32 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	close_win(t_map *map)
{
	ft_printf("extracting agent\n");
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
	return (0);
}

int	mapfailed(int code, t_map *map)
{
	if (code == 0)
		ft_printf("wasted\n");
	if (code == 1)
		ft_printf("Error\nMap is too slay need to be more like []\n");
	if (code == 2)
		ft_printf("Error\nwya my guy\n");
	if (code == 3)
		ft_printf("Error\nur poor\n");
	if (code == 4)
		ft_printf("Error\nmans playing open world\n");
	if (code == 5)
		ft_printf("Error\nyour existence has no purpose\n");
	if (code == 6)
	{
		ft_printf("Error\nmission failed\n");
		close_win(map);
	}
	if (code == 7)
	{
		ft_printf("congrats ig you won in %d steps\n", map->steps);
		close_win(map);
	}
	return (0);
}


int	keyoutput(t_map *map, int code)
{
	if (code == 0)
		return (mapfailed(0, map));
	if (code == 3 && map->collectiblefound > 0)
		return (mapfailed(6, map));
	if (code == 3 && map->collectiblefound == 0)
		return (mapfailed(7, map));
	map->steps++;
	ft_printf("%d\n", map->steps);
	return (0);
}
