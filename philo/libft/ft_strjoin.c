/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:35 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:35 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*box;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	box = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (box == 0)
		return (0);
	ft_memcpy(box, s1, len_1);
	ft_memcpy(box + len_1, s2, len_2);
	*(box + len_1 + len_2) = '\0';
	return (box);
}
