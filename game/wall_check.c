/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 07:52:33 by mkovoor           #+#    #+#             */
/*   Updated: 2023/05/09 14:29:59 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

double	ft_check_walls(t_game *game);
int		ft_intersect_h(t_game *game, t_point *intersect, t_point *delta);
int		ft_intersect_v(t_game *game, t_point *intersect, t_point *delta);
double	ft_check_horizontal_hit(t_game *game);
double	ft_check_vertical_hit(t_game *game);

double	ft_check_walls(t_game *game)
{
	double	vertical_hit;
	double	horizontal_hit;

	game->grid_offset = 0;
	game->p_radius = ft_degree_to_radian(game->ray_angle);
	horizontal_hit = ft_check_horizontal_hit(game);
	game->grid_offset = 0;
	vertical_hit = ft_check_vertical_hit(game);
	if (horizontal_hit <= vertical_hit)
	{
		game->side = 0;
		game->wall_hit.x = game->wall_h.x;
		game->wall_hit.y = game->wall_h.y;
		game->dist_wall = horizontal_hit;
		return (horizontal_hit);
	}
	else
	{
		game->side = 1;
		game->wall_hit.x = game->wall_v.x;
		game->wall_hit.y = game->wall_v.y;
		game->dist_wall = vertical_hit;
		return (vertical_hit);
	}
}

int	ft_intersect_h(t_game *game, t_point *hit, t_point *delta)
{
	if (game->ray_angle > 0.0 && game->ray_angle < 180.0)
	{
		delta->y = (double)(-64);
		delta->x = 64.0 / tan(game->p_radius);
		hit->y = ((int)game->p_position.y >> 6 << 6);
		hit->x = (game->p_position.x + \
		((game->p_position.y - hit->y) / tan(game->p_radius)));
	}
	else if (game->ray_angle > 180.0 && game->ray_angle < 360.0)
	{
		delta->y = 64.0;
		delta->x = -64.0 / tan(game->p_radius);
		hit->y = ((int)game->p_position.y >> 6 << 6) + 64;
		hit->x = game->p_position.x + \
		((game->p_position.y - hit->y) / tan(game->p_radius));
	}
	else if (game->ray_angle == 0.0 || game->ray_angle == 180.0 \
			|| game->ray_angle == 360.0)
		return (-1);
	return (0);
}

int	ft_intersect_v(t_game *game, t_point *intersect, t_point *delta)
{
	if (game->ray_angle < 90.0 || game->ray_angle > 270.0)
	{
		delta->x = 64.0;
		delta->y = -64 * tan(game->p_radius);
		intersect->x = ((int)game->p_position.x >> 6 << 6) + 64;
		intersect->y = game->p_position.y + \
		((game->p_position.x - intersect->x) * tan(game->p_radius));
	}
	else if (game->ray_angle > 90.0 && game->ray_angle < 270.0)
	{
		delta->x = (double)(-64);
		delta->y = 64.0 * tan(game->p_radius);
		intersect->x = ((int)game->p_position.x >> 6 << 6);
		intersect->y = game->p_position.y + \
		((game->p_position.x - intersect->x) * tan(game->p_radius));
	}
	else if (game->ray_angle == 90.0 || game->ray_angle == 270.0)
		return (-1);
	return (0);
}

double	ft_check_horizontal_hit(t_game *game)
{
	int		x;
	int		y;
	t_point	hit;
	t_point	delta;

	if (ft_intersect_h(game, &hit, &delta) == -1)
		return (LONG_MAX);
	if (game->ray_angle > 0.0 && game->ray_angle < 180.0)
		game->grid_offset = -1;
	x = floor(hit.x / SIZE_TITLE);
	y = floor((hit.y + game->grid_offset) / SIZE_TITLE);
	if (ft_check_limits(game, x, y) == -1)
		return (LONG_MAX);
	while ((game->map->map_str[(y * (game->map->width + 1)) + x]) == '0')
	{
		hit.x += delta.x;
		hit.y += delta.y;
		x = floor(hit.x / SIZE_TITLE);
		y = floor((hit.y + game->grid_offset) / SIZE_TITLE);
		if (ft_check_limits(game, x, y) == -1)
			return (LONG_MAX);
	}
	game->wall_h.x = hit.x;
	game->wall_h.y = hit.y;
	return (ft_get_hyp(game->p_position.x, hit.x, game->p_position.y, hit.y));
}

double	ft_check_vertical_hit(t_game *game)
{
	int		x;
	int		y;
	t_point	hit;
	t_point	delta;

	if (ft_intersect_v(game, &hit, &delta) == -1)
		return (LONG_MAX);
	if (game->ray_angle > 90.0 && game->ray_angle < 270.0)
		game->grid_offset = -1;
	x = floor((hit.x + game->grid_offset) / SIZE_TITLE);
	y = floor((hit.y) / SIZE_TITLE);
	if (ft_check_limits(game, x, y) == -1)
		return (LONG_MAX);
	while ((game->map->map_str[(y * (game->map->width + 1)) + x]) == '0')
	{
		hit.x += delta.x;
		hit.y += delta.y;
		x = floor((hit.x + game->grid_offset) / SIZE_TITLE);
		y = floor((hit.y) / SIZE_TITLE);
		if (ft_check_limits(game, x, y) == -1)
			return (LONG_MAX);
	}
	game->wall_v.x = hit.x;
	game->wall_v.y = hit.y;
	return (ft_get_hyp(game->p_position.x, hit.x, game->p_position.y, hit.y));
}
