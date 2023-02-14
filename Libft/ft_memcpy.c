/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 06:13:18 by dylan             #+#    #+#             */
/*   Updated: 2023/01/22 14:57:21 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	if (dest)
	{
		cdest = (unsigned char *)dest;
		csrc = (unsigned char *)src;
		i = 0;
		while (n)
		{
			cdest[i] = csrc[i];
			i++;
			n--;
		}
	}
	return (dest);
}
