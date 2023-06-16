/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_slice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:52:46 by mkovoor           #+#    #+#             */
/*   Updated: 2023/05/09 14:34:57 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_map_slice(t_game *game, double distance_to_wall, int slice_count);
void	ft_map_slice_side0(t_game *game, char *tc, int slice_count, int y);
void	ft_map_slice_side1(t_game *game, char *tc, int slice_count, int y);
void	ft_get_top_bottom(t_game *game);
void	ft_get_text_offset(t_game *game);

int	ft_map_slice(t_game *game, double distance_to_wall, int slice_count)
{
	int	y;

	y = 0;
	game->dist_from_top = 0;
	game->wall_projected = floor((SIZE_TITLE * ((SCREEN_W * 0.5) / \
					tan(ft_degree_to_radian(FOV * 0.5)))) / distance_to_wall);
	game->proj_h = floor(game->wall_projected);
	ft_get_top_bottom(game);
	ft_get_text_offset(game);
	while (y < SCREEN_H)
	{
		if (y >= game->top && y < game->bottom)
		{
			game->dist_from_top = y + (game->proj_h / 2) - (SCREEN_H / 2);
			game->texture_offset_y = floor(game->dist_from_top * \
								((float)TEXHEIGHT / game->proj_h));
			ft_map_slice_side0(game, game->texel_color, slice_count, y);
			ft_map_slice_side1(game, game->texel_color, slice_count, y);
		}
		y++;
	}
	return (0);
}

void	ft_get_top_bottom(t_game *game)
{
	game->top = floor((SCREEN_H / 2) - (game->wall_projected / 2));
	game->bottom = floor((SCREEN_H / 2) + (game->wall_projected / 2));
	if (game->top < 0)
		game->top = 0;
	if (game->bottom > SCREEN_H)
		game->bottom = SCREEN_H;
}

void	ft_get_text_offset(t_game *game)
{
	if (game->side == 0)
		game->texture_offset_x = (int)game->wall_hit.x % (int)SIZE_TITLE;
	else
		game->texture_offset_x = (int)game->wall_hit.y % (int)SIZE_TITLE;
}

void	ft_map_slice_side0(t_game *game, char *tc, int slice_count, int y)
{
	char	*texcel;

	texcel = tc;
	if (game->side == 0)
	{
		if (game->ray_angle > 180 && (game->ray_angle < 360))
		{
			texcel = game->addr2 + (int)((game->line2 * \
						game->texture_offset_y) + game->texture_offset_x * \
						(game->bpp2 / 8));
			my_pixel_put(game, slice_count, y, *(unsigned int *)texcel);
		}
		else
		{
			texcel = game->addr1 + (int)((game->line1 * \
						game->texture_offset_y) + game->texture_offset_x * \
						(game->bpp1 / 8));
			my_pixel_put(game, slice_count, y, *(unsigned int *)texcel);
		}
	}
}

void	ft_map_slice_side1(t_game *game, char *tc, int slice_count, int y)
{
	char	*texcel;

	texcel = tc;
	if (game->side == 1)
	{
		if (game->ray_angle > 90 && game->ray_angle < 270)
		{
			texcel = game->addr4 +(int)((game->line4 * \
						game->texture_offset_y) + game->texture_offset_x * \
						(game->bpp4 / 8));
			my_pixel_put(game, slice_count, y, *(unsigned int *)texcel);
		}
		else
		{
			texcel = game->addr3 +(int)((game->line3 * \
						game->texture_offset_y) + game->texture_offset_x * \
						(game->bpp3 / 8));
			my_pixel_put(game, slice_count, y, *(unsigned int *)texcel);
		}
	}
}
