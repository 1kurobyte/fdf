/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:10:48 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 13:52:14 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include "common.h"
# include "libft.h"
# include <bits/pthreadtypes.h>

typedef void	(*t_task_fn)(void *);

typedef struct s_task
{
	t_task_fn	fn;
	void		*arg;
}	t_task;

typedef struct s_threadpool
{
	pthread_t		threads[NUM_THREADS];
	t_task			task_queue[MAX_TASKS];
	int				task_count;
	int				task_index;
	pthread_mutex_t	lock;
	pthread_cond_t	cond;
	pthread_cond_t	done_cond;
	int				active_workers;
	int				stop;
}	t_threadpool;

t_result	threadpool_init(t_threadpool *pool);
void		threadpool_add(t_threadpool *pool, t_task_fn fn, void *arg);
void		threadpool_run(t_threadpool *pool);
void		threadpool_destroy(t_threadpool *pool);

#endif
