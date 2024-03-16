/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:26:22 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/15 23:23:55 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

// int	check_cell_type(t_ray *ray, t_position position)
// {
// 	calcul_cells(ray);
// 	check_skip(ray, position);
// 	if (!(ray->h_skip) \
// 			&& (position.map->map_tab[ray->ycell_h][ray->xcell_h] == '1' || \
// 			position.map->map_tab[ray->ycell_h][ray->xcell_h] == 'C'))
// 		ray->h_hit = INTERSECTION_FOUND; 
// 	if ((!(ray->v_skip) && \
// 			(position.map->map_tab[ray->ycell_v][ray->xcell_v] == '1' || \
// 			position.map->map_tab[ray->ycell_v][ray->xcell_v] == 'C')))
// 		ray->v_hit = INTERSECTION_FOUND;
// 	if (ray->v_hit && ray->h_hit)
// 		return (INTERSECTION_FOUND);
// 	if (ray->h_hit && ray->v_skip)
// 		return (INTERSECTION_FOUND);
// 	if (ray->v_hit && ray->h_skip)
// 		return (INTERSECTION_FOUND);
// 	return (0);
// }

// void	send_ray(t_data *data, t_ray *ray, t_position position)
// {
// 	int	inter;

// 	inter = 0;
// 	while (1)
// 	{
// 		inter = check_cell_type(ray, position);
// 		if (inter == INTERSECTION_FOUND)
// 			return (calcul_distance(table, ray, position));
// 		if (!(ray->v_hit) && !(ray->v_skip))
// 		{
// 			ray->xbound += ray->x_step;
// 			calcul_next_v_inter(table, ray, position);
// 		}
// 		if (!(ray->h_hit) && !(ray->h_skip))
// 		{
// 			ray->ybound += ray->y_step;
// 			calcul_next_h_inter(table, ray, position);
// 		}
// 	}
// }


