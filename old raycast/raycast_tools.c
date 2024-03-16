/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:31:36 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/13 19:53:03 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double calc_trigo(int i, int trigo)
{
	double	angle;
	double	ang_in;
	double  res;

	ang_in = RAY_ANGLE_DIFF * M_PI / 180.0;
	angle = i * ang_in;
	if (trigo == 1)
	{
		res = sin(angle);
		return (res);
	}
	else if (trigo == 2)
	{
		res = cos(angle);
		return (res);
	}
	else if (trigo == 3)
	{
		res = tan(angle);
		return (res);
	}
	else
		return 0;
}

double	calc_adjacent(double hypotenuse, double opposite)
{
	double	adjacent;

	adjacent = opposite / hypotenuse;
	return (adjacent);
}


double	calc_opposite(double hypotenus, double adjacent)
{
	double	opposite;

	opposite = hypotenus * adjacent;
	return (opposite);
}