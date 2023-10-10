/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:22:37 by ghwa              #+#    #+#             */
/*   Updated: 2023/10/10 14:15:32 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	w_key(t_map *map)
{
	if (map->map[map->pypos - 1][map->pxpos] == '1')
		return (0);
	if (map->map[map->pypos - 1][map->pxpos] == 'X')
		return (0);
	else if (map->map[map->pypos - 1][map->pxpos] == '$')
	{
		map->map[map->pypos--][map->pxpos] = 'X';
		map->map[map->pypos][map->pxpos] = 'P';
		map->collectiblefound--;
	}
	else if (map->map[map->pypos - 1][map->pxpos] == '.')
	{
		map->map[map->pypos--][map->pxpos] = 'X';
		map->map[map->pypos][map->pxpos] = 'P';
	}
	else if (map->map[map->pypos - 1][map->pxpos] == 'W')
		return (3);
	return (1);
}

int	a_key(t_map *map)
{
	if (map->map[map->pypos][map->pxpos - 1] == '1')
		return (0);
	if (map->map[map->pypos][map->pxpos - 1] == 'X')
		return (0);
	else if (map->map[map->pypos][map->pxpos - 1] == '$')
	{
		map->map[map->pypos][map->pxpos--] = 'X';
		map->map[map->pypos][map->pxpos] = 'P';
		map->collectiblefound--;
	}
	else if (map->map[map->pypos][map->pxpos - 1] == '.')
	{
		map->map[map->pypos][map->pxpos--] = 'X';
		map->map[map->pypos][map->pxpos] = 'P';
	}
	else if (map->map[map->pypos][map->pxpos - 1] == 'W')
		return (3);
	return (1);
}

int	s_key(t_map *map)
{
	if (map->map[map->pypos + 1][map->pxpos] == '1')
		return (0);
	if (map->map[map->pypos + 1][map->pxpos] == 'X')
		return (0);
	else if (map->map[map->pypos + 1][map->pxpos] == '$')
	{
		map->map[map->pypos++][map->pxpos] = 'X';
		map->map[map->pypos][map->pxpos] = 'P';
		map->collectiblefound--;
	}
	else if (map->map[map->pypos + 1][map->pxpos] == '.')
	{
		map->map[map->pypos++][map->pxpos] = 'X';
		map->map[map->pypos][map->pxpos] = 'P';
	}
	else if (map->map[map->pypos + 1][map->pxpos] == 'W')
		return (3);
	return (1);
}

int	d_key(t_map *map)
{
	if (map->map[map->pypos][map->pxpos + 1] == '1')
		return (0);
	if (map->map[map->pypos][map->pxpos + 1] == 'X')
		return (0);
	else if (map->map[map->pypos][map->pxpos + 1] == '$')
	{
		map->map[map->pypos][map->pxpos++] = 'X';
		map->map[map->pypos][map->pxpos] = 'P';
		map->collectiblefound--;
	}
	else if (map->map[map->pypos][map->pxpos + 1] == '.')
	{
		map->map[map->pypos][map->pxpos++] = 'X';
		map->map[map->pypos][map->pxpos] = 'P';
	}
	else if (map->map[map->pypos][map->pxpos + 1] == 'W')
		return (3);
	return (1);
}

int	keyinputs(int keycode, t_map *map)
{
	if (keycode == 53)
		close_win(map);
	if (keycode == 13)
		return (keyoutput(map, w_key(map)));
	if (keycode == 0)
		return (keyoutput(map, a_key(map)));
	if (keycode == 1)
		return (keyoutput(map, s_key(map)));
	if (keycode == 2)
		return (keyoutput(map, d_key(map)));
	return (0);
}
