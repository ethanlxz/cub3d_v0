/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:12:46 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/18 22:07:07 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	init_player_pos(char **map, t_player *player, char pv)
{
	// sets the player view
	if (pv == 'N')
		player->angle = 3 * M_PI;
	else if (pv == 'E')
		player->angle = 2 * M_PI;
	else if (pv == 'S')
		player->angle = M_PI / 2;
	else if (pv == 'W')
		player->angle = M_PI;
	// x and y cell sets where the player is inside the map
	player->map_pos_x = 6;
	player->map_pos_y = 6;
	// sets the actual position by pixel of player
	player->pos.x = (player->map_pos_x * CELL_SIZE) + (CELL_SIZE / 2);
	player->pos.y = (player->map_pos_y * CELL_SIZE) + (CELL_SIZE / 2);
	// sets the actual map
	player->map = map;
}

//keystate could be removed
void	init_keystate(t_keystate	*keystate)
{
	keystate->w = 0;
	keystate->a = 0;
	keystate->s = 0;
	keystate->d = 0;
	keystate->l = 0;
	keystate->r = 0;
	keystate->tir = 0;
	keystate->space = 0;
	keystate->esc = 0;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "cub3D");
	mlx->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

void	init_constants(t_data *data)
{
	// data->constants->frame_rate = 1000 / FPS;
	data->constant->half_win_width = WIN_W / 2;
	data->constant->half_win_height = WIN_H / 2;
	data->constant->fov = 60 * (M_PI / 180); // fov is 60 degree in radian
	data->constant->half_fov = data->constant->fov / 2;
	data->constant->screen_dist = WIN_W / 2 / tan(data->constant->half_fov);
	data->constant->num_rays = WIN_W; // 1080 of rays
	data->constant->half_num_rays = data->constant->num_rays / 2;
	data->constant->scale = WIN_W / data->constant->num_rays;
	data->constant->delta_angle = data->constant->fov / data->constant->num_rays;
	data->constant->player_rotation_speed = 90 * (M_PI / 180);
	data->constant->tau = 2 * M_PI;
}


void init(t_data *data)
{
	t_mlx		mlx;
	t_keystate	keystate;
	t_player	player;
	t_ray		*ray;
	t_constants constant;

	data->cell_size = CELL_SIZE;
	data->mlx = &mlx;
	ray = malloc(sizeof(t_ray) * N_RAY);
	data->rays = ray;
	data->keystate = &keystate;
	data->player = &player;
	data->constant = &constant;
	// need parser to set height and width on the map
	data->map_w = 11;
	data->map_h = 11;
	
	// init_player needs more changes
	init_constants(data);
	init_player_pos(data->map, &player, 'N'); // need the parser to put which direction the player is at
	init_mlx(&mlx);
	init_keystate(&keystate);
	hooking(&mlx, data);
}