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

# Makefile to build libtasn1 as static library (libtasn1.lib)

# Written by Vasiliy Olekhov November 2016.

VPATH=../gl:../lib:../lib/gllib

SRC= ASN1.c coding.c decoding.c element.c errors.c gstr.c 
SRC+= parser_aux.c structure.c version.c
SRC+= strverscmp.c hash-pjw-bare.c

TARGET=libtasn1.lib

ifeq ($(ARCH), 64)
ULSIZE=8
else
ULSIZE=4
endif

CFLAGS+=/D inline=__inline /D ASN1_STATIC /D _CRT_SECURE_NO_WARNINGS /D ASN1_API=
CFLAGS+=/D SIZEOF_UNSIGNED_INT=4 /D SIZEOF_UNSIGNED_LONG_INT=$(ULSIZE)
CFLAGS+=/D HAVE_CONFIG_H
CFLAGS+=-I ../lib/gllib -I ../lib -I ../gl /I . -I ..

# GLib stuff
CFLAGS+=/D _GL_ATTRIBUTE_PURE=
# snprintf workaround
CFLAGS+=/FI ./snprintf.h

include msvc_lib.mk
