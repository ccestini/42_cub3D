/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:35:19 by ccestini          #+#    #+#             */
/*   Updated: 2023/05/10 15:59:48 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SIZE_TITLE 64.0
# define SCREEN_W 640
# define SCREEN_H 400
# define TEXWIDTH 64.0
# define TEXHEIGHT 64.0
# define FOV 60.0
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124
# define KEY_ARROW_UP 126
# define KEY_ARROW_DOWN 125

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include<limits.h>
# include<string.h>

typedef struct s_point
{
	double	x;
	double	y;
}t_point;

typedef struct s_map
{
	char	**tmp_file;
	int		height;
	int		width;
	int		nbr_map_chars;
	int		count_p;
	int		player_position;
	int		dist_to_projection;
	char	player_orientation;
	int		count_1;
	int		count_0;
	char	*filename;
	char	*map_str;
	char	**map2d;
	char	*texture_path_north;
	char	*texture_path_south;
	char	*texture_path_west;
	char	*texture_path_east;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	int		nbr_elements_file;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;

	void	*img1;
	char	*addr1;
	int		bpp1;
	int		line1;
	int		endian1;

	void	*img2;
	char	*addr2;
	int		bpp2;
	int		line2;
	int		endian2;

	void	*img3;
	char	*addr3;
	int		bpp3;
	int		line3;
	int		endian3;

	void	*img4;
	char	*addr4;
	int		bpp4;
	int		line4;
	int		endian4;

	double	p_angle;
	double	ray_angle;

	double	p_dx;
	double	p_dy;
	double	p_radius;
	t_point	p_position;

	t_point	wall_hit;
	t_point	wall_h;
	t_point	wall_v;
	double	dist_h;
	double	dist_v;
	double	dist_wall;
	int		side;
	double	proj_h;
	int		grid_offset;
	int		texture_offset_x;
	int		texture_offset_y;
	char	*texel_color;
	int		dist_from_top;
	double	wall_projected;
	int		top;
	int		bottom;

	int		floor_color;
	int		ceiling_color;
}	t_game;

/* Parte 1 - Init structs and free*/
void	ft_init_tmap(t_map *map, char *av[]);
void	ft_free_tmap(t_map *map);
void	ft_free_2d_array(char **str);

/* Parte 2 - Get Scene from cub file */
void	ft_read_file(t_map *map);
void	ft_copy_file(t_map *map);
void	ft_scan_elements(t_map *map);
int		ft_scan_headers(t_map *map, char *line);
int		ft_open(char *filename);
int		ft_check_line_is_map(t_map *map, char *line);
void	ft_check_nbr_elements(t_map *map, int nbr);

void	ft_load_map(t_map *map, int i);
int		ft_count_all_map_chars(t_map *map, int i);
int		ft_copy_map(t_map *map, int i);
void	ft_check_after_map(t_map *map, int i);
int		ft_count_map_contents(t_map *map);
int		ft_find_player_position(t_map *map);
void	ft_make_map_rectangle(t_map *map);
void	ft_fill_map_with_spaces(t_map *map, char *new_map, int len, int j);

void	ft_get_texture_no(char *line, char **strs, t_map *map);
void	ft_get_texture_so(char *line, char **strs, t_map *map);
void	ft_get_texture_we(char *line, char **strs, t_map *map);
void	ft_get_texture_ea(char *line, char **strs, t_map *map);

void	ft_get_color_f(char **strs, char *line, t_map *map);
void	ft_get_color_c(char **strs, char *line, t_map *map);
void	ft_color_exit_free(t_map *map, char *line, char **strs);
void	ft_fill_rgb_floor(t_map *map, char **strs2);
void	ft_fill_rgb_ceiling(t_map *map, char **strs2);
void	ft_check_commas(t_map *map, char *line, char **strs);

/* Parte 3 - Check Scene from cub file */
int		ft_check_file(t_map *map);

int		ft_is_valid_map(t_map *map);
int		ft_valid_file_extension(char *filename, char *filetype);
int		ft_valid_chars(t_map *map);
int		ft_valid_rectangle(t_map *map);
int		ft_valid_inner_walls(t_map *map);
int		ft_valid_outer_walls(t_map *map);
int		ft_check_emptyspace_neighbors(t_map *map, int i, int w, int len);
int		ft_walls_check_row_top_bottom(t_map *map, int i, int last);
int		ft_walls_check_column_left_right(t_map *map, int i);

int		ft_valid_texture(t_map *map, char *tex_path, char *tex_id);
int		ft_valid_color(t_map *map, int colors[], char *color_element);

/* Parte 4 - Play Game */
void	ft_init_player(t_game *game);
void	ft_set_angle(t_game *game);

int		key_handler(int keycode, t_game *game);
int		ft_init_buffer(t_game *game);
int		ft_start(t_game *game);

int		ft_move(t_game *game, int keycode);
void	ft_rotate(t_game *game, int keycode);
void	ft_get_checkpoints(t_game *game, int keycode, t_point *check);

int		ft_map_slice(t_game *game, double distance_to_wall, int slice_count);
void	ft_map_slice_side0(t_game *game, char *tc, int slice_count, int y);
void	ft_map_slice_side1(t_game *game, char *tc, int slice_count, int y);
void	ft_get_top_bottom(t_game *game);
void	ft_get_text_offset(t_game *game);

double	ft_check_walls(t_game *game);
int		ft_intersect_h(t_game *game, t_point *intersect, t_point *delta);
int		ft_intersect_v(t_game *game, t_point *intersect, t_point *delta);
double	ft_check_horizontal_hit(t_game *game);
double	ft_check_vertical_hit(t_game *game);

void	ft_init_textures(t_game *game);
int		ft_check_limits(t_game *game, int x, int y);
void	my_pixel_put(t_game *game, int x, int y, int colour);
int		ft_get_rgb(int red, int green, int blue);
void	ft_draw_floor_ceiling(t_game *game);

void	ft_end_game(t_game *game);

/* Parte 5 - Maths */
double	ft_degree_to_radian(double degree);
double	ft_radian_to_degree(double radian);
double	ft_limit_angle(double angle);
double	ft_get_hyp(double x0, double x1, double y0, double y1);

/* Parte 6 - Utils */
void	ft_print_2darray(char **str);
int		ft_is_whitespace(char c);
int		ft_is_empty(char *str);
void	ft_print_map_and_info(t_map *map);
double	ft_degree_to_radian(double degree);
double	ft_radian_to_degree(double radian);

char	**ft_split2(char const *s, char c);

#endif
