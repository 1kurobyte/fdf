/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:32:58 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 08:39:44 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <assert.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
# include <time.h>
# include <unistd.h>
# include <limits.h>

# include "libft_printf.h"

typedef struct s_rng256
{
	uint64_t	s[4];
	uint64_t	seed;
}	t_rng256;

typedef enum e_result
{
	RESULT_OK,
	RESULT_ERROR,
	RESULT_OVERFLOW,
	RESULT_EOF,
	RESULT_INVAL,
	RESULT_READ_ERROR,
	RESULT_UNKNOWN
}	t_result;

typedef enum e_type
{
	TYPE_UNDEFINED,
	TYPE_OTHER,
}	t_type;

typedef union u_any
{
	void		*ptr;
	char		*str;
	uint64_t	u64;
	int64_t		i64;
	uint32_t	u32;
	int32_t		i32;
	_Float32	f32;
	_Float64	f64;
}	t_any;

typedef struct s_value
{
	t_type	type;
	int		reserved;
	t_any	value;
}	t_value;

/* ************************************************************************** */
/* ALLOC                                                                      */
/* ************************************************************************** */

void		*ft_calloc(size_t n, size_t size);
void		ft_free(void *ptr);
void		*ft_malloc(size_t size);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);

/* ************************************************************************** */
/* RANDOM                                                                     */
/* ************************************************************************** */

void		ft_rng_init(t_rng256 *rng, uint64_t seed);
uint64_t	ft_rng_u64(t_rng256 *rng);
uint32_t	ft_rng_u32(t_rng256 *rng);
double		ft_rng_f64(t_rng256 *rng);

/* ************************************************************************** */
/* CHECKS                                                                     */
/* ************************************************************************** */

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isblank(int c);
int			ft_iscntrl(int c);
int			ft_isdigit(int c);
int			ft_isgraph(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_ispunct(int c);
int			ft_isspace(int c);
int			ft_isupper(int c);
int			ft_isxdigit(int c);

/* ************************************************************************** */
/* CONVERT                                                                    */
/* ************************************************************************** */

int			ft_atoi(const char *nptr);
int			ft_atoi_safe(const char *nptr);
long		ft_atol(const char *nptr);
long		ft_atol_safe(const char *nptr);
long long	ft_atoll(const char *nptr);
long long	ft_atoll_safe(const char *nptr);
int			ft_toupper(int c);
int			ft_tolower(int c);

/* ************************************************************************** */
/* INPUT / OUTPUT                                                             */
/* ************************************************************************** */

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/* ************************************************************************** */
/* MATH                                                                       */
/* ************************************************************************** */

int			ft_abs(int n);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			ft_nmax(int n, ...);
int			ft_nmin(int n, ...);
int			ft_intlen(int n);

/* ************************************************************************** */
/* MEMORY                                                                     */
/* ************************************************************************** */

void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_mempcpy(void *dst, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);

/* ************************************************************************** */
/* STRING                                                                     */
/* ************************************************************************** */

char		*ft_stpcpy(char *dst, const char *src);
char		*ft_stpncpy(char *dst, const char *src, size_t n);

size_t		ft_strlen(const char *s);
size_t		ft_strnlen(const char *s, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcoll(const char *s1, const char *s2);
int			ft_strerror_r(int errnum, char *buf, size_t size);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t dsize);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strncat(char *dst, const char *src, size_t ssize);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strpbrk(const char *s, const char *accept);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strtok(char *str, const char *delim);
char		*ft_strtok_r(char *str, const char *delim, char **saveptr);
char		*ft_strerror(int errnum);
char		*ft_strsignal(int sig);
size_t		ft_strcspn(const char *s, const char *reject);
size_t		ft_strspn(const char *s, const char *accept);
size_t		ft_strxfrm(char *dst, const char *src, size_t n);

size_t		ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dsize);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);

char		*ft_substr(const char *s, size_t start, size_t size);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s, const char *trim);
char		**ft_split(const char *s, char delim);
char		*ft_itoa(int n);
char		*ft_strmapi(const char *s, char (*f)(size_t, char));
void		ft_striteri(char *s, void (*f)(size_t, char *));

/* ************************************************************************** */
/* LINKED LIST                                                                */
/* ************************************************************************** */

typedef struct s_list
{
	t_value			data;
	struct s_list	*next;
}	t_list;

size_t		ft_list_size(t_list *list);
t_list		*ft_list_new(t_value data);
t_list		*ft_list_last(t_list *list);
t_list		*ft_list_at(t_list *list, ssize_t n);
void		ft_list_pushfront(t_list **ptr, t_list *el);
void		ft_list_pushback(t_list **ptr, t_list *el);
void		ft_list_delete(t_list *el, void (*del)(t_value));
void		ft_list_clear(t_list **ptr, void (*del)(t_value));
void		ft_list_foreach(t_list *list, void (*f)(t_value));
t_list		*ft_list_map(t_list *list, t_value (*f)(t_value));
void		ft_list_remove_if(t_list **ptr, t_value ref,
				int (*cmp)(t_value, t_value), void (*free_data)(t_value));
void		ft_list_reverse(t_list **ptr);

/* ************************************************************************** */
/* VECTOR                                                                     */
/* ************************************************************************** */

typedef struct s_vector
{
	size_t	length;
	size_t	capacity;
	size_t	offset;
	t_value	*data;
}	t_vector;

t_value		ft_gen_val(t_type type, t_any value);

t_result	ft_vector_init(t_vector *vec, size_t size);
t_result	ft_vector_resize(t_vector *vec, size_t size);
void		ft_vector_free(t_vector *vec);
void		ft_vector_foreach(t_vector *vec,
				void (*fn)(size_t idx, t_value data));
void		ft_vector_map(t_vector *vec,
				t_value (*fn)(size_t idx, t_value data));
_Bool		ft_vector_every(t_vector *vec,
				_Bool (*fn)(size_t idx, t_value data));
_Bool		ft_vector_some(t_vector *vec,
				_Bool (*fn)(size_t idx, t_value data));
t_value		ft_vector_pop(t_vector *vec);
t_value		ft_vector_shift(t_vector *vec);
t_result	ft_vector_push(t_vector *vec, t_value value);
t_result	ft_vector_unshift(t_vector *vec, t_value value);
t_value		ft_vector_at(t_vector *vec, ssize_t idx);

/* ************************************************************************** */
/* BINARY TREE                                                                */
/* ************************************************************************** */

/* ************************************************************************** */
/* HASHMAP                                                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/* FILE                                                                       */
/* ************************************************************************** */

# ifndef FILE_BUFFER_SIZE
#  define FILE_BUFFER_SIZE 1024
# endif

typedef struct s_file
{
	int				fd;
	unsigned int	len;
	unsigned int	line;
	_Bool			eof;
	char			reserved[3];
	char			*curr;
	char			buf[FILE_BUFFER_SIZE];
}	t_file;

t_result	try(t_result res);

t_result	ft_file_init(t_file *file, int fd);
t_result	ft_file_i8(t_file *file, uint8_t *ret);
t_result	ft_file_u8(t_file *file, uint8_t *ret);
t_result	ft_file_atoi32(t_file *file, int32_t *ret);
t_result	ft_file_atou32(t_file *file, uint32_t *ret);
t_result	ft_file_atox32(t_file *file, uint32_t *ret);
t_result	ft_file_consume(t_file *file, char c, _Bool *found);

_Bool		ft_file_eof(t_file *file);

#endif
