# use the TAP log driver
TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
            $(top_srcdir)/build-aux/tap-driver.sh

# Setup Criterion TAP output using ENV
AM_TESTS_ENVIRONMENT = \
CRITERION_OUTPUTS='tap:-'; \
export CRITERION_OUTPUTS;

# Useful flags for the build system
ACLOCAL_AMFLAGS = -I m4
SUBDIRS = interface

# Library build specifications
lib_LTLIBRARIES = libscore_log.la
libscore_log_la_SOURCES = src/log.c interface/score/log.h
libscore_log_la_CFLAGS = -I./interface
libscore_log_la_LDFLAGS = -shared -fPIC -export-symbols-regex '^score_' -I./interface


# Set up unit testing
check_PROGRAMS = tests
tests_SOURCES = test/tests.c interface/score/log.h
tests_CFLAGS = -I./interface -I../interface $(CRITERION_CFLAGS)
tests_LDFLAGS = $(CRITERION_LIBS)
tests_LDADD = libscore_log.la

TESTS = tests
