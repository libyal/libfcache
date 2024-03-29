/*
 * Library date time functions test program
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

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fcache_test_libcerror.h"
#include "fcache_test_libfcache.h"
#include "fcache_test_macros.h"
#include "fcache_test_unused.h"

#if !defined( LIBFCACHE_DLL_IMPORT )

/* Tests the libfcache_date_time_get_timestamp function
 * Returns 1 if successful or 0 if not
 */
int fcache_test_date_time_get_timestamp(
     void )
{
	libcerror_error_t *error = NULL;
	int64_t timestamp        = 0;
	int result               = 0;

	result = libfcache_date_time_get_timestamp(
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
	result = libfcache_date_time_get_timestamp(
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

#endif /* !defined( LIBFCACHE_DLL_IMPORT ) */

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

#if !defined( LIBFCACHE_DLL_IMPORT )

	FCACHE_TEST_RUN(
	 "libfcache_date_time_get_timestamp",
	 fcache_test_date_time_get_timestamp );

#endif /* !defined( LIBFCACHE_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

