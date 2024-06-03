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

#include<philosopher.h>

void	take_eat(t_philo *st)
{
	pthread_mutex_lock(&st->mutex[st->who - 1]);
	if (st->death_flag)
		return ;
	gettimeofday(&st->time2, NULL);
	printf("%4ld %d has taken a fork\n", (st->time2).tv_usec - (st->time).tv_usec / 1000, st->who);
	pthread_mutex_lock(&st->mutex[st->who]);
	if (st->death_flag)
		return ;
	gettimeofday(st->time3, NULL);
	printf("%4ld %d has taken a fork\n", (st->time3)->tv_usec - (st->time).tv_usec / 1000, st->who);
	printf("%4ld %d is eating\n", (st->time3)->tv_usec - (st->time).tv_usec / 1000, st->who);
	usleep(st->eat_time * 1000);
}

void	take_sleep(t_philo *st)
{
	gettimeofday(&st->time2, NULL);
	if (st->death_flag)
		return ;
	printf("%4ld %d is sleeping\n", (st->time2).tv_usec - (st->time).tv_usec / 1000, st->who);
}

void	take_think(t_philo *st)
{
	gettimeofday(&st->time2, NULL);
	if (st->death_flag)
		return ;
	printf("%4ld %d is thinking\n", (st->time2).tv_usec - (st->time).tv_usec / 1000, st->who);
}
