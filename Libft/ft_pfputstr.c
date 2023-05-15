/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfputstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:07:10 by dylan             #+#    #+#             */
/*   Updated: 2023/02/20 17:56:58 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pfputstr(const char *src, int *count)
{
	int	i;

	i = 0;
	if (!src)
	{
		ft_pfputstr("(null)", count);
		return ;
	}
	while (src[i])
	{
		ft_pfputchar(src[i], count);
		i++;
	}
}
