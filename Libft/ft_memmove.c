/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 05:54:35 by dylan             #+#    #+#             */
/*   Updated: 2023/01/22 14:54:31 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest)
	{
		if (src <= dest)
		{
			while (n > 0)
			{
				n--;
				((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
			}
		}
		else
		{
			i = 0;
			while (i < n)
			{
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
					i++;
			}
		}
	}
	return (dest);
}
