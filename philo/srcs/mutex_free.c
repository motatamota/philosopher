/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:10:14 by tashiget          #+#    #+#             */
/*   Updated: 2024/06/17 13:10:14 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	destroy_one_mutex(pthread_mutex_t *st)
{
	pthread_mutex_destroy(st);
	free(st);
}

void	all_zero(t_philo *st)
{
	st->thread = NULL;
	st->mutex = NULL;
	st->eating = NULL;
	st->time3 = NULL;
	st->death_flag = NULL;
	st->count = NULL;
	st->m_eating = NULL;
	st->m_death_flag = NULL;
	st->m_count = NULL;
}
