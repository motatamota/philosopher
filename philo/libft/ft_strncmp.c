/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:45 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:45 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n && *(s1 + k) && *(s1 + k) == *(s2 + k))
		k++;
	if (k == n)
		return (0);
	return ((unsigned char)*(s1 + k) - (unsigned char)*(s2 + k));
}
