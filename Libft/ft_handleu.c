/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:00:31 by dylan             #+#    #+#             */
/*   Updated: 2023/02/20 17:56:28 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbru(unsigned int nb, int *count)
{
	if (nb >= 10)
	{
		ft_putnbru(nb / 10, count);
		ft_putnbru(nb % 10, count);
	}
	else
		ft_pfputchar((nb + '0'), count);
}
