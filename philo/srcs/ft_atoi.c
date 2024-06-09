/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:25:40 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:25:40 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoisub(char *str, int k, int minus)
{
	long	ans;

	ans = 0;
	while (*(str + k) >= '0' && *(str + k) <= '9')
	{
		if (__LONG_MAX__ / 10 > ans
			|| (__LONG_MAX__ / 10 == ans && 7 >= *(str + k) - '0'))
			ans = ans * 10 + *(str + k) - '0';
		else if (minus == 1)
		{
			ans = __LONG_MAX__;
			break ;
		}
		else if (minus == -1)
		{
			ans = 0;
			break ;
		}
		k++;
	}
	return (ans);
}

int	ft_atoi(const char *str)
{
	int		k;
	int		minus;
	int		ans;

	if (str == 0)
		return (0);
	minus = 1;
	k = 0;
	while (*(str + k) && ((*(str + k) >= 9
				&& *(str + k) <= 13) || *(str + k) == ' '))
		k++;
	if (*(str + k) == '-' || *(str + k) == '+')
	{
		if (*(str + k) == '-')
			minus = -1;
		k++;
	}
	ans = atoisub((char *)str, k, minus);
	return (ans * minus);
}
