/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:32 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:32 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	n;
	size_t	len;
	char	*box;

	len = ft_strlen(str);
	box = (char *)malloc(sizeof(char) * (len + 1));
	if (box == 0)
		return (0);
	n = 0;
	while (n < len)
	{
		*(box + n) = *(str + n);
		n++;
	}
	*(box + n) = '\0';
	return (box);
}
