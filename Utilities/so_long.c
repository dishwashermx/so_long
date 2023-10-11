/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:48:00 by ghwa              #+#    #+#             */
/*   Updated: 2023/10/11 12:07:31 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (valid_file(argc, argv[1], &map) == 0)
		return (0);
	map.mlx = mlx_init();
	initpaths(&map);
	if (mapchecks(&map) == 0)
		return (0);
	map.mlx_win = mlx_new_window(map.mlx, map.map_w * 32, \
	map.map_h * 32, "so_long");
	initmap(&map);
	mlx_key_hook(map.mlx_win, keyinputs, &map);
	mlx_hook(map.mlx_win, 17, 0, exit_win, &map);
	mlx_loop_hook(map.mlx, (void *)initmap, &map);
	mlx_loop(map.mlx);
	system("leaks so_long");
	return (0);
}
