/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:42:22 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 02:42:22 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*box;
	size_t			len;

	if (s == 0 || f == 0)
		return (0);
	len = ft_strlen(s);
	box = (char *)malloc(sizeof(char) * (len + 1));
	if (!box)
		return (0);
	n = 0;
	while (n < len)
	{
		*(box + n) = f(n, *(s + n));
		n++;
	}
	*(box + n) = '\0';
	return (box);
}
