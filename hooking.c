/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:27:32 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/16 19:18:54 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		printf("game ended\n");
		exit (0);
	}
	if (keycode == KEY_W)
		data->player->walk_direction = -1;
	else if (keycode == KEY_S)
		data->player->walk_direction = 1;
	else if (keycode == KEY_A)
		data->player->turn_direction = -1;
	else if (keycode == KEY_D)
		data->player->turn_direction = 1;
	else if (keycode == ARROW_LEFT)
		data->player->rotation_direction = -1;
	else if (keycode == ARROW_RIGHT)
		data->player->rotation_direction = 1;
	else if (keycode == SPACE)
		data->keystate->space = 1;
	return (0);
}

int	keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->player->walk_direction = 0;
	else if (keycode == KEY_S)
		data->player->walk_direction = 0;
	else if (keycode == KEY_A)
		data->player->turn_direction = 0;
	else if (keycode == KEY_D)
		data->player->turn_direction = 0;
	else if (keycode == ARROW_LEFT)
		data->player->rotation_direction = 0;
	else if (keycode == ARROW_RIGHT)
		data->player->rotation_direction = 0;
	else if (keycode == SPACE)
		data->keystate->space = 0;
	return (0);
}

int update(t_data *data)
{
	drawing(data);
	return 0;
}

void	hooking(t_mlx *mlx, t_data *data)
{
	mlx_hook(mlx->win, 02, 00, &keypress, data);
	mlx_hook(mlx->win, 03, 0L, &keyrelease, data);
	mlx_loop_hook(mlx->mlx, &update, data);
	mlx_loop(data->mlx->mlx);
}

