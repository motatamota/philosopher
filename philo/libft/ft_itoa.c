/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:02:11 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 02:02:11 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how(long k)
{
	int		l;

	if (k < 0)
		k = -k;
	l = 1;
	while (k >= 10)
	{
		k = k / 10;
		l++;
	}
	return (l);
}

static void	set(char *str, long k, int n)
{
	if (k < 10)
	{
		*(str + n) = k + '0';
		return ;
	}
	set(str, k / 10, n - 1);
	*(str + n) = k % 10 + '0';
}

static char	*itoasub(long k, int *size)
{
	char	*str;

	k = -k;
	(*size)++;
	str = (char *)malloc(sizeof(char) * (*size + 1));
	if (!str)
		return (0);
	*str = '-';
	set(str + 1, k, *size - 2);
	return (str);
}

static char	*itoasub2(long k, int size, int n)
{
	char	*str;

	k = n;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	set(str, k, size - 1);
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	long	k;
	char	*str;

	k = n;
	str = 0;
	size = how(k);
	if (n < 0)
		str = itoasub(k, &size);
	else
		str = itoasub2(k, size, n);
	if (!str)
		return (0);
	*(str + size) = '\0';
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	printf("%s\n", ft_itoa(-1));
// }