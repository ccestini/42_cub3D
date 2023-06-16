/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:54:44 by mkovoor           #+#    #+#             */
/*   Updated: 2023/05/10 13:43:24 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		key_handler(int keycode, t_game *game);
int		ft_init_buffer(t_game *game);
int		ft_start(t_game *game);

int	key_handler(int keycode, t_game *game)
{	
	if (keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
		ft_rotate(game, keycode);
	if (keycode == KEY_A || keycode == KEY_D \
			|| keycode == KEY_W || keycode == KEY_S \
			|| keycode == KEY_ARROW_UP || keycode == KEY_ARROW_DOWN)
		ft_move(game, keycode);
	if (keycode == KEY_ESC || keycode == 12)
		ft_end_game(game);
	ft_init_buffer(game);
	return (0);
}

int	ft_init_buffer(t_game *game)
{
	ft_draw_floor_ceiling(game);
	ft_start(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	ft_start(t_game *game)
{
	double	angle_increase;
	double	distance_to_wall;
	int		slice_count;
	double	beta;

	game->texel_color = NULL;
	slice_count = -1;
	angle_increase = FOV / SCREEN_W;
	game->ray_angle = ft_limit_angle(game->p_angle +(FOV * 0.5));
	while (++slice_count < SCREEN_W)
	{
		beta = ft_degree_to_radian(ft_limit_angle(game->ray_angle - \
									game->p_angle));
		distance_to_wall = ft_check_walls(game);
		distance_to_wall = distance_to_wall * cos(beta);
		ft_map_slice(game, distance_to_wall, slice_count);
		game->ray_angle = ft_limit_angle(game->ray_angle - angle_increase);
	}
	return (0);
}
