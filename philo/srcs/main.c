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
	gettimeofday(&time, NULL);
	usleep(1000000 - (time.tv_usec - st->time->tv_usec) + st->who * 300);
	printf("success!%d\n", st->who);
	free(st);
	return (NULL);
}

int	threadcre(t_philo *st)
{
	int			n;
	pthread_t	*thread;
	t_philo		*cp;

	n = 0;
	gettimeofday(st->time, NULL);
	thread = (pthread_t *)malloc(sizeof(pthread_t) * st->num_philo);
	if (!thread)
		return (1);
	while (n < st->num_philo)
	{
		st->who = n + 1;
		cp = (t_philo *)malloc(sizeof(t_philo));
		ft_memcpy(cp, st, sizeof(t_philo));
		if (pthread_create(thread + n, NULL, philosopher, (void *)cp))
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
		return (1);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q philosopher");
// }
