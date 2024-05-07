/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:55 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:55 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	size_t	len_s;
	char	*box;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len < len_s - start)
		box = (char *)malloc(sizeof(char) * (len + 1));
	else
		box = (char *)malloc(sizeof(char) * (len_s - start + 1));
	if (box == 0)
		return (0);
	n = 0;
	while (n < len && n < len_s - start)
	{
		*(box + n) = *(s + start + n);
		n++;
	}
	*(box + n) = '\0';
	return (box);
}
