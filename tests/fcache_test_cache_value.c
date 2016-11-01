/*
 * Library cache value type testing program
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

#if defined( __GNUC__ )

extern int libfcache_cache_value_initialize(
            libfcache_cache_value_t **cache_value,
            libcerror_error_t **error );

extern int libfcache_cache_value_free(
            libfcache_cache_value_t **cache_value,
            libcerror_error_t **error );

#endif /* defined( __GNUC__ ) */

#if defined( __GNUC__ )

/* Tests the libfcache_cache_value_initialize function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_cache_value_initialize(
     void )
{
	libfcache_cache_value_t *cache_value = NULL;
	libcerror_error_t *error             = NULL;
	int result                           = 0;

	/* Test libfcache_cache_value_initialize without entries
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

	/* Test libfcache_cache_value_initialize with malloc failing
	 */
	fcache_test_malloc_attempts_before_fail = 0;

	result = libfcache_cache_value_initialize(
	          &cache_value,
	          &error );

	if( fcache_test_malloc_attempts_before_fail != -1 )
	{
		fcache_test_malloc_attempts_before_fail = -1;
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
	/* Test libfcache_cache_value_initialize with memset failing
	 */
	fcache_test_memset_attempts_before_fail = 0;

	result = libfcache_cache_value_initialize(
	          &cache_value,
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

		FCACHE_TEST_ASSERT_IS_NULL(
		 "cache_value",
		 cache_value );

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
	if( cache_value != NULL )
	{
		libfcache_cache_value_free(
		 &cache_value,
		 NULL );
	}
	return( 0 );
}

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

#endif /* defined( __GNUC__ ) */

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

#if defined( __GNUC__ )

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_initialize",
	 fcache_test_cache_value_initialize );

	FCACHE_TEST_RUN(
	 "libfcache_cache_value_free",
	 fcache_test_cache_value_free );

#endif /* defined( __GNUC__ ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

