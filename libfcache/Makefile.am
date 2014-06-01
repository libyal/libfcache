AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@

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
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	@LIBCTHREADS_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	@PTHREAD_LIBADD@

libfcache_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libfcache_definitions.h.in \
	libfcache.rc \
	libfcache.rc.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libfcache_definitions.h
	/bin/rm -f libfcache.rc
	/bin/rm -f Makefile

splint:
	@echo "Running splint on libfcache ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libfcache_la_SOURCES)

