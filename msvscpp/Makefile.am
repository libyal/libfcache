MSVSCPP_FILES = \
	fcache_test_cache/fcache_test_cache.vcproj \
	fcache_test_cache_value/fcache_test_cache_value.vcproj \
	fcache_test_error/fcache_test_error.vcproj \
	fcache_test_get_version/fcache_test_get_version.vcproj \
	libcdata/libcdata.vcproj \
	libcerror/libcerror.vcproj \
	libcstring/libcstring.vcproj \
	libcthreads/libcthreads.vcproj \
	libfcache/libfcache.vcproj \
	libfcache.sln

SCRIPT_FILES = \
	scripts/vs2008_x64.sh \
	scripts/vs2008_x64_sln.sed \
	scripts/vs2008_x64_vcproj.sed \
	scripts/vs2010_x64.sh \
	scripts/vs2010_x64_sln.sed \
	scripts/vs2010_x64_vcxproj.sed

EXTRA_DIST = \
	$(MSVSCPP_FILES) \
	$(SCRIPT_FILES)

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

