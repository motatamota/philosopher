/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:25:47 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:25:47 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t			n;
	unsigned char	*box;

	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	box = (unsigned char *)malloc(size * count);
	if (box == 0)
		return (0);
	n = 0;
	while (n < size * count)
	{
		*(box + n) = 0;
		n++;
	}
	return ((void *)box);
}

// #include <string.h>
// #include <limits.h>
// int	main()
// {
// 	char *a;
// 	a = ft_calloc(INT_MIN, INT_MIN);
// 	free(a);
// }