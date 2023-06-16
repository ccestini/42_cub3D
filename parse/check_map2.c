/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:41:41 by ccestini          #+#    #+#             */
/*   Updated: 2023/04/10 15:54:31 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_valid_inner_walls(t_map *map);
int	ft_valid_outer_walls(t_map *map);
int	ft_check_emptyspace_neighbors(t_map *map, int i, int w, int len);
int	ft_walls_check_row_top_bottom(t_map *map, int i, int last);
int	ft_walls_check_column_left_right(t_map *map, int i);

int	ft_valid_inner_walls(t_map *map)
{
	int		i;
	int		w;
	int		len;
	char	*s;

	i = 0;
	w = map->width + 1;
	s = map->map_str;
	len = ft_strlen(s) - 1;
	if (ft_check_emptyspace_neighbors(map, i, w, len) == -1)
		return (-1);
	return (0);
}

int	ft_check_emptyspace_neighbors(t_map *map, int i, int w, int len)
{
	char	*s;

	s = map->map_str;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			if ((i + 1) >= 0 && (i + 1) <= len)
				if (!(s[i + 1] == ' ' || s[i + 1] == '1' || s[i + 1] == '\n'))
					return (-1);
			if ((i - 1) >= 0 && (i - 1) <= len)
				if (!(s[i - 1] == ' ' || s[i - 1] == '1' || s[i - 1] == '\n'))
					return (-1);
			if ((i + w) >= 0 && (i + w) <= len)
				if (!(s[i + w] == ' ' || s[i + w] == '1' || s[i + w] == '\n'))
					return (-1);
			if ((i - w) >= 0 && (i - w) <= len)
				if (!(s[i - w] == ' ' || s[i - w] == '1' || s[i - w] == '\n'))
					return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_valid_outer_walls(t_map *map)
{
	int	i;
	int	last;

	i = 0;
	last = ft_strlen(map->map_str) - 1;
	if (ft_walls_check_row_top_bottom(map, i, last) == -1)
		return (-1);
	if (ft_walls_check_column_left_right(map, i) == -1)
		return (-1);
	return (0);
}

int	ft_walls_check_row_top_bottom(t_map *map, int i, int last)
{
	int	n;

	n = map->width;
	while (n-- && map->map_str[i] && map->map_str[last])
	{
		if (!(map->map_str[i] == '1' || map->map_str[i] == ' '))
			return (-1);
		if (!(map->map_str[last] == '1' || map->map_str[last] == ' '))
			return (-1);
		i++;
		last--;
	}
	return (0);
}

int	ft_walls_check_column_left_right(t_map *map, int i)
{
	i = 0;
	while (map->map_str[i])
	{
		if (map->map_str[i] == '\n' && !(map->map_str[i - 1] == '1' \
		|| map->map_str[i - 1] == ' '))
			return (-1);
		if (map->map_str[i] == '\n' && !(map->map_str[i + 1] == '1' \
		|| map->map_str[i + 1] == ' '))
			return (-1);
		i++;
	}
	return (0);
}
