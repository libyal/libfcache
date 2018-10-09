/*
 * The cache functions
 *
 * Copyright (C) 2010-2018, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <memory.h>
#include <types.h>

#include "libfcache_cache.h"
#include "libfcache_cache_value.h"
#include "libfcache_date_time.h"
#include "libfcache_definitions.h"
#include "libfcache_libcdata.h"
#include "libfcache_libcerror.h"
#include "libfcache_types.h"

/* Creates a cache
 * Make sure the value cache is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfcache_cache_initialize(
     libfcache_cache_t **cache,
     int maximum_cache_entries,
     libcerror_error_t **error )
{
	libfcache_internal_cache_t *internal_cache = NULL;
	static char *function                      = "libfcache_cache_initialize";

	if( cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid cache.",
		 function );

		return( -1 );
	}
	if( *cache != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid cache value already set.",
		 function );

		return( -1 );
	}
	if( maximum_cache_entries <= 0 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_ZERO_OR_LESS,
		 "%s: invalid maximum cache entries value zero or less.",
		 function );

		return( -1 );
	}
	internal_cache = memory_allocate_structure(
	                  libfcache_internal_cache_t );

	if( internal_cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create cache.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     internal_cache,
	     0,
	     sizeof( libfcache_internal_cache_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear cache.",
		 function );

		goto on_error;
	}
	if( libcdata_array_initialize(
	     &( internal_cache->entries ),
	     maximum_cache_entries,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create entries array.",
		 function );

		goto on_error;
	}
	*cache = (libfcache_cache_t *) internal_cache;

	return( 1 );

on_error:
	if( internal_cache != NULL )
	{
		memory_free(
		 internal_cache );
	}
	return( -1 );
}

/* Frees a cache
 * Returns 1 if successful or -1 on error
 */
int libfcache_cache_free(
     libfcache_cache_t **cache,
     libcerror_error_t **error )
{
	libfcache_internal_cache_t *internal_cache = NULL;
	static char *function                      = "libfcache_cache_free";
	int result                                 = 1;

	if( cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid cache.",
		 function );

		return( -1 );
	}
	if( *cache != NULL )
	{
		internal_cache = (libfcache_internal_cache_t *) *cache;
		*cache         = NULL;

		if( libcdata_array_free(
		     &( internal_cache->entries ),
		     (int (*)(intptr_t **, libcerror_error_t **)) &libfcache_cache_value_free,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free the entries array.",
			 function );

			result = -1;
		}
		memory_free(
		 internal_cache );
	}
	return( result );
}

/* Empties the cache
 * Returns 1 if successful or -1 on error
 */
int libfcache_cache_empty(
     libfcache_cache_t *cache,
     libcerror_error_t **error )
{
	libfcache_internal_cache_t *internal_cache = NULL;
	static char *function                      = "libfcache_cache_empty";

	if( cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid cache.",
		 function );

		return( -1 );
	}
	internal_cache = (libfcache_internal_cache_t *) cache;

	if( libcdata_array_clear(
	     internal_cache->entries,
	     (int (*)(intptr_t **, libcerror_error_t **)) &libfcache_cache_value_free,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
		 "%s: unable to clear entries array.",
		 function );

		return( -1 );
	}
	internal_cache->number_of_cache_values = 0;

	return( 1 );
}

/* Clones (duplicates) the cache, not the cache values
 * Returns 1 if successful or -1 on error
 */
