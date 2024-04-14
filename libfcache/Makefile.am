AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBFCACHE_DLL_EXPORT@

lib_LTLIBRARIES = libfcache.la

libfcache_la_SOURCES = \
	libfcache.c \
	libfcache_cache.c libfcache_cache.h \
	libfcache_cache_value.c libfcache_cache_value.h \
	libfcache_date_time.c libfcache_date_time.h \
	libfcache_definitions.h \
	libfcache_error.c libfcache_error.h \
	libfcache_extern.h \
	libfcache_libcdata.h \
	libfcache_libcerror.h \
	libfcache_support.c libfcache_support.h \
	libfcache_types.h \
	libfcache_unused.h

libfcache_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	@LIBCTHREADS_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	@PTHREAD_LIBADD@

libfcache_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libfcache_definitions.h.in \
	libfcache.rc \
	libfcache.rc.in

DISTCLEANFILES = \
	libfcache_definitions.h \
	libfcache.rc \
	Makefile \
	Makefile.in

sources-local: $(BUILT_SOURCES)

splint-local:
	@echo "Running splint on libfcache ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libfcache_la_SOURCES)

