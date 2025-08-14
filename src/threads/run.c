/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:33:57 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 18:53:45 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"
#include <pthread.h>

void	threadpool_run(t_threadpool *pool)
{
	pthread_mutex_lock(&pool->lock);
	pool->task_index = 0;
	pthread_cond_broadcast(&pool->cond);
	pthread_mutex_unlock(&pool->lock);
	pthread_mutex_lock(&pool->lock);
	while (pool->active_workers > 0 || pool->task_index < pool->task_count)
		pthread_cond_wait(&pool->done_cond, &pool->lock);
	pool->task_count = 0;
	pthread_mutex_unlock(&pool->lock);
}
