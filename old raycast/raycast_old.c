/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_old.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:47:11 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/15 23:21:17 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

// double	calcul_ray_pov(t_position *pos, int ray)
// {
// 	double	ray_pov;
// 	double	first_ray_angle;

// 	first_ray_angle = pos->pov - 30;
// 	ray_pov = first_ray_angle + ray * RAY_ANGLE_DIFF;
// 	if (ray_pov >= 360)
// 		ray_pov = ray_pov - 360;
// 	else if (ray_pov < 0)
// 		ray_pov = ray_pov + 360;
// 	return (ray_pov);
// }

// int	calcul_ray_angle(t_ray *ray, double ray_pov)
// {
// 	int		index;
// 	double	ray_angle;

// 	ray_angle = ray_pov;
// 	ray->quadrant = 1;
// 	if (ray_pov >= 90 && ray_pov < 180)
// 	{
// 		ray->quadrant = 2;
// 		ray_angle = ray_pov - 90.0;
// 	}
// 	else if (ray_pov >= 180 && ray_pov < 270)
// 	{
// 		ray->quadrant = 3;
// 		ray_angle = ray_pov - 180.0;
// 	}
// 	else if (ray_pov >= 270 && ray_pov < 360)
// 	{
// 		ray->quadrant = 4;
// 		ray_angle = ray_pov - 270.0;
// 	}
// 	index = ray_angle / RAY_ANGLE_DIFF;
// 	return (index);
// }

// // side can be oppotenuse or adjacent depending on the quadrant
// void	calcul_first_vertical(t_ray *ray, t_position *pos)
// {
// 	double	diff;
// 	double	side;

// 	diff = pos->virtual_py;
// 	side = 0.0;
// 	if (ray->ray_pov < 180 && ray->ray_pov >= 0)
// 	{
// 		ray->xbound = CELL_SIZE * (pos->x_cell + 1);
// 		ray->x_step = CELL_SIZE;
// 		side = ray->xbound - pos->virtual_px;
// 	}
// 	else
// 	{
// 		ray->xbound = CELL_SIZE * pos->x_cell;
// 		ray->x_step = CELL_SIZE * (-1.0);
// 		side = pos->virtual_px - ray->xbound;
// 	}
// 	if (ray->quadrant == 1 || ray->quadrant == 3)
// 		ray->yi = calcul_adjacent(calc_trigo(ray->index, TAN), side);
// 	else
// 		ray->yi = calcul_opposite(calc_trigo(ray->index, TAN), side);
// 	if (ray->quadrant == 4 || ray->quadrant == 1)
// 		ray->yi = diff - ray->yi;
// 	else
// 		ray->yi = diff + ray->yi;
// }

// void	calcul_first_horizontal(t_ray *ray, t_position *pos)
// {
// 	double	diff;
// 	double	side;

// 	diff = pos->virtual_px;
// 	side = 0.0;
// 	if (ray->ray_pov > 270 || ray->ray_pov <= 90)
// 	{
// 		ray->y_step = CELL_SIZE * (-1.0);
// 		ray->ybound = pos->y_cell * CELL_SIZE;
// 		side = pos->virtual_py - ray->ybound;
// 	}
// 	else
// 	{
// 		ray->y_step = CELL_SIZE;
// 		ray->ybound = (pos->y_cell + 1) * CELL_SIZE;
// 		side = ray->ybound - pos->virtual_py;
// 	}
// 	if (ray->quadrant == 2 || ray->quadrant == 4)
// 		ray->xi = calcul_adjacent(calc_trigo(ray->index, TAN), side);
// 	else
// 		ray->xi = calcul_opposite(calc_trigo(ray->index, TAN), side);
// 	if (ray->quadrant == 3 || ray->quadrant == 4)
// 		ray->xi = diff - ray->xi;
// 	else
// 		ray->xi = diff + ray->xi;
// }

// void init_rays(int i, t_data *data, t_ray **rays)
// {
// 	rays[i]->ray_pov = calcul_ray_pov(data->pos, i);
// 	rays[i]->index = calcul_ray_angle(&rays[i], rays[i]->ray_pov);
// 	calcul_first_vertical(&rays[i], data->pos);
// 	calcul_first_horizontal(&rays[i], data->pos);
// 	rays[i]->door = 0;
// 	rays[i]->h_hit = 0;
// 	rays[i]->v_hit = 0;
// 	rays[i]->h_skip = 0;
// 	rays[i]->v_skip = 0;
// 	rays[i]->first = 0;
// }

// void	casting_rays(t_ray *rays, t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < N_RAY)
// 	{
// 		init_rays(i, data, data->ray);
// 		send_ray(data, &rays[i], data->pos);
// 		i++;
// 	}
// }
