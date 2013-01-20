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
	/bin/rm -f libfcache.h
	/bin/rm -f libfcache/definitions.h
	/bin/rm -f libfcache/features.h
	/bin/rm -f libfcache/types.h
	/bin/rm -f Makefile

