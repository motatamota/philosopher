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
		if (ch_deathflag(st))
			break ;
		n = 0;
		while (n < st->num_philo)
		{
			gettimeofday(&st->time2, NULL);
			if (timecal(st->time3[n], st->time2)
				> st->death_time + 10 && !st->eating[n])
			{
				sum_deathflag(st, 1);
				printf("%ld %d is died\n",
					timecal(st->time, st->time2) - 5, n + 1);
				free(st);
				st = NULL;
				return ;
			}
			n++;
		}
	}
	free(st);
	st = NULL;
}

long	timecal(struct timeval time1, struct timeval time2)
{
	return ((time2.tv_usec - time1.tv_usec) / 1000
		+ (time2.tv_sec - time1.tv_sec) * 1000);
}

void	ft_sleep(long time, struct timeval from)
{
	struct timeval	to;

	gettimeofday(&to, NULL);
	usleep(time - timecal(from, to) + 1000);
}
