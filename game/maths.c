/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:50:42 by mkovoor           #+#    #+#             */
/*   Updated: 2023/05/09 12:50:48 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_degree_to_radian(double degree);
double	ft_radian_to_degree(double radian);
double	ft_limit_angle(double angle);
double	ft_get_hyp(double x0, double x1, double y0, double y1);

double	ft_degree_to_radian(double degree)
{
	double	radian;

	radian = degree * (M_PI / 180.0);
	return (radian);
}

double	ft_radian_to_degree(double radian)
{
	double	degree;

	degree = radian * (180.0 / M_PI);
	return (degree);
}

double	ft_limit_angle(double angle)
{
	if (angle > 360)
			angle = angle - 360.0;
	else if (angle < 0)
			angle = angle + 360;
	return (angle);
}

double	ft_get_hyp(double x0, double x1, double y0, double y1)
{
	return (sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0))));
}
