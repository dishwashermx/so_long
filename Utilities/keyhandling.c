/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:43:40 by ghwa              #+#    #+#             */
/*   Updated: 2023/10/11 12:05:53 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	exit_win(t_map *map)
{
	ft_printf("bravo going dark\n");
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
	return (0);
}

int	close_win(int code, t_map *map)
{
	if (code == 7)
		ft_printf("congrats!\nyou won in %d steps\n", map->steps);
	if (code == 6)
		ft_printf("mission failed\n");
	if (code == 0)
		ft_printf("wasted\n");
	if (code == 8)
		ft_printf("Error\nrift in the fabric of spacetime\n");
	ft_printf("bravo going dark\n");
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
	return (0);
}

int	mapfailed(int code)
{
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
	if (code == 9)
		ft_printf("Error\nyour existence has too many purposes\n");
	if (code == 10)
		ft_printf("Error\nmap????\n");
	if (code == 11)
		ft_printf("Error\n.ber pls\n");
	return (0);
}

int	keyoutput(t_map *map, int code)
{
	if (code == 0)
		return (close_win(0, map));
	if (code == 3 && map->collectiblefound > 0)
		return (close_win(6, map));
	if (code == 3 && map->collectiblefound == 0)
		return (close_win(7, map));
	map->steps++;
	ft_printf("steps: %d\n", map->steps);
	return (0);
}

int	valid_file(int argc, char *file, t_map *map)
{
	char	*filename;

	filename = ft_strjoin("Maps/", file);
	map->fd = open(filename, O_RDONLY);
	if (map->fd == -1)
	{
		perror("Error");
		return (0);
	}
	if (argc == 1)
		return (mapfailed(10));
	if (argc > 2)
		ft_printf("only the first file would be used");
	if (!ft_strendcmp(file, ".ber"))
		return (mapfailed(11));
	return (1);
}
