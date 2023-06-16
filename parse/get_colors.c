/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:42:00 by ccestini          #+#    #+#             */
/*   Updated: 2023/04/10 15:53:11 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_color_f(char **strs, char *line, t_map *map);
void	ft_get_color_c(char **strs, char *line, t_map *map);
void	ft_fill_rgb_floor(t_map *map, char **strs2);
void	ft_fill_rgb_ceiling(t_map *map, char **strs2);
void	ft_check_commas(t_map *map, char *line, char **strs);

void	ft_get_color_f(char **strs, char *line, t_map *map)
{
	int		i;
	char	**strs2;

	if (map->floor_rgb[0] != -1 || map->floor_rgb[1] != -1 \
		|| map->floor_rgb[2] != -1)
	{
		ft_putstr_fd("Error\nOnly one of each element accepted!\n", 2);
		ft_color_exit_free(map, line, strs);
	}
	ft_check_commas(map, line, strs);
	strs2 = ft_split2(line, ',');
	i = 1;
	while (strs2[i] && strs2[i][0] != '\n' && ft_isalldigits(strs2[i]))
		i++;
	if ((i - 1) == 3)
		ft_fill_rgb_floor(map, strs2);
	else
	{
		ft_putstr_fd("Error\nWrong nbr of args or contain other chars then " \
					"digits in the <floor> color rgb info!\n", 2);
		ft_free_2d_array(strs2);
		ft_color_exit_free(map, line, strs);
	}	
	ft_free_2d_array(strs2);
}

void	ft_get_color_c(char **strs, char *line, t_map *map)
{
	int		i;
	char	**strs2;

	if (map->ceiling_rgb[0] != -1 || map->ceiling_rgb[1] != -1 \
		|| map->ceiling_rgb[2] != -1)
	{
		ft_putstr_fd("Error\nOnly one of each element accepted!\n", 2);
		ft_color_exit_free(map, line, strs);
	}
	ft_check_commas(map, line, strs);
	strs2 = ft_split2(line, ',');
	i = 1;
	while (strs2[i] && strs2[i][0] != '\n' && ft_isalldigits(strs2[i]))
		i++;
	if ((i - 1) == 3)
		ft_fill_rgb_ceiling(map, strs2);
	else
	{
		ft_putstr_fd("Error\nWrong nbr of args or contain other chars then " \
					"digits in the <ceiling> color rgb info!\n", 2);
		ft_free_2d_array(strs2);
		ft_color_exit_free(map, line, strs);
	}	
	ft_free_2d_array(strs2);
}

void	ft_fill_rgb_floor(t_map *map, char **strs2)
{
	map->floor_rgb[0] = ft_atoi(strs2[1]);
	map->floor_rgb[1] = ft_atoi(strs2[2]);
	map->floor_rgb[2] = ft_atoi(strs2[3]);
	map->nbr_elements_file++;
}

void	ft_fill_rgb_ceiling(t_map *map, char **strs2)
{
	map->ceiling_rgb[0] = ft_atoi(strs2[1]);
	map->ceiling_rgb[1] = ft_atoi(strs2[2]);
	map->ceiling_rgb[2] = ft_atoi(strs2[3]);
	map->nbr_elements_file++;
}

void	ft_check_commas(t_map *map, char *line, char **strs)
{
	int	commas;
	int	i;

	commas = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			commas++;
		i++;
	}
	if (commas != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Wrong args in color element, check commas!\n", 2);
		ft_color_exit_free(map, line, strs);
		exit (1);
	}
}
