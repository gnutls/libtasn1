## Process this file with automake to produce Makefile.in
# Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation
#
# This file is part of LIBTASN1.
#
# This file is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This file is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this file; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

INCLUDES = -I$(top_srcdir)/lib -I$(top_srcdir)/gl -I../gl

AM_LDFLAGS = -no-install
LDADD = ../lib/libtasn1.la

EXTRA_DIST = Test_parser.asn Test_tree.asn Test_tree_asn1_tab.c	\
	Test_encoding.asn 

# For crlf.
EXTRA_DIST += pkix.asn crlf.cer
dist_check_SCRIPTS = crlf

MOSTLYCLEANFILES = Test_parser_ERROR.asn

check_PROGRAMS = Test_parser Test_tree Test_encoding

TESTS = Test_parser Test_tree Test_encoding crlf

TESTS_ENVIRONMENT = \
	ASN1PARSER=$(srcdir)/Test_parser.asn \
	ASN1TREE=$(srcdir)/Test_tree.asn \
	ASN1ENCODING=$(srcdir)/Test_encoding.asn \
	$(VALGRIND)
