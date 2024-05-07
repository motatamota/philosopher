/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:52 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:52 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	stt;
	size_t	end;
	size_t	len;
	char	*box;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	stt = 0;
	while (ft_strchr(set, *(s1 + stt)))
		stt++;
	end = 0;
	while (ft_strchr(set, *(s1 + len - 1 - end)))
		end++;
	if (stt + end >= len)
		return (ft_strdup(""));
	box = (char *)malloc(sizeof(char) * (len - stt - end + 1));
	if (!box)
		return (0);
	ft_memcpy(box, s1 + stt, len - stt - end);
	*(box + len - stt - end) = '\0';
	return (box);
}
