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
AC_INIT([GNU Libtasn1],[4.16.0],[help-libtasn1@gnu.org])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIRS([m4 m4-gl])
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE([1.10 foreign -Wall -Wno-override])
AM_SILENT_RULES([yes])

# Library code modified:                              REVISION++
# Interfaces changed/added/removed:   CURRENT++       REVISION=0
# Interfaces added:                             AGE++
# Interfaces removed:                           AGE=0
AC_SUBST(LT_CURRENT, 12)
AC_SUBST(LT_REVISION, 0)
AC_SUBST(LT_AGE, 6)

# Generate version defines for include file
AC_SUBST([ASN1_VERSION_MAJOR], [`echo $VERSION|cut -d'.' -f1`])
AC_SUBST([ASN1_VERSION_MINOR], [`echo $VERSION|cut -d'.' -f2`])
# Let's activate the following line as soon as we change to extended version numbering
#AC_SUBST([ASN1_VERSION_PATCH], [`echo $VERSION|cut -d'.' -f3`])
AC_SUBST([ASN1_VERSION_PATCH], [`echo 0`])
AC_SUBST([ASN1_VERSION_NUMBER], [`printf '0x%02x%02x%02x' $ASN1_VERSION_MAJOR $ASN1_VERSION_MINOR $ASN1_VERSION_PATCH`])
AC_CONFIG_FILES([lib/includes/libtasn1.h])


AC_PROG_CC
gl_EARLY
AC_PROG_YACC

AC_ARG_ENABLE(doc,
  AS_HELP_STRING([--disable-doc], [don't generate any documentation]),
    enable_doc=$enableval, enable_doc=yes)
AM_CONDITIONAL(ENABLE_DOC, test "$enable_doc" != "no")

AC_CHECK_FUNCS([clock_gettime fmemopen])

dnl Checks for programs.
AM_MISSING_PROG(HELP2MAN, help2man, $missing_dir)
AC_LIBTOOL_WIN32_DLL
AM_PROG_AR
AM_PROG_LIBTOOL
GTK_DOC_CHECK(1.2)

AC_CHECK_SIZEOF(unsigned long int, 4)
AC_CHECK_SIZEOF(unsigned int, 4)

# For gnulib compatibility modules.
gl_INIT

AC_ARG_ENABLE([gcc-warnings],
  [AS_HELP_STRING([--disable-gcc-warnings],
    [disable GCC warnings (for developers)])],
  [case $enableval in
     yes|no) ;;
     *)      AC_MSG_ERROR([bad value $enableval for gcc-warnings option]) ;;
   esac
   gl_gcc_warnings=$enableval],
  [gl_gcc_warnings=yes]
)

if test "$gl_gcc_warnings" = yes; then
  gl_MANYWARN_ALL_GCC([warnings])
  nw=
  nw="$nw -Wsystem-headers"       # Don't let system headers trigger warnings
  nw="$nw -Wc++-compat"           # We don't care strongly about C++ compilers
  nw="$nw -Wundef"                # All compiler preprocessors support #if UNDEF
  nw="$nw -Wtraditional"          # All compilers nowadays support ANSI C
  nw="$nw -Wconversion"           # These warnings usually don't point to mistakes.
  nw="$nw -Wpadded"               # Padding internal structs doesn't help.
  nw="$nw -Wunused-macros"        # Lot's of warnings in ASN1.y
  nw="$nw -Woverlength-strings"   # Modern compilers handle strings > 4096 gracefully
  nw="$nw -Wsuggest-attribute=pure" # Asked for several nodes handling functions

  gl_MANYWARN_COMPLEMENT([warnings], [$warnings], [$nw])
  for w in $warnings; do
    gl_WARN_ADD([$w])
  done

  gl_WARN_ADD([-Wno-type-limits]) # Too many warnings from gnulib macros
  gl_WARN_ADD([-Wformat-truncation=1])
  gl_WARN_ADD([-Wimplicit-fallthrough=2])
  gl_WARN_ADD([-Wno-unused-parameter])
  gl_WARN_ADD([-fdiagnostics-show-option])
  gl_WARN_ADD([-fdiagnostics-color=always])      # colors even when using ccache
fi

AX_CODE_COVERAGE

AC_ARG_ENABLE([fuzzing],
  [AS_HELP_STRING([--enable-fuzzing], [Turn on fuzzing build (for developers)])],
  [enable_fuzzing=yes; AC_SUBST([LIB_FUZZING_ENGINE])], [enable_fuzzing=no; LIB_FUZZING_ENGINE=""])
AM_CONDITIONAL([FUZZING], [test "$enable_fuzzing" = "yes"])

OLD_LIBS=$LIBS
AC_SEARCH_LIBS([dlsym], [dl dld])
FUZZ_LIBS=$LIBS
LIBS=$OLD_LIBS
AC_SUBST([FUZZ_LIBS])

AC_CONFIG_FILES([
  Makefile
  doc/Makefile
  doc/reference/Makefile
  examples/Makefile
  lib/Makefile
  lib/gl/Makefile
  lib/libtasn1.pc
  src/Makefile
  tests/Makefile
  fuzz/Makefile
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
  Fuzzing build:    $enable_fuzzing, $LIB_FUZZING_ENGINE
])
