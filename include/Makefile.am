include_HEADERS = \
	libfcache.h

pkginclude_HEADERS = \
	libfcache/definitions.h \
	libfcache/error.h \
	libfcache/extern.h \
	libfcache/features.h \
	libfcache/types.h

EXTRA_DIST = \
	libfcache.h.in \
	libfcache/definitions.h.in \
	libfcache/features.h.in \
	libfcache/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f libfcache.h
	-rm -f libfcache/definitions.h
	-rm -f libfcache/features.h
	-rm -f libfcache/types.h
	-rm -f Makefile

