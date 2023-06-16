/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:43:12 by ccestini          #+#    #+#             */
/*   Updated: 2023/05/13 10:26:23 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_open(char *filename);
int		ft_check_line_is_map(t_map *map, char *line);
void	ft_check_nbr_elements(t_map *map, int nbr);

int	ft_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFile not found!\n", 2);
		exit (1);
	}
	return (fd);
}

void	ft_check_nbr_elements(t_map *map, int nbr)
{
	if (map->nbr_elements_file < nbr)
	{
		ft_putstr_fd("Error\nWrong nbr of elements in file\n", 2);
		ft_free_tmap(map);
		exit (1);
	}
}

int	ft_check_line_is_map(t_map *map, char *line)
{
	if (ft_strchr("012NSEW ", *line) != 0)
	{
		return (2);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid elem or wrong nbr of args per element!\n", 2);
		if (line)
			free(line);
		ft_free_tmap(map);
		exit(1);
	}
	return (0);
}
