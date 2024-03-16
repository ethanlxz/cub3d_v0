/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:03:46 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/16 18:46:10 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

// for strdup
#include <string.h>

char	**map_dup()
{
	char	**map;
	// char default_map[11][11] = 
	// {
	// 	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	// };

	map = malloc(sizeof(char *) * (11 + 1));
	if (map == NULL)
		return (NULL);
	map[0] = strdup("11111111111");
	map[1] = strdup("10000000001");
	map[2] = strdup("10010000101");
	map[3] = strdup("10000000001");
	map[4] = strdup("10000000001");
	map[5] = strdup("11100000001");
	map[6] = strdup("10000000001");
	map[7] = strdup("10000000001");
	map[8] = strdup("10000000001");
	map[9] = strdup("10100000101");
	map[10] = strdup("11111111111");
	map[11] = 0;

	// int i = -1;
	// while (map[++i])
	// 	printf("%s\n", map[i]);
	return (map);
}

typedef struct s_image {
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
} t_image;

void put_pixel(t_image *img, int x, int y, int color) 
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}

void print_img(t_data *data)
{
	t_image	image;
	int		img_w;
	int		img_h;
	int 	x;
	int		y;
	char	*relative_path = "./img/img.xpm";

	image.img = mlx_xpm_file_to_image(data->mlx->mlx, relative_path, &img_w, &img_h);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_length, &image.endian);

	for (y = 0; y < WIN_H; y++) 
	{
        for (x = 0; x < WIN_W; x++) 
		{
            put_pixel(&image, x, y, *(unsigned int *)(image.addr + (y * image.line_length + x * (image.bpp / 8))));
        }
    }
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, image.img, 0, 0);
}

void print_arr(char **arr)
{
	int x;
	int y;
	y = 0;
	while (arr[y])
	{
		x = 0;
		while(arr[y][x])
		{
			printf("%c", arr[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}