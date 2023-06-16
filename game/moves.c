/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:43:01 by mkovoor           #+#    #+#             */
/*   Updated: 2023/05/10 13:45:17 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_move(t_game *game, int keycode);
void	ft_rotate(t_game *game, int keycode);
void	ft_get_checkpoints(t_game *game, int keycode, t_point *check);

int	ft_move(t_game *game, int keycode)
{
	int		x;
	int		y;
	t_point	check;

	ft_get_checkpoints(game, keycode, &check);
	x = (int)(check.x / SIZE_TITLE);
	y = (int)(check.y / SIZE_TITLE);
	if (game->map->map_str[(int)(y * (game->map->width + 1) + x)] == '0')
	{
		game->p_position.x = check.x;
		game->p_position.y = check.y;
		return (0);
	}
	else
		return (-1);
}

void	ft_rotate(t_game *game, int keycode)
{
	if (keycode == KEY_ARROW_LEFT)
	{
		game->p_angle = ft_limit_angle(game->p_angle + 5);
		game->p_dx = cos(ft_degree_to_radian(game->p_angle));
		game->p_dy = -sin(ft_degree_to_radian(game->p_angle));
	}
	if (keycode == KEY_ARROW_RIGHT)
	{
		game->p_angle = ft_limit_angle(game->p_angle - 5);
		game->p_dx = cos(ft_degree_to_radian(game->p_angle));
		game->p_dy = -sin(ft_degree_to_radian(game->p_angle));
	}
}

void	ft_get_checkpoints(t_game *game, int keycode, t_point *check)
{
	if (keycode == KEY_W || keycode == KEY_ARROW_UP)
	{
		(*check).x = game->p_position.x + (20 * game->p_dx);
		(*check).y = game->p_position.y + (20 * game->p_dy);
	}
	if (keycode == KEY_S || keycode == KEY_ARROW_DOWN)
	{
		(*check).x = game->p_position.x - (20 * game->p_dx);
		(*check).y = game->p_position.y - (20 * game->p_dy);
	}
	if (keycode == KEY_D)
	{
		(*check).x = game->p_position.x - 20 * game->p_dy;
		(*check).y = game->p_position.y + 20 * game->p_dx;
	}
	if (keycode == KEY_A)
	{
		(*check).x = game->p_position.x + 20 * game->p_dy;
		(*check).y = game->p_position.y - 20 * game->p_dx;
	}
}
