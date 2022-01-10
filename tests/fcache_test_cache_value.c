/*
 * Library cache_value type test program
 *
 * Copyright (C) 2010-2022, Joachim Metz <joachim.metz@gmail.com>
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

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fcache_test_libcerror.h"
#include "fcache_test_libfcache.h"
#include "fcache_test_macros.h"
#include "fcache_test_memory.h"
#include "fcache_test_unused.h"

#include "../libfcache/libfcache_cache_value.h"

int fcache_test_cache_value_free_function_return_value = 1;

/* Test value free function
 * Returns 1 if successful or -1 on error
 */
int fcache_test_cache_value_free_function(
     intptr_t **value FCACHE_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error FCACHE_TEST_ATTRIBUTE_UNUSED )
{
	FCACHE_TEST_UNREFERENCED_PARAMETER( value )
	FCACHE_TEST_UNREFERENCED_PARAMETER( error )

	return( fcache_test_cache_value_free_function_return_value );
}

#if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT )

/* Tests the libfcache_cache_value_initialize function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_value_initialize(
     void )
{
	libcerror_error_t *error             = NULL;
	libfcache_cache_value_t *cache_value = NULL;
	int result                           = 0;

#if defined( HAVE_FCACHE_TEST_MEMORY )
	int number_of_malloc_fail_tests      = 1;
	int number_of_memset_fail_tests      = 1;
	int test_number                      = 0;
#endif

	/* Test regular cases
	 */
	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfcache_cache_value_free(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfcache_cache_value_initialize(
	          NULL,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	cache_value = (libfcache_cache_value_t *) 0x12345678UL;

	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	cache_value = NULL;

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_FCACHE_TEST_MEMORY )

	/* 1 fail in memory_allocate_structure
	 */
	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfcache_cache_value_initialize with malloc failing
		 */
		fcache_test_malloc_attempts_before_fail = test_number;

		result = libfcache_cache_value_initialize(
		          &cache_value,
		          &error );

		if( fcache_test_malloc_attempts_before_fail != -1 )
		{
			fcache_test_malloc_attempts_before_fail = -1;

			if( cache_value != NULL )
			{
				libfcache_cache_value_free(
				 &cache_value,
				 NULL );
			}
		}
		else
		{
			FCACHE_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FCACHE_TEST_ASSERT_IS_NULL(
			 "cache_value",
			 cache_value );

			FCACHE_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	/* 1 fail in memset after memory_allocate_structure
	 */
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfcache_cache_value_initialize with memset failing
		 */
		fcache_test_memset_attempts_before_fail = test_number;

		result = libfcache_cache_value_initialize(
		          &cache_value,
		          &error );

		if( fcache_test_memset_attempts_before_fail != -1 )
		{
			fcache_test_memset_attempts_before_fail = -1;

			if( cache_value != NULL )
			{
				libfcache_cache_value_free(
				 &cache_value,
				 NULL );
			}
		}
		else
		{
			FCACHE_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FCACHE_TEST_ASSERT_IS_NULL(
			 "cache_value",
			 cache_value );

			FCACHE_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_FCACHE_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( cache_value != NULL )
	{
		libfcache_cache_value_free(
		 &cache_value,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT ) */

/* Tests the libfcache_cache_value_free function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_value_free(
     void )
{
#if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT )
	uint8_t value_data[ 16 ];

	libfcache_cache_value_t *cache_value = NULL;
#endif

	libcerror_error_t *error             = NULL;
	int result                           = 0;

#if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT )

	/* Initialize test
	 */
	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfcache_cache_value_set_value(
	          cache_value,
	          (intptr_t *) value_data,
	          &fcache_test_cache_value_free_function,
	          LIBFCACHE_CACHE_VALUE_FLAG_MANAGED,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	( (libfcache_internal_cache_value_t *) cache_value )->value_free_function = NULL;

	result = libfcache_cache_value_free(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Initialize test
	 */
	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfcache_cache_value_set_value(
	          cache_value,
	          (intptr_t *) value_data,
	          &fcache_test_cache_value_free_function,
	          LIBFCACHE_CACHE_VALUE_FLAG_MANAGED,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	fcache_test_cache_value_free_function_return_value = -1;

	result = libfcache_cache_value_free(
	          &cache_value,
	          &error );

	fcache_test_cache_value_free_function_return_value = 1;

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#endif /* defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT ) */

	/* Test error cases
	 */
	result = libfcache_cache_value_free(
	          NULL,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
#if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT )
	if( cache_value != NULL )
	{
		libfcache_cache_value_free(
		 &cache_value,
		 NULL );
	}
#endif
	return( -1 );
}

#if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT )

/* Tests the libfcache_cache_value_clear function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_value_clear(
     void )
{
	libcerror_error_t *error             = NULL;
	libfcache_cache_value_t *cache_value = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfcache_cache_value_clear(
	          cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfcache_cache_value_clear(
	          NULL,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_FCACHE_TEST_MEMORY )

	/* Test libfcache_cache_value_clear with memset failing
	 */
	fcache_test_memset_attempts_before_fail = 0;

	result = libfcache_cache_value_clear(
	          cache_value,
	          &error );

	if( fcache_test_memset_attempts_before_fail != -1 )
	{
		fcache_test_memset_attempts_before_fail = -1;
	}
	else
	{
		FCACHE_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FCACHE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FCACHE_TEST_MEMORY ) */

	/* Clean up
	 */
	result = libfcache_cache_value_free(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( cache_value != NULL )
	{
		libfcache_cache_value_free(
		 &cache_value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfcache_cache_value_get_identifier function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_value_get_identifier(
     void )
{
	libcerror_error_t *error             = NULL;
	libfcache_cache_value_t *cache_value = NULL;
	off64_t offset                       = 0;
	int64_t timestamp                    = 0;
	int file_index                       = 0;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfcache_cache_value_get_identifier(
	          cache_value,
	          &file_index,
	          &offset,
	          &timestamp,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfcache_cache_value_get_identifier(
	          NULL,
	          &file_index,
	          &offset,
	          &timestamp,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfcache_cache_value_get_identifier(
	          cache_value,
	          NULL,
	          &offset,
	          &timestamp,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfcache_cache_value_get_identifier(
	          cache_value,
	          &file_index,
	          NULL,
	          &timestamp,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfcache_cache_value_get_identifier(
	          cache_value,
	          &file_index,
	          &offset,
	          NULL,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfcache_cache_value_free(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( cache_value != NULL )
	{
		libfcache_cache_value_free(
		 &cache_value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfcache_cache_value_get_cache_index function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_value_get_cache_index(
     void )
{
	libcerror_error_t *error             = NULL;
	libfcache_cache_value_t *cache_value = NULL;
	int cache_index                      = 0;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfcache_cache_value_get_cache_index(
	          cache_value,
	          &cache_index,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfcache_cache_value_get_cache_index(
	          NULL,
	          &cache_index,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfcache_cache_value_get_cache_index(
	          cache_value,
	          NULL,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfcache_cache_value_free(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( cache_value != NULL )
	{
		libfcache_cache_value_free(
		 &cache_value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfcache_cache_value_set_identifier function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_value_set_identifier(
     void )
{
	libcerror_error_t *error             = NULL;
	libfcache_cache_value_t *cache_value = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfcache_cache_value_set_identifier(
	          cache_value,
	          0,
	          0,
	          0,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfcache_cache_value_set_identifier(
	          NULL,
	          0,
	          0,
	          0,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfcache_cache_value_free(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( cache_value != NULL )
	{
		libfcache_cache_value_free(
		 &cache_value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfcache_cache_value_set_cache_index function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_value_set_cache_index(
     void )
{
	libcerror_error_t *error             = NULL;
	libfcache_cache_value_t *cache_value = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfcache_cache_value_set_cache_index(
	          cache_value,
	          0,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfcache_cache_value_set_cache_index(
	          NULL,
	          0,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfcache_cache_value_free(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( cache_value != NULL )
	{
		libfcache_cache_value_free(
		 &cache_value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfcache_cache_value_get_value function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_value_get_value(
     void )
{
	libcerror_error_t *error             = NULL;
	libfcache_cache_value_t *cache_value = NULL;
	intptr_t *value                      = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfcache_cache_value_get_value(
	          cache_value,
	          &value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfcache_cache_value_get_value(
	          NULL,
	          &value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfcache_cache_value_get_value(
	          cache_value,
	          NULL,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfcache_cache_value_free(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( cache_value != NULL )
	{
		libfcache_cache_value_free(
		 &cache_value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfcache_cache_value_set_value function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_value_set_value(
     void )
{
	uint8_t value_data[ 16 ];

	int (*value_free_function)(intptr_t **, libcerror_error_t **) = NULL;
	libcerror_error_t *error                                      = NULL;
	libfcache_cache_value_t *cache_value                          = NULL;
	int result                                                    = 0;

	/* Initialize test
	 */
	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfcache_cache_value_set_value(
	          cache_value,
	          (intptr_t *) value_data,
	          &fcache_test_cache_value_free_function,
	          LIBFCACHE_CACHE_VALUE_FLAG_MANAGED,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfcache_cache_value_set_value(
	          cache_value,
	          (intptr_t *) value_data,
	          &fcache_test_cache_value_free_function,
	          LIBFCACHE_CACHE_VALUE_FLAG_MANAGED,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfcache_cache_value_set_value(
	          NULL,
	          (intptr_t *) value_data,
	          &fcache_test_cache_value_free_function,
	          LIBFCACHE_CACHE_VALUE_FLAG_MANAGED,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	value_free_function = ( (libfcache_internal_cache_value_t *) cache_value )->value_free_function;

	( (libfcache_internal_cache_value_t *) cache_value )->value_free_function = NULL;

	result = libfcache_cache_value_set_value(
	          cache_value,
	          (intptr_t *) value_data,
	          &fcache_test_cache_value_free_function,
	          LIBFCACHE_CACHE_VALUE_FLAG_MANAGED,
	          &error );

	( (libfcache_internal_cache_value_t *) cache_value )->value_free_function = value_free_function;

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	fcache_test_cache_value_free_function_return_value = -1;

	result = libfcache_cache_value_set_value(
	          cache_value,
	          (intptr_t *) value_data,
	          &fcache_test_cache_value_free_function,
	          LIBFCACHE_CACHE_VALUE_FLAG_MANAGED,
	          &error );

	fcache_test_cache_value_free_function_return_value = 1;

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfcache_cache_value_set_value(
	          cache_value,
	          (intptr_t *) value_data,
	          NULL,
	          LIBFCACHE_CACHE_VALUE_FLAG_MANAGED,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfcache_cache_value_free(
	          &cache_value,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "cache_value",
	 cache_value );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( cache_value != NULL )
	{
		libfcache_cache_value_free(
		 &cache_value,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FCACHE_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FCACHE_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FCACHE_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FCACHE_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FCACHE_TEST_UNREFERENCED_PARAMETER( argc )
	FCACHE_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT )

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_initialize",
	 fcache_test_cache_value_initialize );

#endif /* defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT ) */

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_free",
	 fcache_test_cache_value_free );

#if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT )

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_clear",
	 fcache_test_cache_value_clear );

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_get_identifier",
	 fcache_test_cache_value_get_identifier );

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_get_cache_index",
	 fcache_test_cache_value_get_cache_index );

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_set_identifier",
	 fcache_test_cache_value_set_identifier );

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_set_cache_index",
	 fcache_test_cache_value_set_cache_index );

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_get_value",
	 fcache_test_cache_value_get_value );

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_set_value",
	 fcache_test_cache_value_set_value );

#endif /* defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

