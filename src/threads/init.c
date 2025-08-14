/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:15:05 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 18:54:07 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"
#include "libft.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

static void	*worker_loop(void *arg)
{
	t_threadpool	*pool;
	t_task			task;

	pool = (t_threadpool *)arg;
	while (1)
	{
		pthread_mutex_lock(&pool->lock);
		while (pool->task_index >= pool->task_count && !pool->stop)
			pthread_cond_wait(&pool->cond, &pool->lock);
		if (pool->stop)
		{
			pthread_mutex_unlock(&pool->lock);
			break ;
		}
		task = pool->task_queue[pool->task_index++];
		pool->active_workers++;
		pthread_mutex_unlock(&pool->lock);
		task.fn(task.arg);
		pthread_mutex_lock(&pool->lock);
		if (--pool->active_workers == 0 && pool->task_index >= pool->task_count)
			pthread_cond_signal(&pool->done_cond);
		pthread_mutex_unlock(&pool->lock);
	}
	return (NULL);
}

t_result	threadpool_init(t_threadpool *pool)
{
	int32_t	i;

	ft_memset(pool, 0, sizeof(t_threadpool));
	pool->task_count = 0;
	pool->task_index = 0;
	pool->active_workers = 0;
	pool->stop = 0;
	pthread_mutex_init(&pool->lock, NULL);
	pthread_cond_init(&pool->cond, NULL);
	pthread_cond_init(&pool->done_cond, NULL);
	i = -1;
	while (++i < NUM_THREADS)
	{
		if (pthread_create(&pool->threads[i], NULL, worker_loop, pool) != 0)
		{
			threadpool_destroy(pool);
			return (RESULT_ERROR);
		}
	}
	return (RESULT_OK);
}
