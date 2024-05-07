/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:17 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:17 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			k;
	unsigned char	*box;

	box = (unsigned char *)buf;
	k = 0;
	while (k < n)
	{
		*(box + k) = (unsigned char)ch;
		k++;
	}
	return (buf);
}
