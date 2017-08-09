/*
 * Library cache_value type test program
 *
 * Copyright (C) 2010-2017, Joachim Metz <joachim.metz@gmail.com>
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

	FCACHE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FCACHE_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	cache_value = NULL;

#if defined( HAVE_FCACHE_TEST_MEMORY )

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

#endif /* #if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT ) */

/* Tests the libfcache_cache_value_free function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_value_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

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
	return( 0 );
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
	intptr_t value                       = 0;
	int result                           = 0;
	int value_is_set                     = 0;

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
	          (intptr_t **) &value,
	          &error );

	FCACHE_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FCACHE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value_is_set = result;

	/* Test error cases
	 */
	result = libfcache_cache_value_get_value(
	          NULL,
	          (intptr_t **) &value,
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

	if( value_is_set != 0 )
	{
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
	}
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

#endif /* #if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT ) */

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

#endif /* #if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT ) */

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_free",
	 fcache_test_cache_value_free );

#if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT )

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_clear",
	 fcache_test_cache_value_clear );

	/* TODO: add tests for libfcache_cache_value_get_identifier */

	/* TODO: add tests for libfcache_cache_value_set_identifier */

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_get_value",
	 fcache_test_cache_value_get_value );

	/* TODO: add tests for libfcache_cache_value_set_value */

#endif /* #if defined( __GNUC__ ) && !defined( LIBFCACHE_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

