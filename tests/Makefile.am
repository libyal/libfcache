AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBFCACHE_DLL_IMPORT@

BUILT_SOURCES = package.m4

check_AUTOTESTS = \
	test_library \
	test_manpages

check_PROGRAMS = \
	fcache_test_cache \
	fcache_test_cache_value \
	fcache_test_date_time \
	fcache_test_error \
	fcache_test_support

fcache_test_cache_SOURCES = \
	fcache_test_cache.c \
	fcache_test_libcerror.h \
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
	fcache_test_libcerror.h \
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

AUTOM4TE = autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest

SUFFIXES = .at

.at:
	$(AM_V_GEN)rm -f $@ $@.tmp; \
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $< && \
	mv $@.tmp $@

atconfig: $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status tests/$@

check-build: $(check_PROGRAMS)

check-local: $(check_AUTOTESTS)
	@fail=0; \
	for test_suite in $(check_AUTOTESTS); do \
		$(AM_TESTS_ENVIRONMENT) $(SHELL) "./$$test_suite" $(TESTSUITEFLAGS) || fail=1; \
		echo ""; \
	done; \
	exit $$fail

clean-local:
	for test_suite in $(check_AUTOTESTS); do \
		test ! -f "$$test_suite" || $(SHELL) "./$$test_suite" --clean; \
	done

package.m4: $(top_srcdir)/configure.ac
	$(AM_V_GEN):; \
	{ \
	  echo 'm4_define([AT_PACKAGE_NAME], [$(PACKAGE_NAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_TARNAME], [$(PACKAGE_TARNAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_VERSION], [$(PACKAGE_VERSION)])' ; \
	  echo 'm4_define([AT_PACKAGE_STRING], [$(PACKAGE_STRING)])' ; \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [$(PACKAGE_BUGREPORT)])' ; \
	} > $@

test_library: package.m4 test_library.at test_macros.at

EXTRA_DIST = \
	$(check_AUTOTESTS:=.at) \
	package.m4 \
	test_macros.at

CLEANFILES = \
	$(check_AUTOTESTS) \
	*.exe \
	*.tmp

DISTCLEANFILES = \
	*.log \
	atconfig \
	Makefile \
	Makefile.in

