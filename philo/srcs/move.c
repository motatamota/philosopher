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
	st->eating[st->who - 1] = 1;
	(*st->count)--;
	if (!*st->count)
		*st->death_flag = 1;
	printf("%ld %d is eating\n",
		timecal(st->time, st->time3[st->who - 1]), st->who);
	usleep(st->eat_time * 1000);
	st->eating[st->who - 1] = 0;
	pthread_mutex_unlock(&st->mutex[st->right]);
	pthread_mutex_unlock(&st->mutex[st->left]);
}

void	take_eat(t_philo *st)
{
	pthread_mutex_lock(&st->mutex[st->right]);
	if (*st->death_flag)
	{
		pthread_mutex_unlock(&st->mutex[st->right]);
		return ;
	}
	gettimeofday(&st->time2, NULL);
	printf("%ld %d has taken a fork\n", timecal(st->time, st->time2), st->who);
	pthread_mutex_lock(&st->mutex[st->left]);
	if (*st->death_flag)
	{
		pthread_mutex_unlock(&st->mutex[st->left]);
		return ;
	}
	take_eat2(st);
}

void	take_sleep(t_philo *st)
{
	gettimeofday(&st->time2, NULL);
	if (*st->death_flag)
		return ;
	printf("%ld %d is sleeping\n", timecal(st->time, st->time2), st->who);
	usleep(st->sleep_time * 1000);
}
