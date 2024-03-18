/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:42:58 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/18 22:32:20 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_mlx_put_px(t_mlx *mlx, int x, int y, unsigned long color)
{
	char	*dst;

	if (x >= WIN_W || y >= WIN_H || x < 0 || y < 0)
		return ;
	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	color_sqr(t_data *data, int x, int y, unsigned int color)
{
	int	xc;
	int	yc;

	xc = 0;
	while (xc <= data->cell_size)
	{
		yc = 0;
		while (yc <= data->cell_size)
		{
			if (yc == 0 || xc == 0)
				ft_mlx_put_px(data->mlx, xc + (data->cell_size * x),
					yc + (data->cell_size * y), 0x0);
			else
				ft_mlx_put_px(data->mlx, xc + (data->cell_size * x),
					yc + (data->cell_size * y), color);
			if ((data->player->map_pos_x == x) && (data->player->map_pos_y == y))
			{
				// printf("%f = player x \n", data->player->pos.x );
				// printf("%f = player y \n", data->player->pos.y );
				ft_mlx_put_px(data->mlx, data->player->pos.x / data->cell_size,
					data->player->pos.y / data->cell_size, 0xff0000);
				ft_mlx_put_px(data->mlx, data->player->pos.x / data->cell_size + 1,
					data->player->pos.y / data->cell_size, 0xff0000);
				ft_mlx_put_px(data->mlx, data->player->pos.x / data->cell_size,
					data->player->pos.y / data->cell_size + 1, 0xff0000);
					ft_mlx_put_px(data->mlx, data->player->pos.x / data->cell_size + 1,
					data->player->pos.y / data->cell_size + 1, 0xff0000);
			}
			yc++;
		}
		xc++;
	}
}

void	ft_color_win(t_data *data, t_mlx *mlx, int ray_h)
{
	(void)data;
	int	x;
	int	y;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			if (y > WIN_H / 2 + ray_h)
			{
				ft_mlx_put_px(mlx, x, y, 0x00f310);
				y++;
			}
			else
			{
				ft_mlx_put_px(mlx, x, y, 0x00f310);
				y++;
			}
		}
		x++;
	}
}

void	put_map(t_data *data)
{
	int	x;
	int	y;
	
	if (data->keystate->space)
		data->cell_size = WIN_W / 40; // how big the minimap will expand
	else
		data->cell_size = 10; // else minimap will be this big
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			// add C for door
			if (ft_strchr(data->map[y][x], "1"))
				color_sqr(data, x, y, 0x0);
			else if (ft_strchr(data->map[y][x], "0"))
				color_sqr(data, x, y, 0xd0d0d0);
			x++;
		}
		y++;
	}
	// put_rays(data, (double)CELL_SIZE / data->cell_size);
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->win, data->mlx->img, 0, 0);
}

void drawing(t_data *data)
{
	raycast(data); // cast rays
	// print_img(data); // still testing
	ft_color_win(data, data->mlx, 0); // colours green for the whole map
	put_map(data); // puts minimap
}

