/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:41:52 by ccestini          #+#    #+#             */
/*   Updated: 2023/04/10 15:53:36 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_tmap(t_map *map);
void	ft_free_2d_array(char **str);
void	ft_color_exit_free(t_map *map, char *line, char **strs);

void	ft_free_tmap(t_map *map)
{
	if (map->tmp_file != NULL)
		ft_free_2d_array(map->tmp_file);
	if (map->map_str != NULL)
		free (map->map_str);
	if (map->map2d != NULL)
		ft_free_2d_array(map->map2d);
	if (map->texture_path_north != NULL)
		free(map->texture_path_north);
	if (map->texture_path_south != NULL)
		free(map->texture_path_south);
	if (map->texture_path_west != NULL)
		free(map->texture_path_west);
	if (map->texture_path_east != NULL)
		free(map->texture_path_east);
}

void	ft_free_2d_array(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
	str = NULL;
}

void	ft_color_exit_free(t_map *map, char *line, char **strs)
{
	ft_free_tmap(map);
	if (line)
		free(line);
	if (strs)
		ft_free_2d_array(strs);
	exit (1);
}
