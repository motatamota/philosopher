/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:09:54 by tashiget          #+#    #+#             */
/*   Updated: 2024/06/17 12:09:54 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ch_deathflag(t_philo *st)
{
	pthread_mutex_lock(st->m_death_flag);
	if (*st->death_flag == 1)
	{
		pthread_mutex_unlock(st->m_death_flag);
		return (1);
	}
	pthread_mutex_unlock(st->m_death_flag);
	return (0);
}

int	sum_deathflag(t_philo *st, int x)
{
	pthread_mutex_lock(st->m_death_flag);
	*st->death_flag += x;
	pthread_mutex_unlock(st->m_death_flag);
	return (0);
}

int	ch_count(t_philo *st)
{
	pthread_mutex_lock(st->m_count);
	if (*st->count != 0)
	{
		pthread_mutex_unlock(st->m_count);
		return (1);
	}
	pthread_mutex_unlock(st->m_count);
	return (0);
}

int	sum_count(t_philo *st, int x)
{
	pthread_mutex_lock(st->m_count);
	*st->count += x;
	pthread_mutex_unlock(st->m_count);
	return (0);
}

int	initmutex(t_philo *st)
{
	st->m_death_flag = &st->m_death_flag_i;
	st->m_count = &st->m_count_i;
	if (pthread_mutex_init(st->m_death_flag, NULL)
		|| pthread_mutex_init(st->m_count, NULL))
		return (1);
	return (0);
}
