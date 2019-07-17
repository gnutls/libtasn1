dnl Process this file with autoconf to produce a configure script.
# Copyright (C) 2002-2014 Free Software Foundation, Inc.
#
# This file is part of LIBTASN1.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

AC_PREREQ([2.63])
AC_INIT([GNU Libtasn1],[4.14],[help-libtasn1@gnu.org])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIRS([m4 m4-gl])
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE([1.10 foreign -Wall -Wno-override])
AM_SILENT_RULES([yes])

# Library code modified:                              REVISION++
# Interfaces changed/added/removed:   CURRENT++       REVISION=0
# Interfaces added:                             AGE++
# Interfaces removed:                           AGE=0
AC_SUBST(LT_CURRENT, 11)
AC_SUBST(LT_REVISION, 6)
AC_SUBST(LT_AGE, 5)

AC_PROG_CC
gl_EARLY
AC_PROG_YACC

AC_ARG_ENABLE(doc,
  AS_HELP_STRING([--disable-doc], [don't generate any documentation]),
    enable_doc=$enableval, enable_doc=yes)
AM_CONDITIONAL(ENABLE_DOC, test "$enable_doc" != "no")

AC_CHECK_FUNCS([clock_gettime])

dnl Checks for programs.
AM_MISSING_PROG(HELP2MAN, help2man, $missing_dir)
AC_LIBTOOL_WIN32_DLL
AM_PROG_AR
AM_PROG_LIBTOOL
GTK_DOC_CHECK(1.2)

AC_CHECK_SIZEOF(unsigned long int, 4)
AC_CHECK_SIZEOF(unsigned int, 4)

sj_UPDATE_HEADER_VERSION([$srcdir/lib/includes/libtasn1.h])

# For gnulib compatibility modules.
gl_INIT

AC_ARG_ENABLE([gcc-warnings],
  [AS_HELP_STRING([--disable-gcc-warnings],
		  [disable GCC warnings (for developers)])],
  [case $enableval in
     yes|no) ;;
     *)      AC_MSG_ERROR([bad value $enableval for gcc-warnings option]) ;;
   esac
   gcc_warnings=$enableval],
  [gcc_warnings=yes]
)

WARN_CFLAGS=""
if test "$gcc_warnings" = yes;then
  WARN_CFLAGS="$WARN_CFLAGS -Wall"
fi
AC_SUBST([WARN_CFLAGS])

AC_CONFIG_FILES([
  Makefile
  doc/Makefile
  doc/cyclo/Makefile
  doc/reference/Makefile
  examples/Makefile
  lib/Makefile
  lib/gl/Makefile
  lib/libtasn1.pc
  src/Makefile
  tests/Makefile
])
AC_OUTPUT

AC_MSG_NOTICE([summary of build options:

  version:          ${VERSION} shared $LT_CURRENT:$LT_REVISION:$LT_AGE
  Host type:        ${host}
  Install prefix:   ${prefix}
  Compiler:         ${CC}
  Warning flags:    errors: ${WERROR_CFLAGS} warnings: ${WARN_CFLAGS}
  Library types:    Shared=${enable_shared}, Static=${enable_static}
  Valgrind:         ${VALGRIND}
  Version script:   $have_ld_version_script
])
