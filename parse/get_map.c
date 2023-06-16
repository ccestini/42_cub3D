/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:42:18 by ccestini          #+#    #+#             */
/*   Updated: 2023/04/29 11:25:35 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_load_map(t_map *map, int i);
int		ft_count_all_map_chars(t_map *map, int i);
int		ft_copy_map(t_map *map, int i);
void	ft_check_after_map(t_map *map, int i);
int		ft_calc_width(char *s);

void	ft_load_map(t_map *map, int i)
{
	map->nbr_map_chars = ft_count_all_map_chars(map, i);
	map->width = ft_calc_width(map->tmp_file[i]);
	map->map_str = ft_calloc(sizeof(char), (map->nbr_map_chars + 1));
	if (!map->map_str)
	{
		ft_putstr_fd("Error\nNo memory allocated!\n", 2);
		ft_free_tmap(map);
		exit (1);
	}
	i = ft_copy_map(map, i);
	ft_check_after_map(map, i);
}

int	ft_copy_map(t_map *map, int i)
{
	int	j;
	int	m;

	m = 0;
	while (map->tmp_file[i] && !ft_is_empty(map->tmp_file[i]))
	{
		j = 0;
		while (map->tmp_file[i][j])
		{
			map->map_str[m] = map->tmp_file[i][j];
			j++;
			m++;
		}
		if ((int)ft_strlen(map->tmp_file[i]) > map->width)
			map->width = ft_calc_width(map->tmp_file[i]);
		map->height++;
		i++;
	}
	map->map_str[m] = '\0';
	if (map->map_str[m - 1] == '\n')
		map->map_str[m - 1] = '\0';
	map->nbr_elements_file++;
	return (i);
}

void	ft_check_after_map(t_map *map, int i)
{
	while (map->tmp_file[i])
	{
		if (!ft_is_empty(map->tmp_file[i]))
		{
			ft_putstr_fd("Error\nNo elements accepted after the map!\n", 2);
			ft_free_tmap(map);
			exit (1);
		}
		i++;
	}
}

int	ft_count_all_map_chars(t_map *map, int i)
{
	int	j;
	int	total_chars;

	j = 0;
	total_chars = 0;
	while (map->tmp_file[i])
	{
		j = 0;
		if (!ft_is_empty(map->tmp_file[i]))
		{
			while (map->tmp_file[i][j])
			{
				total_chars++;
				j++;
			}
		}
		else
			break ;
		i++;
	}
	return (total_chars);
}

int	ft_calc_width(char *s)
{
	int	w;

	if (s)
	{
		w = 0;
		while (s[w] != '\0' && s[w] != '\n')
			w++;
		return (w);
	}
	return (0);
}
