/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlei.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:59:34 by dylan             #+#    #+#             */
/*   Updated: 2023/02/20 17:56:21 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ismin(int nb, int *count)
{
	ft_pfputstr("-2", count);
	nb = 147483648;
	return (nb);
}

int	isneg(int nb, int *count)
{
	ft_pfputchar('-', count);
	return (-nb);
}

void	ft_pfputnbr(int nb, int *count)
{
	if (nb == -2147483648)
		nb = ismin(nb, count);
	if (nb < 0)
		nb = isneg(nb, count);
	if (nb >= 10)
	{
		ft_pfputnbr(nb / 10, count);
		ft_pfputnbr(nb % 10, count);
	}
	else
		ft_pfputchar((nb + '0'), count);
}
