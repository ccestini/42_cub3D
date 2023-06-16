/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:42:42 by ccestini          #+#    #+#             */
/*   Updated: 2023/04/10 15:51:50 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_count_map_contents(t_map *map);
int		ft_find_player_position(t_map *map);
void	ft_make_map_rectangle(t_map *map);
void	ft_fill_map_with_spaces(t_map *map, char *new_map, int len, int j);

int	ft_count_map_contents(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_str[i])
	{
		if (map->map_str[i] == 'N' || map->map_str[i] == 'S' \
		|| map->map_str[i] == 'W' || map->map_str[i] == 'E')
		{
			map->count_p++;
			if (map->map_str[i] == 'N')
				map->player_orientation = 'N';
			else if (map->map_str[i] == 'S')
				map->player_orientation = 'S';
			else if (map->map_str[i] == 'W')
				map->player_orientation = 'W';
			else if (map->map_str[i] == 'E')
				map->player_orientation = 'E';
		}
		else if (map->map_str[i] == '0')
			map->count_0++;
		else if (map->map_str[i] == '1')
			map->count_1++;
		i++;
	}
	return (0);
}

int	ft_find_player_position(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_str[i])
	{
		if (map->map_str[i] == 'N' || map->map_str[i] == 'S' \
			|| map->map_str[i] == 'W' || map->map_str[i] == 'E')
		{
			map->player_position = i;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	ft_make_map_rectangle(t_map *map)
{
	char	*new_map;
	int		j;
	int		len;

	j = 0;
	len = 0;
	new_map = ft_calloc(sizeof(char), (map->height * (map->width + 1)));
	if (!new_map)
	{
		ft_putstr_fd("Error\nNo memory allocated!\n", 2);
		ft_free_tmap(map);
		exit (1);
	}
	ft_fill_map_with_spaces(map, new_map, len, j);
	free(map->map_str);
	map->map_str = new_map;
}

void	ft_fill_map_with_spaces(t_map *map, char *new_map, int len, int j)
{
	int	i;

	i = 0;
	while (map->map_str[i])
	{
		if (map->map_str[i] != '\n')
			new_map[j++] = map->map_str[i++];
		else if (map->map_str[i] == '\n' && len < map->width)
			new_map[j++] = ' ';
		else
		{
			new_map[j++] = map->map_str[i++];
			len = -1;
		}
		len++;
	}
	while (map->map_str[i] == '\0' && len < map->width)
	{
		new_map[j++] = ' ';
		len++;
	}
	new_map[j] = '\0';
}
