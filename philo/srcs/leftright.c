/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftright.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:23:01 by tashiget          #+#    #+#             */
/*   Updated: 2024/06/17 16:23:01 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ch_right2(t_philo *st)
{
	if (st->who != st->num_philo
		&& timecal(st->time3[st->who], st->time3[st->who - 1]) > 0)
	{
		pthread_mutex_unlock(&st->mutex[st->right]);
		if (ch_deathflag(st))
			return (1);
		pthread_mutex_lock(&st->mutex[st->right]);
	}
	else if (st->who == st->num_philo
		&& timecal(st->time3[0], st->time3[st->who - 1]) > 0)
	{
		pthread_mutex_unlock(&st->mutex[st->right]);
		if (ch_deathflag(st))
			return (1);
		pthread_mutex_lock(&st->mutex[st->right]);
	}
	return (0);
}

int	ch_right(t_philo *st)
{
	if (st->who % 2)
	{
		if (ch_right2(st))
			return (1);
	}
	else
	{
		if (timecal(st->time3[st->who - 2], st->time3[st->who - 1]) > 0)
		{
			pthread_mutex_unlock(&st->mutex[st->right]);
			if (ch_deathflag(st))
				return (1);
			pthread_mutex_lock(&st->mutex[st->right]);
		}
	}
	return (0);
}

int	ch_left2(t_philo *st)
{
	if (st->who != 1
		&& timecal(st->time3[st->who - 2], st->time3[st->who - 1]) > 0)
	{
		pthread_mutex_unlock(&st->mutex[st->left]);
		if (ch_deathflag(st))
			return (1);
		pthread_mutex_lock(&st->mutex[st->left]);
	}
	else if (st->who == 1
		&& timecal(st->time3[st->num_philo - 1], st->time3[st->who - 1]) > 0)
	{
		pthread_mutex_unlock(&st->mutex[st->left]);
		if (ch_deathflag(st))
			return (1);
		pthread_mutex_lock(&st->mutex[st->left]);
	}
	return (0);
}

int	ch_left(t_philo *st)
{
	if (st->who % 2 && ch_left2(st))
		return (1);
	else
	{
		if (!st->who % 2 && st->who != st->num_philo
			&& timecal(st->time3[st->who], st->time3[st->who - 1]) > 0)
		{
			pthread_mutex_unlock(&st->mutex[st->left]);
			if (ch_deathflag(st))
				return (1);
			pthread_mutex_lock(&st->mutex[st->left]);
		}
		else if (!st->who % 2 && st->who == st->num_philo
			&& timecal(st->time3[0], st->time3[st->who - 1]) > 0)
		{
			pthread_mutex_unlock(&st->mutex[st->left]);
			if (ch_deathflag(st))
				return (1);
			pthread_mutex_lock(&st->mutex[st->left]);
		}
	}
	return (0);
}
