/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:51:43 by ccestini          #+#    #+#             */
/*   Updated: 2022/09/21 14:15:36 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexa_upper(unsigned int n)
{
	char	*hexa;
	int		len;

	len = 1;
	hexa = "0123456789ABCDEF";
	if (n >= 16)
		len = len + ft_printhexa_upper(n / 16);
	write(1, &hexa[n % 16], 1);
	return (len);
}
