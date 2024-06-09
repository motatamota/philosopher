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

	st = (t_philo *)cal;
	if (st->who == 0)
	{
		imchecker(st);
		return (NULL);
	}
	if (st->who % 2)
		usleep(300);
	if (st->who == 1)
		usleep(300);
	while (1)
	{
		if (*st->death_flag || st->error)
			break ;
		take_eat(st);
		take_sleep(st);
	}
	usleep(10000000);
	free(st);
	return (NULL);
}

int	initst(t_philo *st)
{
	gettimeofday(&st->time, NULL);
	st->thread = (pthread_t *)malloc(sizeof(pthread_t) * (st->num_philo + 1));
	st->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * st->num_philo);
	st->time3 = (struct timeval *)malloc(sizeof(struct timeval) * st->num_philo);
	st->eating = (int *)malloc(sizeof(int) * st->num_philo);
	st->death_flag = (int *)malloc(sizeof(int));
	if (!st->thread || !st->mutex || !st->time3 || !st->eating || !st->death_flag)
		return (1);
	*st->death_flag = 0;
	memset(st->eating, 0, sizeof(int) * st->num_philo);
	memset(st->time3, 0, sizeof(struct timeval) * st->num_philo);
	return (0);
}

void	set_lr(t_philo *st)
{
	int	p;

	st->right = st->who - 1;
	st->left = st->who;
	if (st->who == st->num_philo)
		st->left = 0;
	if (st->who % 2)
	{
		p = st->left;
		st->left = st->right;
		st->right = p;
	}
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
	if (n != cp->num_philo && (pthread_mutex_init((cp->mutex) + n, NULL) || pthread_create(cp->thread + n, NULL, philosopher, (void *)cp)))
	{
		free(cp);
		return (1);
	}
	else if (pthread_create(cp->thread + n, NULL, philosopher, (void *)cp))
	{
		free(cp);
		return (1);
	}
}

int	threadcre(t_philo *st)
{
	int				n;
	t_philo			*cp;

	if (initst(st))
		return (1);
	n = 0;
	while (n <= st->num_philo)
	{
		cp = threadcre2(st, n);
		if (!cp)
			return (1);
		ft_memcpy(cp, st, sizeof(t_philo));
		if (n != cp->num_philo && (pthread_mutex_init((cp->mutex) + n, NULL) || pthread_create(cp->thread + n, NULL, philosopher, (void *)cp)))
		{
			free(cp);
			return (1);
		}
		else if (pthread_create(cp->thread + n, NULL, philosopher, (void *)cp))
		{
			free(cp);
			return (1);
		}
		n++;
	}
	n = -1;
	while (++n < st->num_philo)
		pthread_join(*(st->thread + n), NULL);
	return (0);
}

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

void	free_philo(t_philo *st)
{
	if (st->thread)
		free(st->thread);
	if (st->mutex)
		destroy_mutex(st);
	if (st->eating)
		free(st->eating);
	if (st->time3)
		free(st->time3);
	if (st->death_flag)
		free(st->death_flag);
}

int	main(int ac, char **av)
{
	t_philo			st;

	if (ac != 5)
		return (1);
	st.error = 0;
	st.num_philo = ft_atoi(*(av + 1));
	st.death_time = ft_atoi(*(av + 2));
	st.eat_time = ft_atoi(*(av + 3));
	st.sleep_time = ft_atoi(*(av + 4));
	gettimeofday(&st.time, NULL);
	if (threadcre(&st))
	{
		st.error = 1;
		free_philo(&st);
		return (1);
	}
	free_philo(&st);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q philosopher");
// }
