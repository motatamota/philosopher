/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:12 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:12 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			k;
	unsigned char	*box;
	unsigned char	*bot;

	if (!src || !dest)
		return (dest);
	k = 0;
	box = (unsigned char *)dest;
	bot = (unsigned char *)src;
	while (k < n)
	{
		*(box + k) = *(bot + k);
		k++;
	}
	return (dest);
}
