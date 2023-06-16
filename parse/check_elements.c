/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:40:39 by ccestini          #+#    #+#             */
/*   Updated: 2023/04/25 13:11:10 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_file(t_map *map);
int	ft_valid_texture(t_map *map, char *tex_path, char *tex_id);
int	ft_valid_color(t_map *map, int colors[], char *color_element);

int	ft_check_file(t_map *map)
{
	if (ft_valid_file_extension(map->filename, ".cub") != 0)
	{
		ft_putstr_fd("Error\nInvalid file extension. Use *.cub!\n", 2);
		exit (1);
	}
	ft_read_file(map);
	ft_copy_file(map);
	ft_scan_elements(map);
	if (!map->map_str)
	{
		ft_putstr_fd("Error\nMap is missing!\n", 2);
		ft_free_tmap(map);
		exit (1);
	}
	ft_make_map_rectangle(map);
	map->map2d = ft_split(map->map_str, '\n');
	ft_find_player_position(map);
	ft_is_valid_map(map);
	ft_valid_texture(map, map->texture_path_north, "NO");
	ft_valid_texture(map, map->texture_path_south, "SO");
	ft_valid_texture(map, map->texture_path_west, "WE");
	ft_valid_texture(map, map->texture_path_east, "EA");
	ft_valid_color(map, map->floor_rgb, "Floor");
	ft_valid_color(map, map->ceiling_rgb, "Ceiling");
	return (0);
}

int	ft_valid_texture(t_map *map, char *tex_path, char *tex_id)
{
	int	fd;

	if (tex_path == NULL || tex_path[0] == '\n')
	{
		printf("Error\n<%s> texture path not found!\n", tex_id);
		ft_free_tmap(map);
		exit(1);
	}
	if (ft_valid_file_extension(tex_path, ".xpm") != 0)
	{
		printf("Error\nImage file of <%s> must have .xpm extension!\n", tex_id);
		ft_free_tmap(map);
		exit(1);
	}
	fd = open(tex_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCould not open the <%s> texture path!\n", tex_id);
		ft_free_tmap(map);
		exit(1);
	}
	close(fd);
	return (0);
}

int	ft_valid_color(t_map *map, int colors[], char *color_element)
{
	if (colors[0] < 0 || colors[1] < 0 || colors[2] < 0 \
		|| colors[0] > 255 || colors[1] > 255 || colors[2] > 255 \
		|| colors[0] == -1 || colors[1] == -1 || colors[2] == -1)
	{
		printf("Error\nRGB code for the <%s> is wrong or missing!\n", \
				color_element);
		ft_free_tmap(map);
		exit(1);
	}
	return (0);
}
