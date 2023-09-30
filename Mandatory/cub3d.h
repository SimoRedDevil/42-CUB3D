/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:29:53 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 12:04:29 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

/*========================= ERROR MESSAGES =========================*/
# define MAP_ERROR "Error: something is wrong in the map"
# define TEXTURE_ERROR "Error: something is wrong in the textures"
# define INVALID_COLOR "Error: color is not valid"
# define MALLOC_ERROR "Error: malloc failed"
# define COLOR_ERROR "Error: something is wrong in the colors"
# define EXTENSION_ERROR "Error: map extension is not valid"
# define ARGS_ERROR "Error: number of args is not valid"
# define MAP_NOT_CLOSED "Error: map is not closed"
# define PLAYER_ERROR "Error: map must contain one player"
# define BAD_CHAR_ERROR "Error: map contains bad characters"
# define MAP_EMPTY_LINE "Error: map contains empty line"
# define FILE_ERROR "Error: file is not valid"
# define MLX_NEW_IMG_ERROR "Error: mlx_new_image failed"
# define MLX_XPM_FILE_TO_IMG_ERROR "Error: mlx_xpm_file_to_image failed"
# define IMG_SIZE_ERROR "Error: image size is not valid"

/*========================= GAME CONSTANTS =========================*/
# define SCALE_SIZE 32
# define SPEED 3
# define KEYBOARD_ROTSPEED 2.5
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

typedef struct s_garbage	t_garbage;
typedef struct s_data		t_data;
typedef struct s_texture	t_texture;
typedef struct s_mlx		t_mlx;
typedef struct s_image		t_image;
typedef struct s_color		t_color;
typedef struct s_player		t_player;
typedef struct s_ray		t_ray;
typedef struct s_flags		t_flags;

enum e_keys
{
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125
};

struct s_garbage
{
	void		*address;
	t_garbage	*next;
	t_garbage	*last;
};

struct s_texture
{
	char		*key;
	char		*value;
	float		x_offset;
	float		y_offset;
	int			xpm_width;
	int			xpm_height;
	t_image		*texture_img;
	t_texture	*next;
	t_texture	*last;
};

struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
};

struct s_image
{
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			line_length;
	int			endian;
};

struct s_player
{
	float	x;
	float	y;
	float	angle;
	float	fov;
	float	dis_proj_player;
};

struct s_ray
{
	float	ray_angle;
	bool	ray_looking_down;
	bool	ray_looking_right;
	float	y_horz_int;
	float	x_horz_int;
	float	y_vert_int;
	float	x_vert_int;
	float	horz_dist;
	float	vert_dist;
	float	y_step;
	float	x_step;
	int		hit_vert_horz;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
};

struct s_flags
{
	bool	move_up;
	bool	move_down;
	bool	move_left;
	bool	move_right;

	bool	rotate_left;
	bool	rotate_right;

	bool	redraw_scene;
};

struct s_data
{
	t_mlx		*mlx;
	t_image		*window_img;

	t_texture	*textures;
	int			celling_color;
	int			floor_color;

	char		**map;
	float		half_screen;
	int			map_width;
	int			map_height;

	t_player	*player;
	t_ray		*ray;
	t_flags		*flags;
};

/*-----------------------------g_collector.c-----------------------------*/
void		add_to_garbage(t_garbage **heap, void *address);
void		empty_trash(t_garbage **heap);
t_garbage	**g_heap(void);

/*-----------------------------cub3d_utils.c-----------------------------*/
void		throw_error(char *msg, t_garbage **heap);
int			ft_strcmp(char *s1, char *s2);
int			tab_size(char **tab);
char		*free_s1_join(char *s1, char *s2);
void		free_tab(char **tab);

/*-----------------------------map_reader.c-----------------------------*/
void		read_map(char *path, t_data *data);

/*-----------------------------init_data.c-----------------------------*/
void		init_data(t_data *data, char *path);

/*-----------------------------texture_parser.c-----------------------------*/
void		fill_tetxures_list(t_data *data, char *key, char *value);
void		textures_checker(t_data	*data);

/*-----------------------------color_parser.c-----------------------------*/
int			get_color(char *value);
void		fill_color(t_data *data, char *key, char *value);
void		color_checker(t_data *data);

/*-----------------------------parsing_utils.c-----------------------------*/
bool		is_player(char c);
bool		contains_bad_char(char *str);
void		contains_player(char *str, int *p);

/*-----------------------------map_parser.c-----------------------------*/
void		map_checker(char **map);

/*-----------------------------my_mlx_func.c-----------------------------*/
void		my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
void		*my_mlx_new_img(t_data *data, int width, int height);
void		my_mlx_destroyer(t_data *data);
void		my_pixel_put(t_texture *data, int x, int y, int *color);
void		*my_mlx_xpm_file_to_img(t_data *data, char *path,
				int *width, int *height);

/*-----------------------------init_mlx.c-----------------------------*/
t_mlx		*init_mlx(void);
t_image		*init_win_image(t_data *data);

/*-----------------------------init_player.c-----------------------------*/
t_player	*init_player(t_data *data);

/*-----------------------------info_getter.c-----------------------------*/
int			*get_player_coord(char **map);
int			get_map_width(char **map);
int			get_map_height(char **map);

/*-----------------------------raycasting_utils.c-----------------------------*/
float		adjust_angle(float ray_angle);
void		check_horz_intersection(t_data *data, float ray_angle);
void		check_vert_intersection(t_data *data, float ray_angle);

/*-----------------------------raycasting.c-----------------------------*/
void		cast_all_rays(t_data *data);

/*-----------------------------draw_walls.c-----------------------------*/
void		colorize_window(t_data *data);
void		wall_drawing(int x, float height, t_data *data);
void		clear_window_draw(t_data *data);

/*-----------------------------move_player.c-----------------------------*/
int			move_player(t_data *data);
bool		check_wall(t_data *data, float x, float y);
void		move_right(t_data *data);
void		move_left(t_data *data);
void		move_up(t_data *data);
void		move_down(t_data *data);

/*-----------------------------rotation.c-----------------------------*/
void		rotate_left(t_data *data);
void		rotate_right(t_data *data);

/*-----------------------------drawing_utils.c-----------------------------*/
void		my_pixel_put(t_texture *data, int x, int y, int *color);
t_texture	*get_value(t_texture *texture, char *key);
void		get_texture_offset(t_data *data, t_texture *texture,
				float wall_height, float y_top);
#endif