/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:50 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:50 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	n;
	char	*p;

	n = 0;
	p = 0;
	while (*(str + n))
	{
		if (*(str + n) == (char)c)
			p = (char *)str + n;
		n++;
	}
	if (*(str + n) == (char)c)
		p = (char *)str + n;
	return (p);
}
