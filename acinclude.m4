dnl Checks for required headers and functions
dnl
dnl Version: 20181009

dnl Function to detect if libfcache dependencies are available
AC_DEFUN([AX_LIBFCACHE_CHECK_LOCAL],
  [dnl Types used in libfcache/libfcache_date_time.h
  AC_STRUCT_TM

  dnl Headers included in libfcache/libfcache_date_time.h
  AC_HEADER_TIME

  dnl Date and time functions used in libfcache/libfcache_date_time.h
  AC_CHECK_FUNCS([clock_gettime time])

  AS_IF(
    [test "x$ac_cv_func_time" != xyes],
    [AC_MSG_FAILURE(
      [Missing function: time],
      [1])
    ])
  ])

