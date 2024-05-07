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
	int				death_flag;
	suseconds_t		eat_time;
	suseconds_t		sleep_time;
	suseconds_t		death_time;
	struct timeval	*time;
}	t_philo;

#endif
