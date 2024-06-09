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
	int				*death_flag;
	int				eat_time;
	int				sleep_time;
	int				death_time;
	struct timeval	time;
	struct timeval	time2;
	struct timeval	*time3;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	int				left;
	int				right;
	int				*eating;
	int				error;
}	t_philo;

void	take_eat(t_philo *st);
void	take_sleep(t_philo *st);
void	imchecker(t_philo *st);
long	timecal(struct timeval time1, struct timeval time2);
#endif
