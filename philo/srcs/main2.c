/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:30:50 by tashiget          #+#    #+#             */
/*   Updated: 2024/06/09 15:30:50 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	checknum(char *str)
{
	int	n;

	n = 0;
	while (*(str + n))
	{
		if (*(str + n) < '0' || *(str + n) > '9')
			return (0);
		n++;
	}
	return (1);
}

int	ft_error(int ac, char **av, t_philo *st)
{
	st->count = (int *)malloc(sizeof(int));
	if (!st->count)
		return (1);
	*st->count = 0;
	if (ac != 5 && ac != 6)
		return (1);
	if (ac == 6 && checknum(*(av + 1)) && checknum(*(av + 2))
		&& checknum(*(av + 3)) && checknum(*(av + 4)) && checknum(*(av + 5)))
		*st->count = ft_atoi(*(av + 5));
	if (ac == 5 && checknum(*(av + 1)) && checknum(*(av + 2))
		&& checknum(*(av + 3)) && checknum(*(av + 4)))
		*st->count = -1;
	if (!*st->count)
		return (1);
	return (0);
}

void	set_time3(t_philo *st)
{
	int	n;

	n = 0;
	while (n < st->num_philo)
	{
		gettimeofday(&st->time3[n], NULL);
		n++;
	}
}

void	zeroall(t_philo *st)
{
	st->thread = NULL;
	st->mutex = NULL;
	st->time3 = NULL;
	st->eating = NULL;
	st->death_flag = NULL;
}

int	initst(t_philo *st)
{
	st->m_flag = 0;
	zeroall(st);
	st->thread = (pthread_t *)malloc(sizeof(pthread_t) * (st->num_philo + 1));
	st->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* st->num_philo);
	st->time3 = (struct timeval *)malloc(sizeof(struct timeval)
			* st->num_philo);
	st->eating = (int *)malloc(sizeof(int) * st->num_philo);
	st->death_flag = (int *)malloc(sizeof(int));
	st->m_eating = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* st->num_philo);
	if (!st->thread || !st->mutex || !st->time3 || !st->eating
		|| !st->death_flag || !st->m_eating || initmutex(st))
		return (1);
	*st->death_flag = 0;
	memset(st->eating, 0, sizeof(int) * st->num_philo);
	set_time3(st);
	return (0);
}
