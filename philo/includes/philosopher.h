/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:48:04 by tashiget          #+#    #+#             */
/*   Updated: 2024/05/07 10:48:04 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include "libft.h"

typedef struct s_philo
{
	int				num_philo;
	int				who;
	pthread_mutex_t	m_death_flag_i;
	pthread_mutex_t	*m_death_flag;
	int				*death_flag;
	int				eat_time;
	int				sleep_time;
	int				death_time;
	struct timeval	time;
	struct timeval	time2;
	pthread_mutex_t	*m_time3;
	struct timeval	*time3;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	int				left;
	int				right;
	pthread_mutex_t	*m_eating;
	int				*eating;
	int				error;
	pthread_mutex_t	m_count_i;
	pthread_mutex_t	*m_count;
	int				*count;
	int				m_flag;
}	t_philo;

void	take_eat(t_philo *st);
void	take_sleep(t_philo *st);
void	imchecker(t_philo *st);
long	timecal(struct timeval time1, struct timeval time2);
int		ft_error(int ac, char **av, t_philo *st);
void	destroy_mutex(t_philo *st);
void	destroy_mutex_eating(t_philo *st);
int		threadcre(t_philo *st);
int		initst(t_philo *st);
void	set_lr(t_philo *st);
void	*philosopher(void *cal);
int		ch_deathflag(t_philo *st);
int		ch_count(t_philo *st);
int		sum_deathflag(t_philo *st, int x);
int		sum_count(t_philo *st, int x);
void	destroy_one_mutex(pthread_mutex_t *st);
int		initmutex(t_philo *st);
void	all_zero(t_philo *st);
int		ch_left(t_philo *st);
int		ch_right(t_philo *st);
#endif
