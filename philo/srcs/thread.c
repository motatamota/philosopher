/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:31:39 by tashiget          #+#    #+#             */
/*   Updated: 2024/06/09 15:31:39 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	destroy_mutex(t_philo *st)
{
	int	n;

	n = 0;
	while (n < st->num_philo)
	{
		pthread_mutex_destroy(&st->mutex[n]);
		n++;
	}
	free(st->mutex);
}

t_philo	*threadcre2(t_philo *st, int n)
{
	t_philo	*cp;

	st->who = n;
	set_lr(st);
	cp = (t_philo *)malloc(sizeof(t_philo));
	if (!cp)
		return (0);
	return (cp);
}

int	threadcre3(t_philo *cp, int n)
{
	if (n != cp->num_philo && (pthread_mutex_init((cp->mutex) + n, NULL)
			|| pthread_create(cp->thread + n, NULL, philosopher, (void *)cp)))
	{
		free(cp);
		return (1);
	}
	else if (n == cp->num_philo && pthread_create(cp->thread + n, NULL,
			philosopher, (void *)cp))
	{
		free(cp);
		return (1);
	}
	return (0);
}

int	threadcre(t_philo *st)
{
	int				n;
	t_philo			*cp;

	if (initst(st))
		return (1);
	n = 0;
	gettimeofday(&st->time, NULL);
	while (n <= st->num_philo)
	{
		cp = threadcre2(st, n);
		if (!cp)
			return (1);
		ft_memcpy(cp, st, sizeof(t_philo));
		threadcre3(cp, n);
		n++;
	}
	n = -1;
	while (++n <= st->num_philo)
		pthread_join(*(st->thread + n), NULL);
	return (0);
}
