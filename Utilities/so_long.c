/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:48:00 by ghwa              #+#    #+#             */
/*   Updated: 2023/10/10 10:44:09 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

int	main(void)
{
	t_map	map;

	map.fd = open("Maps/map1.ber", O_RDONLY);
	initpaths(&map);
	if (mapchecks(&map) == 0)
		return (0);
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, 1920, 1080, "so_long");
	initmap(&map);
	mlx_key_hook(map.mlx_win, keyinputs, &map);
	mlx_hook(map.mlx_win, 17, 0, close_win, &map);
	mlx_loop_hook(map.mlx, (void *)initmap, &map);
	mlx_loop(map.mlx);
	return (0);
}
