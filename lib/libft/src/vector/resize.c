/* ************************************************************************** */
/*                                                                            */
/*                                                         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   */
/*   resize.c                                              ⠀⠀⠀⠀⢀⣴⣿⠟⠁ ⣿⠟⢹⣿⣿⠀   */
/*                                                         ⠀⠀⢀⣴⣿⠟⠁⠀⠀⠀⠁⢀⣼⣿⠟⠀   */
/*   By: smamalig <smamalig@student.42.fr>                 ⠀⣴⣿⣟⣁⣀⣀⣀⡀⠀⣴⣿⡟⠁⢀⠀   */
/*                                                         ⠀⠿⠿⠿⠿⠿⣿⣿⡇⠀⣿⣿⣇⣴⣿⠀   */
/*   Created: 2025/06/04 18:10:27 by smamalig              ⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀   */
/*   Updated: 2025/06/05 08:26:44 by smamalig              ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stddef.h>

t_result	ft_vector_resize(t_vector *vec, size_t size)
{
	t_value	*save_ptr;
	t_value	*new_data;
	size_t	real_offset;

	if (size <= vec->capacity)
		return (RESULT_ERROR);
	new_data = ft_malloc(size * sizeof(t_value));
	if (!new_data)
		return (RESULT_ERROR);
	real_offset = vec->offset % vec->capacity;
	save_ptr = ft_mempcpy(new_data, vec->data + real_offset,
			sizeof(t_value) * (vec->capacity - real_offset));
	ft_memcpy(save_ptr, vec->data, sizeof(t_value) * real_offset);
	free(vec->data);
	vec->data = new_data;
	vec->capacity = size;
	vec->offset = 0;
	return (RESULT_OK);
}
