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

INCLUDES = -I../lib

AM_LDFLAGS = -no-install

EXTRA_DIST = Test_parser.asn Test_tree.asn Test_tree_asn1_tab.c

TESTS = Test_parser Test_tree
check_PROGRAMS = $(TESTS)
Test_parser_SOURCES = Test_parser.c  
Test_parser_LDADD = ../lib/libtasn1.la

Test_tree_SOURCES = Test_tree.c  
Test_tree_LDADD = ../lib/libtasn1.la

VALGRIND=valgrind --leak-check=full --leak-resolution=high \
	--show-reachable=yes --num-callers=50
TESTS_ENVIRONMENT = \
	ASN1PARSER=$(srcdir)/Test_parser.asn \
	ASN1TREE=$(srcdir)/Test_tree.asn \
	`if type valgrind > /dev/null 2>&1; then echo $(VALGRIND); else echo $$SHELL -c; fi`
