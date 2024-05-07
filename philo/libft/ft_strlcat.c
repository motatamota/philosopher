/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:38 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:38 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	scands(char *dest, char *src)
{
	if (!dest && !src)
		return (0);
	if (!dest)
		return (ft_strlen(src));
	return (ft_strlen(dest));
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_d;
	size_t	len_s;
	size_t	k;

	if (!dest || !src)
		return (scands(dest, (char *)src));
	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (len_d >= n)
		return (n + len_s);
	k = 0;
	while (k < n - len_d - 1 && *(src + k))
	{
		*(dest + len_d + k) = *(src + k);
		k++;
	}
	*(dest + len_d + k) = '\0';
	return (len_d + len_s);
}
