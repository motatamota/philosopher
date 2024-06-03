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
		usleep(20);
		n = 0;
		while (n < st->num_philo)
		{
			if (st->time3[n].tv_usec - st->time.tv_usec > st-> death_time)
			{
				st->death_flag = 1;
				gettimeofday(&st->time2, NULL);
				printf("%4ld %d is died\n", st->time2.tv_usec - st->time.tv_usec / 1000, n + 1);
				return ;
			}
			n++;
		}
	}
}
