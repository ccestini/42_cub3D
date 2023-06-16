/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:37:37 by ccestini          #+#    #+#             */
/*   Updated: 2023/05/09 12:45:27 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_player(t_game *game);
void	ft_set_angle(t_game *game);

void	ft_init_player(t_game *game)
{
	int	i;
	int	j;

	i = game->map->player_position % (game->map->width + 1);
	j = game->map->player_position / (game->map->width + 1);
	game->map->map2d[j][i] = '0';
	game->map->map_str[j * (game->map->width + 1) + i] = '0';
	game->p_position.x = (i * SIZE_TITLE) + (SIZE_TITLE / 2);
	game->p_position.y = (j * SIZE_TITLE) + (SIZE_TITLE / 2);
	ft_set_angle(game);
	game->p_angle = ft_limit_angle(game->p_angle);
	game->p_dx = cos(ft_degree_to_radian(game->p_angle));
	game->p_dy = -sin(ft_degree_to_radian(game->p_angle));
	ft_init_textures(game);
}

void	ft_set_angle(t_game *game)
{
	if (game->map->player_orientation == 'N')
		game->p_angle = 90;
	else if (game->map->player_orientation == 'W')
		game->p_angle = 180;
	else if (game->map->player_orientation == 'S')
		game->p_angle = 270;
	else if (game->map->player_orientation == 'E')
		game->p_angle = 360;
}
