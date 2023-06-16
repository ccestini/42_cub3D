/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:41:19 by ccestini          #+#    #+#             */
/*   Updated: 2023/04/10 15:55:18 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_valid_map(t_map *map);
int	ft_valid_file_extension(char *filename, char *filetype);
int	ft_valid_chars(t_map *map);
int	ft_valid_rectangle(t_map *map);

int	ft_is_valid_map(t_map *map)
{
	ft_count_map_contents(map);
	if (ft_valid_chars(map) != 0)
	{
		ft_free_tmap(map);
		exit (1);
	}
	if (ft_valid_outer_walls(map) != 0)
	{
		ft_putstr_fd("Error\nMap must be surrounded by walls\n", 2);
		ft_free_tmap(map);
		exit (1);
	}
	if (ft_valid_inner_walls(map) != 0)
	{
		ft_putstr_fd("Error\nEmpty spaces must be surrounded by walls\n", 2);
		ft_free_tmap(map);
		exit (1);
	}
	return (0);
}

int	ft_valid_file_extension(char *filename, char *filetype)
{
	int		i;
	int		j;
	int		n;

	n = ft_strlen(filetype);
	i = ft_strlen(filename) - 1;
	j = n - 1;
	if (!filename || !filetype || i <= j)
		return (-1);
	while (n--)
	{
		if ((filename[i] == filetype[j]) && filename && filetype)
		{
			i--;
			j--;
		}
		else
			return (-1);
	}
	return (0);
}

int	ft_valid_chars(t_map *map)
{
	int	i;

	i = -1;
	while (map->map_str[++i])
	{
		if (!(map->map_str[i] == '1' || map->map_str[i] == '0' \
			|| map->map_str[i] == '\n' || map->map_str[i] == ' ' \
			|| map->map_str[i] == 'N' || map->map_str[i] == 'S' \
			|| map->map_str[i] == 'E' || map->map_str[i] == 'W'))
		{
			ft_putstr_fd("Error\nMap with invalid character!\n", 2);
			return (-1);
		}
	}
	if (map->count_p != 1)
	{
		ft_putstr_fd("Error\nMap must have 1 Player!\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_valid_rectangle(t_map *map)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (map->map_str[i])
	{
		if (map->map_str[i] != '\n')
			w++;
		if (map->map_str[i] == '\n')
		{
			if (map->width != w)
				return (-1);
			w = 0;
		}
		i++;
	}
	if (map->map_str[i] == '\0' && map->width != w)
		return (-1);
	return (0);
}
