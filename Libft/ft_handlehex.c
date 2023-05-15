/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlehex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:58:49 by dylan             #+#    #+#             */
/*   Updated: 2023/02/20 17:56:13 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hex(unsigned int nb, int *count, char c)
{
	if (nb >= 16)
	{
		ft_hex(nb / 16, count, c);
		ft_hex(nb % 16, count, c);
	}
	else
	{
		if (nb <= 9)
			ft_pfputchar((nb + '0'), count);
		else
		{
			if (c == 'x')
				ft_pfputchar((nb - 10 + 'a'), count);
			if (c == 'X')
				ft_pfputchar((nb - 10 + 'A'), count);
		}
	}
}

void	ft_putptr(uintptr_t nb, int *count, int io)
{
	if (nb != 0)
	{
		if (io == 0)
		{
			io = 1;
			ft_pfputstr(("0x"), count);
		}
	}
	if (nb == 0 && io == 0)
	{
		ft_pfputstr(("(nil)"), count);
		return ;
	}
	if (nb >= 16)
	{
		ft_putptr(nb / 16, count, io);
		ft_putptr(nb % 16, count, io);
	}
	else
	{
		if (nb <= 9)
			ft_pfputchar((nb + '0'), count);
		else
			ft_pfputchar((nb - 10 + 'a'), count);
	}
}
