/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:06 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:06 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t			k;
	unsigned char	*box;
	unsigned char	*bot;

	box = (unsigned char *)buf1;
	bot = (unsigned char *)buf2;
	k = 0;
	while (k < count)
	{
		if (*(box + k) != *(bot + k))
			return (*(box + k) - *(bot + k));
		k++;
	}
	return (0);
}
