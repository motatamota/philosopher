/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:40 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:40 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	k;

	if (!src || !dest)
		return (0);
	k = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (k < n - 1 && *(src + k))
	{
		*(dest + k) = *(src + k);
		k++;
	}
	*(dest + k) = '\0';
	return (ft_strlen(src));
}
