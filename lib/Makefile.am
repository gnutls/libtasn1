## Process this file with automake to produce Makefile.in
# Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 Free Software Foundation
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

SUBDIRS = gllib

AM_CFLAGS = $(WARN_CFLAGS)
AM_CPPFLAGS = -I$(builddir)/gllib

include_HEADERS = libtasn1.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libtasn1.pc

lib_LTLIBRARIES = libtasn1.la

libtasn1_la_SOURCES = libtasn1.h gstr.h errors.h int.h parser_aux.h	\
	structure.h element.h ASN1.y decoding.c gstr.c errors.c		\
	parser_aux.c structure.c element.c coding.c libtasn1.vers

libtasn1_la_LDFLAGS = -no-undefined \
	-version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

if HAVE_LD_VERSION_SCRIPT
libtasn1_la_LDFLAGS += -Wl,--version-script=$(srcdir)/libtasn1.vers
endif
