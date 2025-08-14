/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 08:45:16 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 10:10:59 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"
#include <stddef.h>

static inline _Bool	ft_file_can_advance(t_file *file)
{
	return (file->curr + 1 < file->buf + file->len);
}

static t_result	ft_file_fill(t_file *file)
{
	ssize_t	bytes_read;
	size_t	remaining;

	if (file->curr > file->buf)
	{
		remaining = (size_t)(file->len - (size_t)(file->curr - file->buf));
		ft_memmove(file->buf, file->curr, remaining);
		file->curr = file->buf;
		file->len = (unsigned int)remaining;
	}
	bytes_read = read(file->fd, file->buf + file->len,
			FILE_BUFFER_SIZE - file->len);
	if (bytes_read < 0)
		return (RESULT_ERROR);
	if (bytes_read == 0)
	{
		file->eof = true;
		return (RESULT_EOF);
	}
	file->len += (unsigned int)bytes_read;
	return (RESULT_OK);
}

t_result	_ft_file_advance(t_file *file)
{
	t_result	result;

	if (!ft_file_can_advance(file))
	{
		result = ft_file_fill(file);
		if (result != RESULT_OK)
			return (result);
	}
	if (*file->curr == '\n')
		file->line++;
	file->curr++;
	return (RESULT_OK);
}
