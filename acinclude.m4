dnl Checks for required headers and functions
dnl
dnl Version: 20230115

dnl Function to detect if libfcache dependencies are available
AC_DEFUN([AX_LIBFCACHE_CHECK_LOCAL],
  [dnl Types used in libfcache/libfcache_date_time.h
  AC_STRUCT_TM

  dnl Headers included in libfcache/libfcache_date_time.h
  AC_CHECK_HEADERS([sys/time.h])

  dnl Date and time functions used in libfcache/libfcache_date_time.h
  AC_CHECK_FUNCS([clock_gettime time])

  AS_IF(
    [test "x$ac_cv_func_time" != xyes],
    [AC_MSG_FAILURE(
      [Missing function: time],
      [1])
    ])
  ])

dnl Function to check if DLL support is needed
AC_DEFUN([AX_LIBFCACHE_CHECK_DLL_SUPPORT],
  [AS_IF(
    [test "x$enable_shared" = xyes],
    [AS_CASE(
      [$host],
      [*cygwin* | *mingw* | *msys*],
      [AC_DEFINE(
        [HAVE_DLLMAIN],
        [1],
        [Define to 1 to enable the DllMain function.])
      AC_SUBST(
        [HAVE_DLLMAIN],
        [1])

      AC_SUBST(
        [LIBFCACHE_DLL_EXPORT],
        ["-DLIBFCACHE_DLL_EXPORT"])

      AC_SUBST(
        [LIBFCACHE_DLL_IMPORT],
        ["-DLIBFCACHE_DLL_IMPORT"])
      ])
    ])
  ])

