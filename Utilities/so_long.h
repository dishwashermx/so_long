/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:48:04 by ghwa              #+#    #+#             */
/*   Updated: 2023/10/18 09:58:25 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_map {
	int		img_width;
	int		img_height;
	int		fd;
	int		map_w;
	int		map_h;
	int		validmap;
	int		exitfound;
	int		exitpathfound;
	int		collectiblefound;
	int		playerfound;
	int		steps;
	int		pxpos;
	int		pypos;
	void	*mlx;
	void	*img_fruit;
	void	*img_house;
	void	*img_p;
	void	*img_water;
	void	*img_grass;
	void	*img_dirt;
	char	*water;
	char	*dirt;
	char	*grass;
	char	*player;
	void	*apple;
	char	*house;
	void	*mlx_win;
	char	**map;
	char	*temp_map;
	char	test;
	int		ufo;
}	t_map;

int		initpaths(t_map *map);
void	initmap(t_map *map);
int		mapchecks(t_map *map);
int		close_win(int code, t_map *map);
int		exit_win(t_map *map);
int		keyinputs(int keycode, t_map *map);
int		mapfailed(int code);
int		keyoutput(t_map *map, int code);
int		valid_file(int argc, char *file, t_map *map);
int		real_tile(char tile);

#endif