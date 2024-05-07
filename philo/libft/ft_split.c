/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:27 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:27 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	how(char *s, char c)
{
	int	size;

	if (*s == 0)
		return (0);
	size = 0;
	while (*s)
	{
		if (*s == c)
		{
			size++;
			while (*s && *(s + 1) == c)
				s++;
		}
		s++;
	}
	if (*(s - 1) != c)
		size++;
	return (size);
}

static void	splitfree(char **box)
{
	int	n;

	n = 0;
	while (*(box + n))
	{
		free(*(box + n));
		n++;
	}
	free(box);
}

static void	setboxsub(int min, int max, char *box, char *s)
{
	int	p;

	p = 0;
	while (min < max)
	{
		*(box + p) = *(s + min);
		p++;
		min++;
	}
}

static int	setbox(char **box, char *s, int many, char c)
{
	int	n;
	int	min;
	int	max;

	n = 0;
	max = 0;
	while (n < many)
	{
		min = max;
		while (*(s + max) != c && *(s + max))
			max++;
		*(box + n) = (char *)malloc(sizeof(char) * (max - min + 1));
		if (!*(box + n))
			return (0);
		setboxsub(min, max, *(box + n), s);
		*(*(box + n) + max - min) = '\0';
		while (*(s + max) == c)
			max++;
		n++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		many;
	char	**box;

	if (s == 0)
		return (0);
	while (*s == c && *s)
		s++;
	many = how((char *)s, c);
	box = (char **)malloc(sizeof(char *) * (many + 1));
	if (!box)
		return (0);
	if (!setbox(box, (char *)s, many, c))
	{
		splitfree(box);
		return (0);
	}
	*(box + many) = NULL;
	return (box);
}

// #include <stdio.h>
// int main()
// {
// 	char **box;
// 	int	n;

// 	n = 0;
// 	box = ft_split("                 ", ' ');
// 	if (box == 0)
// 		return 0;
// 	while (*(box + n))
// 	{
// 		printf("%s\n", *(box + n));
// 		n++;
// 	}
// }
