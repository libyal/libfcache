/*
 * Cache value functions
 *
 * Copyright (C) 2010-2024, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFCACHE_CACHE_VALUE_H )
#define _LIBFCACHE_CACHE_VALUE_H

#include <common.h>
#include <types.h>

#include "libfcache_extern.h"
#include "libfcache_libcerror.h"
#include "libfcache_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfcache_internal_cache_value libfcache_internal_cache_value_t;

struct libfcache_internal_cache_value
{
	/* The cache index
	 */
	int cache_index;

	/* The file index
	 */
	int file_index;

	/* The offset
	 */
	off64_t offset;

	/* The timestamp
	 */
	int64_t timestamp;

	/* The value
	 */
	intptr_t *value;

	/* The value free function
	 */
	int (*value_free_function)(
	       intptr_t **value,
	       libcerror_error_t **error );

	/* The flags
	 */
	uint8_t flags;
};

int libfcache_cache_value_initialize(
     libfcache_cache_value_t **cache_value,
     libcerror_error_t **error );

LIBFCACHE_EXTERN \
int libfcache_cache_value_free(
     libfcache_cache_value_t **cache_value,
     libcerror_error_t **error );

LIBFCACHE_EXTERN \
int libfcache_cache_value_clear(
     libfcache_cache_value_t *cache_value,
     libcerror_error_t **error );

LIBFCACHE_EXTERN \
int libfcache_cache_value_get_identifier(
     libfcache_cache_value_t *cache_value,
     int *file_index,
     off64_t *offset,
     int64_t *timestamp,
     libcerror_error_t **error );

int libfcache_cache_value_get_cache_index(
     libfcache_cache_value_t *cache_value,
     int *cache_index,
     libcerror_error_t **error );

LIBFCACHE_EXTERN \
int libfcache_cache_value_set_identifier(
     libfcache_cache_value_t *cache_value,
     int file_index,
     off64_t offset,
     int64_t timestamp,
     libcerror_error_t **error );

int libfcache_cache_value_set_cache_index(
     libfcache_cache_value_t *cache_value,
     int cache_index,
     libcerror_error_t **error );

LIBFCACHE_EXTERN \
int libfcache_cache_value_get_value(
     libfcache_cache_value_t *cache_value,
     intptr_t **value,
     libcerror_error_t **error );

LIBFCACHE_EXTERN \
int libfcache_cache_value_set_value(
     libfcache_cache_value_t *cache_value,
     intptr_t *value,
     int (*value_free_function)(
            intptr_t **value,
            libcerror_error_t **error ),
     uint8_t flags,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFCACHE_CACHE_VALUE_H ) */