int libfcache_cache_clone(
     libfcache_cache_t **destination_cache,
     libfcache_cache_t *source_cache,
     libcerror_error_t **error )
{
	libfcache_internal_cache_t *internal_source_cache = NULL;
	static char *function                             = "libfcache_cache_clone";
	int number_of_cache_entries                       = 0;

	if( destination_cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid destination cache.",
		 function );

		return( -1 );
	}
	if( *destination_cache != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: destination cache already set.",
		 function );

		return( -1 );
	}
	if( source_cache == NULL )
	{
		*destination_cache = NULL;

		return( 1 );
	}
	internal_source_cache = (libfcache_internal_cache_t *) source_cache;

	if( libcdata_array_get_number_of_entries(
	     internal_source_cache->entries,
	     &number_of_cache_entries,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve number of cache entries from source entries array.",
		 function );

		return( -1 );
	}
	if( libfcache_cache_initialize(
	     destination_cache,
	     number_of_cache_entries,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create destination cache.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Resizes the cache
 * Returns 1 if successful or -1 on error
 */
int libfcache_cache_resize(
     libfcache_cache_t *cache,
     int maximum_cache_entries,
     libcerror_error_t **error )
{
	libfcache_internal_cache_t *internal_cache = NULL;
	static char *function                      = "libfcache_cache_resize";

	if( cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid cache.",
		 function );

		return( -1 );
	}
	internal_cache = (libfcache_internal_cache_t *) cache;

	if( libcdata_array_resize(
	     internal_cache->entries,
	     maximum_cache_entries,
	     (int (*)(intptr_t **, libcerror_error_t **)) &libfcache_cache_value_free,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_RESIZE_FAILED,
		 "%s: unable to resize entries array.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the number of entries of the cache
 * Returns 1 if successful or -1 on error
 */
int libfcache_cache_get_number_of_entries(
     libfcache_cache_t *cache,
     int *number_of_entries,
     libcerror_error_t **error )
{
	libfcache_internal_cache_t *internal_cache = NULL;
	static char *function                      = "libfcache_cache_get_number_of_entries";

	if( cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid cache.",
		 function );

		return( -1 );
	}
	internal_cache = (libfcache_internal_cache_t *) cache;

	if( libcdata_array_get_number_of_entries(
	     internal_cache->entries,
	     number_of_entries,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve number of entries from entries array.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the number of cache values
 * Returns 1 if successful or -1 on error
 */
int libfcache_cache_get_number_of_cache_values(
     libfcache_cache_t *cache,
     int *number_of_cache_values,
     libcerror_error_t **error )
{
	libfcache_internal_cache_t *internal_cache = NULL;
	static char *function                      = "libfcache_cache_get_number_of_cache_values";

	if( cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid cache.",
		 function );

		return( -1 );
	}
	internal_cache = (libfcache_internal_cache_t *) cache;

	if( number_of_cache_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid number of cache values.",
		 function );

		return( -1 );
	}
	*number_of_cache_values = internal_cache->number_of_cache_values;

	return( 1 );
}

/* Retrieves the cache value that matches the file index, offset and timestamp
 * Returns 1 if successful, 0 if no such value or -1 on error
 */
int libfcache_cache_get_value_by_identifier(
     libfcache_cache_t *cache,
     int file_index,
     off64_t offset,
     int64_t timestamp,
     libfcache_cache_value_t **cache_value,
     libcerror_error_t **error )
{
	libfcache_cache_value_t *previous_cache_value = NULL;
	libfcache_cache_value_t *safe_cache_value     = NULL;
	libfcache_internal_cache_t *internal_cache    = NULL;
	static char *function                         = "libfcache_cache_get_value_by_identifier";
	off64_t cache_value_offset                    = 0;
	int64_t cache_value_timestamp                 = 0;
	int cache_entry_index                         = 0;
	int cache_value_file_index                    = 0;

	if( cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid cache.",
		 function );

		return( -1 );
	}
	internal_cache = (libfcache_internal_cache_t *) cache;

	if( cache_value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid cache value.",
		 function );

		return( -1 );
	}
	for( cache_entry_index = 0;
	     cache_entry_index < internal_cache->number_of_cache_values;
	     cache_entry_index++ )
	{
		if( libcdata_array_get_entry_by_index(
		     internal_cache->entries,
		     cache_entry_index,
		     (intptr_t **) &safe_cache_value,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve cache value: %d from entries array.",
			 function,
			 cache_entry_index );

			return( -1 );
		}
		if( libfcache_cache_value_get_identifier(
		     safe_cache_value,
		     &cache_value_file_index,
		     &cache_value_offset,
		     &cache_value_timestamp,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve cache value: %d from entries array.",
			 function,
			 cache_entry_index );

			return( -1 );
		}
		if( ( cache_value_file_index == file_index )
		 && ( cache_value_offset == offset )
		 && ( cache_value_timestamp == timestamp ) )
		{
			if( cache_entry_index > 0 )
			{
/* TODO track usage */
				if( libcdata_array_set_entry_by_index(
				     internal_cache->entries,
				     cache_entry_index - 1,
				     (intptr_t *) safe_cache_value,
				     error ) != 1 )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
					 "%s: unable to set cache value: %d in entries array.",
					 function,
					 cache_entry_index - 1 );

					return( -1 );
				}
				if( libcdata_array_set_entry_by_index(
				     internal_cache->entries,
				     cache_entry_index,
				     (intptr_t *) previous_cache_value,
				     error ) != 1 )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
					 "%s: unable to set cache value: %d in entries array.",
					 function,
					 cache_entry_index - 1 );

					return( -1 );
				}
			}
			*cache_value = safe_cache_value;

			return( 1 );
		}
		previous_cache_value = safe_cache_value;
	}
	return( 0 );
}

/* Retrieves the cache value for the specific index
 * Returns 1 if successful or -1 on error
 */
