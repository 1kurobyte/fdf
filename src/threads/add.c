/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:34:38 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 13:34:50 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"
#include <pthread.h>

void	threadpool_add(t_threadpool *pool, t_task_fn fn, void *arg)
{
	pthread_mutex_lock(&pool->lock);
	pool->task_queue[pool->task_count++] = (t_task){fn, arg};
	pthread_mutex_unlock(&pool->lock);
}
