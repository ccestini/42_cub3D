/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:36:59 by ccestini          #+#    #+#             */
/*   Updated: 2023/05/10 16:00:45 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_tmap(t_map *map, char *av[]);
void	ft_end_game(t_game *game);

int	main(int ac, char *av[])
{
	t_map	map;
	t_game	game;	

	if (ac != 2)
	{
		ft_putstr_fd ("Error\nMust have one argument: Map file!\n", 2);
		exit (1);
	}
	ft_init_tmap(&map, av);
	ft_check_file(&map);
	game.map = &map;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, SCREEN_W, SCREEN_H, "CUB3D");
	game.img = mlx_new_image(game.mlx, SCREEN_W, SCREEN_H);
	game.addr = mlx_get_data_addr(game.img, &(game.bits_per_pixel), \
				&(game.line_len), &(game.endian));
	ft_init_player(&game);
	ft_init_buffer(&game);
	mlx_hook(game.win, 17, 0, (void *)&ft_end_game, &game);
	mlx_hook(game.win, 2, 0, (void *)&key_handler, &game);
	mlx_loop(game.mlx);
	ft_free_tmap(&map);
	return (0);
}

void	ft_init_tmap(t_map *map, char *av[])
{
	map->filename = av[1];
	map->tmp_file = NULL;
	map->height = 0;
	map->width = 0;
	map->nbr_map_chars = 0;
	map->count_p = 0;
	map->count_1 = 0;
	map->count_0 = 0;
	map->player_position = -1;
	map->player_orientation = 'A';
	map->map_str = NULL;
	map->map2d = NULL;
	map->texture_path_north = NULL;
	map->texture_path_south = NULL;
	map->texture_path_west = NULL;
	map->texture_path_east = NULL;
	map->floor_rgb[0] = -1;
	map->floor_rgb[1] = -1;
	map->floor_rgb[2] = -1;
	map->ceiling_rgb[0] = -1;
	map->ceiling_rgb[1] = -1;
	map->ceiling_rgb[2] = -1;
	map->nbr_elements_file = 0;
}

void	ft_end_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_image(game->mlx, game->img1);
	mlx_destroy_image(game->mlx, game->img2);
	mlx_destroy_image(game->mlx, game->img3);
	mlx_destroy_image(game->mlx, game->img4);
	mlx_destroy_window(game->mlx, game->win);
	ft_free_tmap(game->map);
	exit (0);
}
