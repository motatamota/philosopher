/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:45:28 by tashiget          #+#    #+#             */
/*   Updated: 2024/05/07 10:45:28 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philosopher(void *cal)
{
	t_philo	*st;
	struct timeval time;

	st = (t_philo *)cal;
	gettimeofday(st->time, NULL);
	if (st->who % 2)
		usleep(300);
	while (1)
	{
		take_eat(st);
		take_sleep(st);
		take_think(st);
	}
	free(st);
	return (NULL);
}

int	threadcre(t_philo *st)
{
	int				n;
	pthread_t		*thread;
	t_philo			*cp;

	n = 0;
	gettimeofday(st->time, NULL);
	thread = (pthread_t *)malloc(sizeof(pthread_t) * st->num_philo);
	st->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * st->num_philo);
	if (!thread)
		return (1);
	while (n < st->num_philo)
	{
		st->who = n + 1;
		cp = (t_philo *)malloc(sizeof(t_philo));
		ft_memcpy(cp, st, sizeof(t_philo));
		if (pthread_create(thread + n, NULL, philosopher, (void *)cp))
			return (1);
		if (pthread_mutex_init((st->mutex) + n, NULL))
			return (1);
		n++;
	}
	n = -1;
	while (++n < st->num_philo)
		pthread_join(*(thread + n), NULL);
	free(thread);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo			st;
	struct timeval	time;

	if (ac != 5)
		return (1);
	st.num_philo = ft_atoi(*(av + 1));
	st.death_time = ft_atoi(*(av + 2));
	st.eat_time = ft_atoi(*(av + 3));
	st.sleep_time = ft_atoi(*(av + 4));
	st.time = &time;
	st.death_flag = 0;
	if (threadcre(&st))
	{
		free_philo();
		return (1);
	}
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q philosopher");
// }
