/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:46:24 by mkovoor           #+#    #+#             */
/*   Updated: 2023/05/09 14:28:19 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_textures(t_game *game);
int		ft_check_limits(t_game *game, int x, int y);
void	my_pixel_put(t_game *game, int x, int y, int colour);
int		ft_get_rgb(int red, int green, int blue);
void	ft_draw_floor_ceiling(t_game *game);

void	ft_init_textures(t_game *game)
{
	int	pos[8];

	game->img1 = mlx_xpm_file_to_image(game->mlx, \
			game->map->texture_path_north, &pos[0], &pos[1]);
	game->addr1 = mlx_get_data_addr(game->img1, &game->bpp1, \
			&game->line1, &game->endian1);
	game->img2 = mlx_xpm_file_to_image(game->mlx, \
			game->map->texture_path_south, &pos[2], &pos[3]);
	game->addr2 = mlx_get_data_addr(game->img2, &game->bpp2, \
			&game->line2, &game->endian2);
	game->img3 = mlx_xpm_file_to_image(game->mlx, \
			game->map->texture_path_east, &pos[4], &pos[5]);
	game->addr3 = mlx_get_data_addr(game->img3, &game->bpp3, \
			&game->line3, &game->endian3);
	game->img4 = mlx_xpm_file_to_image(game->mlx, \
			game->map->texture_path_west, &pos[6], &pos[7]);
	game->addr4 = mlx_get_data_addr(game->img4, &game->bpp4, \
			&game->line4, &game->endian4);
	game->ceiling_color = ft_get_rgb(game->map->ceiling_rgb[0], \
			game->map->ceiling_rgb[1], game->map->ceiling_rgb[2]);
	game->floor_color = ft_get_rgb(game->map->floor_rgb[0], \
			game->map->floor_rgb[1], game->map->floor_rgb[2]);
}

int	ft_check_limits(t_game *game, int x, int y)
{
	if (y >= 0 && (y < game->map->height))
	{
		if (x >= 0 && (x < game->map->width))
			return (0);
	}
	return (-1);
}

void	my_pixel_put(t_game *game, int x, int y, int colour)
{
	char	*dst;

	dst = game->addr + (y * game->line_len + x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

int	ft_get_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	ft_draw_floor_ceiling(t_game *game)
{
	unsigned int	*dst;
	unsigned int	i;

	dst = (unsigned int *)game->addr;
	i = SCREEN_W * SCREEN_H * 0.5;
	while (--i > 0)
	{
		*dst++ = game->ceiling_color;
	}
	i = SCREEN_W * SCREEN_H * 0.5 + 1;
	while (--i > 0)
	{
		*dst++ = game->floor_color;
	}
}

// t_game	*ft_map_line(t_game *game, t_point begin, t_point end, int colour) 
// add check to prevent seg fault
// {
// 	t_point	p1;
// 	int		dx;
// 	int		dy;
// 	int		sx;
// 	int		sy;
// 	int		error;
// 	int		e2;

// 	p1.x = (int)begin.x;
// 	p1.y = (int)begin.y;
// 	dx = fabs((int)end.x - p1.x);
// 	if (begin.x < end.x)
// 		sx = 1;
// 	else
// 		sx = -1;
// 	dy = -fabs((int)end.y - p1.y);
// 	if (begin.y < end.y)
// 		sy = 1;
// 	else
// 		sy = -1;
// 	error = dx + dy;
// 	while (1)
// 	{
// 		my_pixel_put(game, (int)p1.x, (int)p1.y, colour);
// 		if (p1.x == (int)end.x && p1.y == (int)end.y)	
// 			break ;
// 		e2 = 2 * error;
// 		if (e2 >= dy)
// 		{
// 			if (p1.x == (int)end.x)
// 				break ;
// 			error = error + dy;
// 			p1.x +=sx;
// 		}
// 		if (e2 <= dx)
// 		{
// 			if (p1.y == (int)end.y)
// 				break ;
// 			error = error + dx;
// 			p1.y +=sy;
// 		}
// 	}
// 	return (game);
//}
