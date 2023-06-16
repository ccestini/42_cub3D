/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:43:24 by ccestini          #+#    #+#             */
/*   Updated: 2023/04/11 14:43:44 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_read_file(t_map *map);
void	ft_copy_file(t_map *map);
void	ft_scan_elements(t_map *map);
int		ft_scan_headers(t_map *map, char *line);

void	ft_read_file(t_map *map)
{
	int		fd;
	int		count_lines;
	char	*line;

	line = NULL;
	count_lines = 0;
	fd = ft_open(map->filename);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count_lines++;
		free(line);
	}
	close(fd);
	if (count_lines < 7)
	{
		ft_putstr_fd("Error\nElement(s) is(are) missing!\n", 2);
		exit (1);
	}
	map->tmp_file = ft_calloc(sizeof(char *), count_lines + 1);
	if (!map->tmp_file)
		ft_putstr_fd("Error\nNo memory allocated!\n", 2);
}

void	ft_copy_file(t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	line = NULL;
	i = 0;
	if (!map->tmp_file)
		exit (1);
	fd = ft_open(map->filename);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->tmp_file[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	map->tmp_file[i] = NULL;
}

void	ft_scan_elements(t_map *map)
{
	int			i;
	static int	check_is_map;
	char		*line_trim;

	i = 0;
	line_trim = NULL;
	while (map->tmp_file[i])
	{
		if (ft_is_empty(map->tmp_file[i]))
		{
			i++;
			continue ;
		}
		line_trim = ft_strtrim(map->tmp_file[i], "\n");
		check_is_map = ft_scan_headers(map, line_trim);
		if (line_trim)
			free(line_trim);
		if (check_is_map == 2)
		{
			ft_check_nbr_elements(map, 6);
			ft_load_map(map, i);
			return ;
		}
		i++;
	}
}

int	ft_scan_headers(t_map *map, char *line)
{
	char	**strs;

	strs = ft_split(line, ' ');
	if (strs == NULL || strs[0] == NULL)
		return (-1);
	else if (ft_strcmp(strs[0], "NO") == 0 && strs[1] != 0 && strs[2] == 0)
		ft_get_texture_no(line, strs, map);
	else if (ft_strcmp(strs[0], "SO") == 0 && strs[1] != 0 && strs[2] == 0)
		ft_get_texture_so(line, strs, map);
	else if (ft_strcmp(strs[0], "WE") == 0 && strs[1] != 0 && strs[2] == 0)
		ft_get_texture_we(line, strs, map);
	else if (ft_strcmp(strs[0], "EA") == 0 && strs[1] != 0 && strs[2] == 0)
		ft_get_texture_ea(line, strs, map);
	else if (ft_strcmp(strs[0], "F") == 0 && strs[1] != 0)
		ft_get_color_f(strs, line, map);
	else if (ft_strcmp(strs[0], "C") == 0 && strs[1] != 0)
		ft_get_color_c(strs, line, map);
	else
	{
		ft_free_2d_array(strs);
		if (ft_check_line_is_map(map, line) == 2)
			return (2);
	}
	ft_free_2d_array(strs);
	return (0);
}
