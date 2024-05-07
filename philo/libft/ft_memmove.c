/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:15 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:15 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	memmovesub(unsigned char *box, size_t n, unsigned char *bot)
{
	size_t	k;

	k = n;
	while (k > 0)
	{
		*(box + k - 1) = *(bot + k - 1);
		k--;
	}
}

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	size_t			k;
	unsigned char	*box;
	unsigned char	*bot;

	if (!buf2)
		return (0);
	box = (unsigned char *)buf1;
	bot = (unsigned char *)buf2;
	if (buf1 < buf2)
	{
		k = 0;
		while (k < n)
		{
			*(box + k) = *(bot + k);
			k++;
		}
	}
	else
		memmovesub(box, n, bot);
	return (buf1);
}
