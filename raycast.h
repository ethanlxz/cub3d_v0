#pragma once

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h> 
# include <math.h>
# include <errno.h>
# include <signal.h>
# include <stdbool.h>
# include <stdint.h>

# define PLAYER_SCALE 3
# define WIN_W 1080 // screen width
# define WIN_H 520 // screen height
# define CELL_SIZE 500
# define RAY_ANGLE_DIFF 0.05555555555 // each ray distance within player pov (60 / 1080)
# define MAX_DEPTH 100
# define N_RAY 1080 // number of ray being casted

# define ERROR "\033[1;31m"
# define GREEN "\033[0;32m" 
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

enum
{
	KEY_A = 0,
	KEY_D = 2,
	KEY_S = 1,
	KEY_W = 13,
	ESC = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	SPACE = 49
};

typedef struct s_iterators
{
	int	i;
	int	j;
}	t_iterators;


typedef struct s_keystate
{
	int	tir;
	int	w;
	int	a;
	int	s;
	int	d;
	int	r;
	int	l;
	int	space;
	int	esc;
}	t_keystate;

typedef struct s_mlx
{
	void		*mlx;
	void		*img;
	void		*win;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_mlx;

// typedef struct s_position
// {
// 	int		x_cell;
// 	int		y_cell;
// 	double	virtual_px;
// 	double	virtual_py;
// 	double	pov;
// 	char	**map;
// }	t_position;

typedef struct s_coords
{
	float	x;
	float	y;
}	t_coords;


typedef struct s_ray
{
	t_coords	wall_hit;
	float		angle;
	float		depth;
	bool		vertical_hit;
	int			content_hit;
	float		sin_a;
	float		cos_a;
	t_coords	horz_inters;
	t_coords	vert_inters;
	float		depth_horz;
	float		depth_vert;
	float		horz_wall_content;
	float		vert_wall_content;
	float		proj_h;
}	t_ray;

typedef struct s_player
{
	t_coords	pos; // actual player postion in pixel
	int			map_pos_x; // map player position
	int			map_pos_y;
	int			width;
	int			height;
	float		angle; // player pov
	float		speed;
	float		rot_speed;
	int			turn_direction; // Keys A D ARROW_LEFT ARROW_RIGHT
	int			walk_direction; // Keys W S
	int			rotation_direction;
	char		**map;
}	t_player;


typedef struct s_constants
{
	float	frame_rate;
	float	half_win_width;
	float	half_win_height;
	float	fov;
	float	half_fov;
	float	screen_dist;
	int		num_rays;
	float	half_num_rays;
	float	scale;
	float	delta_angle;
	float	player_rotation_speed;
	float	tau;
}	t_constants;


typedef struct s_data
{
	t_mlx			*mlx;
	t_keystate		*keystate;
	t_player		*player;
	t_ray			*rays;
	t_constants		*constant;
	char			**map; // actual map
	int				map_w; // set map height and width
	int				map_h;
	int				cell_size;

}	t_data;


// libft.c (tools for cub3d)
int	ft_strchr(char c, char *s);
int	ft_is_whitespace(int c);

// test.c (for testing tools)
char	**map_dup();
void print_img(t_data *data);
void print_arr(char **arr);

//init.c 
void init(t_data *data);

//keyboard.c
void	hooking(t_mlx *mlx, t_data *data);

// drawing.c
void drawing(t_data *data);

// raycast.c
void	raycast(t_data *data);