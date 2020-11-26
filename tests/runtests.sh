#!/bin/sh
# Script to run tests
#
# Version: 20201121

if test -f ${PWD}/libfcache/.libs/libfcache.1.dylib && test -f ./pyfcache/.libs/pyfcache.so;
then
	install_name_tool -change /usr/local/lib/libfcache.1.dylib ${PWD}/libfcache/.libs/libfcache.1.dylib ./pyfcache/.libs/pyfcache.so;
fi

make check CHECK_WITH_STDERR=1;
RESULT=$?;

if test ${RESULT} -ne 0 && test -f tests/test-suite.log;
then
	cat tests/test-suite.log;
fi
exit ${RESULT};

