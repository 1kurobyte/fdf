/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:45:46 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 07:46:57 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "worldgen.h"
#include <fcntl.h>
#include <stdint.h>

static uint32_t	switch_line(t_file *file, t_map *map, int32_t *p_width)
{
	map->width = ft_max(map->width, *p_width);
	map->height++;
	*p_width = 0;
	return (file->line);
}

static t_result	count_pass(t_file *file, t_map *map)
{
	int32_t		num;
	int32_t		cur_width;
	t_result	result;
	uint32_t	prev_line;

	cur_width = 0;
	prev_line = 1;
	while (1)
	{
		if (file->line != prev_line)
			prev_line = switch_line(file, map, &cur_width);
		result = ft_file_atoi32(file, &num);
		if (result == RESULT_EOF)
			break ;
		if (result != RESULT_OK)
			return (result);
		map->alt_min = ft_min(map->alt_min, num);
		map->alt_max = ft_max(map->alt_max, num);
		cur_width++;
	}
	if (cur_width > 0)
		map->height++;
	map->width = ft_max(map->width, cur_width);
	return (RESULT_OK);
}

static t_result	retrieve_pass(t_file *file, t_map *map)
{
	t_result	result;
	int32_t		num;
	int32_t		i;

	map->elevation = ft_malloc(
			(uint32_t)map->height * (uint32_t)map->width * sizeof(int32_t));
	if (!map->elevation)
		return (RESULT_ERROR);
	i = -1;
	while (++i < map->width * map->height)
	{
		result = ft_file_atoi32(file, &num);
		if (result != RESULT_OK)
			return (result);
		map->elevation[i] = num;
	}
	return (RESULT_OK);
}

t_result	worldgen_init(t_fdf *fdf, char *filename)
{
	int		fd;
	t_file	file;

	if (!filename)
		return (RESULT_ERROR);
	fdf->map.alt_min = INT_MAX;
	fdf->map.alt_max = INT_MIN;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (RESULT_ERROR);
	if (ft_file_init(&file, fd) != RESULT_OK
		|| count_pass(&file, &fdf->map) != RESULT_OK)
		return (close(fd), RESULT_ERROR);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (RESULT_ERROR);
	if (ft_file_init(&file, fd) != RESULT_OK
		|| retrieve_pass(&file, &fdf->map) != RESULT_OK)
		return (close(fd), RESULT_ERROR);
	close(fd);
	ft_printf("[INFO] Parsed map: width=%d, height=%d\n",
		fdf->map.width, fdf->map.height);
	return (RESULT_OK);
}
