/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:33:22 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 13:33:37 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"
#include <pthread.h>
#include <stdint.h>

void	threadpool_destroy(t_threadpool *pool)
{
	int32_t	i;

	pthread_mutex_lock(&pool->lock);
	pool->stop = 1;
	pthread_cond_broadcast(&pool->cond);
	pthread_mutex_unlock(&pool->lock);
	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(pool->threads[i], NULL);
	pthread_mutex_destroy(&pool->lock);
	pthread_cond_destroy(&pool->cond);
	pthread_cond_destroy(&pool->done_cond);
}
