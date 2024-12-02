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
	while (1)
	{
		if (ch_deathflag(st) || st->error)
			break ;
		take_eat(st);
		take_sleep(st);
	}
	usleep(200000);
	if (st)
		free(st);
	st = NULL;
	return (NULL);
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
	if (st->count)
		free(st->count);
	if (st->m_eating)
		destroy_mutex_eating(st);
	all_zero(st);
}

void	onetry(t_philo *st)
{
	printf("0 1 has taken a fork\n");
	usleep(st->death_time * 1000);
	printf("%d is died\n", st->death_time);
	free(st->count);
}

int	main(int ac, char **av)
{
	t_philo			st;

	if (ft_error(ac, av, &st))
		return (1);
	st.error = 0;
	st.num_philo = ft_atoi(*(av + 1));
	st.death_time = ft_atoi(*(av + 2));
	st.eat_time = ft_atoi(*(av + 3));
	st.sleep_time = ft_atoi(*(av + 4));
	if (!strncmp("1", *(av + 1), 2))
	{
		onetry(&st);
		return (0);
	}
	else if (threadcre(&st))
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
