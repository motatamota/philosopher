/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:35:56 by tashiget          #+#    #+#             */
/*   Updated: 2024/06/03 13:35:56 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	imchecker(t_philo *st)
{
	int	n;

	while (1)
	{
		usleep(10000);
		if (*st->death_flag)
			break ;
		gettimeofday(&st->time2, NULL);
		n = 0;
		while (n < st->num_philo)
		{
			if (timecal(st->time3[n], st->time2)
				> st->death_time && !st->eating[n])
			{
				*st->death_flag = 1;
				printf("%ld %d is died\n", timecal(st->time, st->time2), n + 1);
				free(st);
				return ;
			}
			n++;
		}
	}
	free(st);
}

long	timecal(struct timeval time1, struct timeval time2)
{
	return ((time2.tv_usec - time1.tv_usec) / 1000
		+ (time2.tv_sec - time1.tv_sec) * 1000);
}
