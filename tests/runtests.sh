#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libfcache/.libs/libfcache.1.dylib && test -f ./pyfcache/.libs/pyfcache.so
then
	install_name_tool -change /usr/local/lib/libfcache.1.dylib ${PWD}/libfcache/.libs/libfcache.1.dylib ./pyfcache/.libs/pyfcache.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