int libfcache_cache_get_value_by_index(
     libfcache_cache_t *cache,
     int cache_entry_index,
     libfcache_cache_value_t **cache_value,
     libcerror_error_t **error )
{
	libfcache_internal_cache_t *internal_cache = NULL;
	static char *function                      = "libfcache_cache_get_value_by_index";

	if( cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid cache.",
		 function );

		return( -1 );
	}
	internal_cache = (libfcache_internal_cache_t *) cache;

	if( libcdata_array_get_entry_by_index(
	     internal_cache->entries,
	     cache_entry_index,
	     (intptr_t **) cache_value,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve cache value: %d from entries array.",
		 function,
		 cache_entry_index );

		return( -1 );
	}
	return( 1 );
}

/* Sets the cache value for the file index, offset and timestamp
 * Returns 1 if successful or -1 on error
 */
int libfcache_cache_set_value_by_identifier(
     libfcache_cache_t *cache,
     int file_index,
     off64_t offset,
     int64_t timestamp,
     intptr_t *value,
     int (*value_free_function)(
            intptr_t **value,
            libcerror_error_t **error ),
     uint8_t flags,
     libcerror_error_t **error )
{
	libfcache_cache_value_t *cache_value       = NULL;
	libfcache_internal_cache_t *internal_cache = NULL;
	static char *function                      = "libfcache_cache_set_value_by_identifier";
	int number_of_cache_entries                = 0;

	if( cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid cache.",
		 function );

		return( -1 );
	}
	internal_cache = (libfcache_internal_cache_t *) cache;

	if( libcdata_array_get_number_of_entries(
	     internal_cache->entries,
	     &number_of_cache_entries,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve number of cache entries from entries array.",
		 function );

		return( -1 );
	}
	if( internal_cache->number_of_cache_values < number_of_cache_entries )
	{
		if( libfcache_cache_value_initialize(
		     &cache_value,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
			 "%s: unable to create cache value.",
			 function );

			return( -1 );
		}
		if( libcdata_array_set_entry_by_index(
		     internal_cache->entries,
		     internal_cache->number_of_cache_values,
		     (intptr_t *) cache_value,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
			 "%s: unable to set cache value: %d in entries array.",
			 function,
			 internal_cache->number_of_cache_values );

			libfcache_cache_value_free(
			 &cache_value,
			 NULL );

			return( -1 );
		}
		internal_cache->number_of_cache_values++;
	}
	else
	{
		if( libcdata_array_get_entry_by_index(
		     internal_cache->entries,
		     number_of_cache_entries - 1,
		     (intptr_t **) &cache_value,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve cache value: %d from entries array.",
			 function,
			 number_of_cache_entries - 1 );

			return( -1 );
		}
	}
	if( libfcache_cache_value_set_value(
	     cache_value,
	     value,
	     value_free_function,
	     flags,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set value in cache value.",
		 function );

		return( -1 );
	}
	if( libfcache_cache_value_set_identifier(
	     cache_value,
	     file_index,
	     offset,
	     timestamp,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set identifier in cache value.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Sets the cache value for the specific index
 * Returns 1 if successful or -1 on error
 */
int libfcache_cache_set_value_by_index(
     libfcache_cache_t *cache,
     int cache_entry_index,
     int file_index,
     off64_t offset,
     int64_t timestamp,
     intptr_t *value,
     int (*value_free_function)(
            intptr_t **value,
            libcerror_error_t **error ),
     uint8_t flags,
     libcerror_error_t **error )
{
	libfcache_cache_value_t *cache_value       = NULL;
	libfcache_internal_cache_t *internal_cache = NULL;
	static char *function                      = "libfcache_cache_set_value_by_index";

	if( cache == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid cache.",
		 function );

		return( -1 );
	}
	internal_cache = (libfcache_internal_cache_t *) cache;

	if( libcdata_array_get_entry_by_index(
	     internal_cache->entries,
	     cache_entry_index,
	     (intptr_t **) &cache_value,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve cache value: %d from entries array.",
		 function,
		 cache_entry_index );

		return( -1 );
	}
	if( cache_value == NULL )
	{
		if( libfcache_cache_value_initialize(
		     &cache_value,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
			 "%s: unable to create cache value.",
			 function );

			return( -1 );
		}
		if( libcdata_array_set_entry_by_index(
		     internal_cache->entries,
		     cache_entry_index,
		     (intptr_t *) cache_value,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
			 "%s: unable to set cache value: %d in entries array.",
			 function,
			 cache_entry_index );

			libfcache_cache_value_free(
			 &cache_value,
			 NULL );

			return( -1 );
		}
		internal_cache->number_of_cache_values++;
	}
	if( libfcache_cache_value_set_value(
	     cache_value,
	     value,
	     value_free_function,
	     flags,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set value in cache value.",
		 function );

		return( -1 );
	}
	if( libfcache_cache_value_set_identifier(
	     cache_value,
	     file_index,
	     offset,
	     timestamp,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set identifier in cache value.",
		 function );

		return( -1 );
	}
	return( 1 );
}

