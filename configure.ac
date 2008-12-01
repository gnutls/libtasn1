dnl Process this file with autoconf to produce a configure script.
# Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software Foundation
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

AC_PREREQ(2.61)
AC_INIT([libtasn1], [2.0], [bug-gnutls@gnu.org])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE([1.10 -Wall -Werror -Wno-override])

# Library code modified:                              REVISION++
# Interfaces changed/added/removed:   CURRENT++       REVISION=0
# Interfaces added:                             AGE++
# Interfaces removed:                           AGE=0
AC_SUBST(LT_CURRENT, 5)
AC_SUBST(LT_REVISION, 0)
AC_SUBST(LT_AGE, 0)

AC_PROG_CC
gl_EARLY
AC_PROG_YACC
AC_PROG_LN_S

dnl Checks for programs.
AC_PROG_INSTALL
AM_MISSING_PROG(PERL, perl, $missing_dir)
AM_MISSING_PROG(HELP2MAN, help2man, $missing_dir)

AC_LIBTOOL_WIN32_DLL
AM_PROG_LIBTOOL

AC_CHECK_SIZEOF(unsigned long int, 4)
AC_CHECK_SIZEOF(unsigned int, 4)

sj_VALGRIND
sj_LINKER_SCRIPT
sj_UPDATE_HEADER_VERSION([$srcdir/lib/libtasn1.h])

# Check for gtk-doc.
GTK_DOC_CHECK(1.2)

# For gnulib compatibility modules in gl/.
gl_INIT

# Disable useless warnings.
W=
W="$W -Wsystem-headers"         # Don't let system headers trigger warnings
W="$W -Wc++-compat"             # We don't care strongly about C++ compilers
W="$W -Wtraditional"            # Warns on #elif which we use often
W="$W -Wtraditional-conversion" # Too many warnings for now
W="$W -Wconversion"             # Too many warnings for now
W="$W -Wsign-conversion"        # Too many warnings for now
W="$W -Wold-style-definition"   # 
W="$W -Wpadded"                 # Our structs are not padded
W="$W -Wundef"                  # 
W="$W -Wunreachable-code"       # Too many false positives
W="$W -Wunsafe-loop-optimizations"
W="$W -Wstrict-overflow"
gl_MANYWARN_ALL_GCC([WARNINGS])
gl_MANYWARN_COMPLEMENT(WARNINGS, [$WARNINGS], [$W])
for w in $WARNINGS; do
  gl_WARN_ADD([$w])
done
gl_WARN_ADD([-Wno-missing-field-initializers])
gl_WARN_ADD([-Wno-sign-compare])
gl_WARN_ADD([-Wno-pointer-sign])
gl_WARN_ADD([-Wno-unused-parameter])
gl_WARN_ADD([-fdiagnostics-show-option])

AC_CONFIG_FILES([
  Makefile
  doc/Makefile
  doc/cyclo/Makefile
  doc/reference/Makefile
  examples/Makefile
  gl/Makefile
  lib/Makefile
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
  Warning flags:    ${WARN_CFLAGS}
  Library types:    Shared=${enable_shared}, Static=${enable_static}
  Valgrind:         ${VALGRIND}
  Linker script:    $have_ld_version_script
])
