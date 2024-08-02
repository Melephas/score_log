#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# Required version of autoconf
AC_PREREQ([2.71])

# Initialise all the programs needed
AC_INIT([score_log], [0.3.0], [contact.melephas@gmail.com])
# 'foreign' is for project layout compatibility, 'no-dist-gzip dist-xz' produces a .tar.xz dist instead of .tar.gz
AM_INIT_AUTOMAKE([foreign subdir-objects no-dist-gzip dist-xz])
LT_INIT

# Tell autoconf where the source is
AC_CONFIG_SRCDIR([src/log.c])
# Automatically generate config.h to include details about the package and authors
AC_CONFIG_HEADERS([src/config.h])
# For extra macros the project might need
AC_CONFIG_MACRO_DIR([m4])

# Use C not C++
AC_LANG([C])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_AWK
# Need to have per product flags myexecutable_CFLAG
AC_PROG_CC_C_O


# Checks for libraries.


# Checks for header files.
# ./configure --disable-assert to define NDEBUG
AC_HEADER_ASSERT

AC_CHECK_HEADER([stdbool.h])
AC_CHECK_HEADER([stdarg.h])
AC_CHECK_HEADER([stdio.h])

# Check for unit testing library (criterion)
PKG_CHECK_MODULES([CRITERION], [criterion], [], [
    AC_MSG_ERROR([unable to find Criterion])
])

AC_SUBST([CRITERION_CFLAGS])
AC_SUBST([CRITERION_LIBS])

# Which files to generate and where to generate them
AC_CONFIG_FILES([Makefile
                 interface/Makefile])
AC_REQUIRE_AUX_FILE([tap-driver.sh])
AC_OUTPUT
