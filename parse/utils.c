/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:43:32 by ccestini          #+#    #+#             */
/*   Updated: 2023/04/10 15:46:13 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_print_2darray(char **str);
int		ft_is_whitespace(char c);
int		ft_is_empty(char *str);
void	ft_print_map_and_info(t_map *map);

void	ft_print_2darray(char **str)
{
	int	i;

	i = 0;
	if (!str)
	{
		printf("(null)\n");
		return ;
	}
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\v' || c == '\r' \
		|| c == '\n')
		return (1);
	else
		return (0);
}

int	ft_is_empty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (ft_is_whitespace(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_map_and_info(t_map *map)
{
	int	x;

	printf("Map:\n%s\n", map->map_str);
	printf("Map2D:\n");
	ft_print_2darray(map->map2d);
	printf("height=%d\n", map->height);
	printf("width=%d\n", map->width);
	printf("player position=%d\n", map->player_position);
	printf("player orientation=%c\n", map->player_orientation);
	x = ft_valid_rectangle(map);
	printf("rectangle if 0 is ok-> result= %d\n", x);
}
