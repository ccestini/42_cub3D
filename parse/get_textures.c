/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:42:55 by ccestini          #+#    #+#             */
/*   Updated: 2023/04/10 15:43:03 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_texture_no(char *line, char **strs, t_map *map);
void	ft_get_texture_so(char *line, char **strs, t_map *map);
void	ft_get_texture_we(char *line, char **strs, t_map *map);
void	ft_get_texture_ea(char *line, char **strs, t_map *map);

void	ft_get_texture_no(char *line, char **strs, t_map *map)
{
	if (map->texture_path_north != NULL)
	{
		ft_putstr_fd("Error\nOnly one of each element accepted!\n", 2);
		if (strs)
			ft_free_2d_array(strs);
		if (line)
			free(line);
		ft_free_tmap(map);
		exit (1);
	}
	else
	{
		map->texture_path_north = ft_strdup(strs[1]);
		map->nbr_elements_file++;
	}
}

void	ft_get_texture_so(char *line, char **strs, t_map *map)
{
	if (map->texture_path_south != NULL)
	{
		ft_putstr_fd("Error\nOnly one of each element accepted!\n", 2);
		if (strs)
			ft_free_2d_array(strs);
		if (line)
			free(line);
		ft_free_tmap(map);
		exit (1);
	}
	else
	{
		map->texture_path_south = ft_strdup(strs[1]);
		map->nbr_elements_file++;
	}
}

void	ft_get_texture_we(char *line, char **strs, t_map *map)
{
	if (map->texture_path_west != NULL)
	{
		ft_putstr_fd("Error\nOnly one of each element accepted!\n", 2);
		if (strs)
			ft_free_2d_array(strs);
		if (line)
			free(line);
		ft_free_tmap(map);
		exit (1);
	}
	else
	{
		map->texture_path_west = ft_strdup(strs[1]);
		map->nbr_elements_file++;
	}
}

void	ft_get_texture_ea(char *line, char **strs, t_map *map)
{
	if (map->texture_path_east != NULL)
	{
		ft_putstr_fd("Error\nOnly one of each element accepted!\n", 2);
		if (strs)
			ft_free_2d_array(strs);
		if (line)
			free(line);
		ft_free_tmap(map);
		exit (1);
	}
	else
	{
		map->texture_path_east = ft_strdup(strs[1]);
		map->nbr_elements_file++;
	}
}
