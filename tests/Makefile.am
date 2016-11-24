AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBFCACHE_DLL_IMPORT@

TESTS = \
	test_api_functions.sh \
	test_api_types.sh

check_SCRIPTS = \
	test_api_functions.sh \
	test_api_types.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fcache_test_cache \
	fcache_test_cache_value \
	fcache_test_date_time \
	fcache_test_error \
	fcache_test_support

fcache_test_cache_SOURCES = \
	fcache_test_cache.c \
	fcache_test_libfcache.h \
	fcache_test_macros.h \
	fcache_test_memory.c fcache_test_memory.h \
	fcache_test_unused.h

fcache_test_cache_LDADD = \
	../libfcache/libfcache.la \
	@LIBCERROR_LIBADD@

fcache_test_cache_value_SOURCES = \
	fcache_test_cache_value.c \
	fcache_test_libcerror.h \
	fcache_test_libfcache.h \
	fcache_test_macros.h \
	fcache_test_memory.c fcache_test_memory.h \
	fcache_test_unused.h

fcache_test_cache_value_LDADD = \
	../libfcache/libfcache.la \
	@LIBCERROR_LIBADD@

fcache_test_date_time_SOURCES = \
	fcache_test_date_time.c \
	fcache_test_libfcache.h \
	fcache_test_macros.h \
	fcache_test_unused.h

fcache_test_date_time_LDADD = \
	../libfcache/libfcache.la \
	@LIBCERROR_LIBADD@

fcache_test_error_SOURCES = \
	fcache_test_error.c \
	fcache_test_libfcache.h \
	fcache_test_macros.h \
	fcache_test_unused.h

fcache_test_error_LDADD = \
	../libfcache/libfcache.la

fcache_test_support_SOURCES = \
	fcache_test_libfcache.h \
	fcache_test_macros.h \
	fcache_test_support.c \
	fcache_test_unused.h

fcache_test_support_LDADD = \
	../libfcache/libfcache.la

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

