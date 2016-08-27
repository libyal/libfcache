/*
 * Library cache type testing program
 *
 * Copyright (C) 2010-2016, Joachim Metz <joachim.metz@gmail.com>
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

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fcache_test_libfcache.h"
#include "fcache_test_libcerror.h"
#include "fcache_test_libcstring.h"
#include "fcache_test_macros.h"
#include "fcache_test_memory.h"
#include "fcache_test_unused.h"

/* Tests the libfcache_cache_initialize function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_initialize(
     void )
{
	libfcache_cache_t *cache = NULL;
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test libfcache_cache_initialize without entries
	 */
	result = libfcache_cache_initialize(
	          &cache,
	          16,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 1 );

        FCACHE_TEST_ASSERT_IS_NOT_NULL(
         "cache",
         cache );

        FCACHE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfcache_cache_free(
	          &cache,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 1 );

        FCACHE_TEST_ASSERT_IS_NULL(
         "cache",
         cache );

        FCACHE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfcache_cache_initialize(
	          NULL,
	          16,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FCACHE_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	cache = (libfcache_cache_t *) 0x12345678UL;

	result = libfcache_cache_initialize(
	          &cache,
	          16,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FCACHE_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	cache = NULL;

#if defined( HAVE_FCACHE_TEST_MEMORY )

	/* Test libfcache_cache_initialize with malloc failing
	 */
	fcache_test_malloc_attempts_before_fail = 0;

	result = libfcache_cache_initialize(
	          &cache,
	          16,
	          &error );

	if( fcache_test_malloc_attempts_before_fail != -1 )
	{
		fcache_test_malloc_attempts_before_fail = -1;
	}
	else
	{
		FCACHE_TEST_ASSERT_EQUAL(
		 "result",
		 result,
		 -1 );

		FCACHE_TEST_ASSERT_IS_NULL(
		 "cache",
		 cache );

		FCACHE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfcache_cache_initialize with memset failing
	 */
	fcache_test_memset_attempts_before_fail = 0;

	result = libfcache_cache_initialize(
	          &cache,
	          16,
	          &error );

	if( fcache_test_memset_attempts_before_fail != -1 )
	{
		fcache_test_memset_attempts_before_fail = -1;
	}
	else
	{
		FCACHE_TEST_ASSERT_EQUAL(
		 "result",
		 result,
		 -1 );

		FCACHE_TEST_ASSERT_IS_NULL(
		 "cache",
		 cache );

		FCACHE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FCACHE_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( cache != NULL )
	{
		libfcache_cache_free(
		 &cache,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfcache_cache_free function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfcache_cache_free(
	          NULL,
	          &error );

	FCACHE_TEST_ASSERT_EQUAL(
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

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
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

	FCACHE_TEST_RUN(
	 "libfcache_cache_initialize",
	 fcache_test_cache_initialize() )

	FCACHE_TEST_RUN(
	 "libfcache_cache_free",
	 fcache_test_cache_free() )

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
