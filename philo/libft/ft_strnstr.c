/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:48 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:48 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t	len_s;
	size_t	n;
	size_t	m;

	if (!dest || !src)
		return (0);
	len_s = ft_strlen(src);
	n = 0;
	if (len_s == 0)
		return ((char *)dest);
	while (n + len_s - 1 < len && *(dest + n))
	{
		m = 0;
		while (*(dest + n + m) == *(src + m)
			&& n + m < len && *(dest + n + m) && *(src + m))
			m++;
		if (*(src + m) == 0)
			return ((char *)dest + n);
		n++;
	}
	return (0);
}

// #include <string.h>
// int	main()
// {
// 	char *a = (char *)"aaabcabcd";
// 	printf("%p\n", ft_strnstr(a, "coucou", -1));
// 	printf("%p\n", a);
// }
