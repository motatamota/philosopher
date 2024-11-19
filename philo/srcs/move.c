/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:23:01 by tashiget          #+#    #+#             */
/*   Updated: 2024/05/23 09:23:01 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	take_eat2(t_philo *st)
{
	gettimeofday(&st->time3[st->who - 1], NULL);
	printf("%ld %d has taken a fork\n",
		timecal(st->time, st->time3[st->who - 1]), st->who);
	sum_count(st, -1);
	if (!ch_count(st))
		sum_deathflag(st, 1);
	pthread_mutex_lock(&st->m_eating[st->who - 1]);
	st->eating[st->who - 1] = 1;
	printf("%ld %d is eating\n",
		timecal(st->time, st->time3[st->who - 1]), st->who);
	ft_sleep(st->eat_time * 1000, st->time3[st->who - 1]);
	st->eating[st->who - 1] = 0;
	pthread_mutex_unlock(&st->m_eating[st->who - 1]);
	pthread_mutex_unlock(&st->mutex[st->right]);
	pthread_mutex_unlock(&st->mutex[st->left]);
}

void	take_eat(t_philo *st)
{
	pthread_mutex_lock(&st->mutex[st->right]);
	if (ch_deathflag(st))
	{
		pthread_mutex_unlock(&st->mutex[st->right]);
		return ;
	}
	if (ch_right(st))
		return ;
	gettimeofday(&st->time2, NULL);
	printf("%ld %d has taken a fork\n", timecal(st->time, st->time2), st->who);
	pthread_mutex_lock(&st->mutex[st->left]);
	if (ch_deathflag(st))
	{
		pthread_mutex_unlock(&st->mutex[st->right]);
		pthread_mutex_unlock(&st->mutex[st->left]);
		return ;
	}
	if (ch_left(st))
		return ;
	take_eat2(st);
}

void	take_sleep(t_philo *st)
{
	gettimeofday(&st->time2, NULL);
	if (ch_deathflag(st))
		return ;
	printf("%ld %d is sleeping\n", timecal(st->time, st->time2), st->who);
	ft_sleep(st->sleep_time * 1000, st->time2);
}

// void	initsleep(t_philo *st)
// {
// 	if (st->who % 2)

// }
