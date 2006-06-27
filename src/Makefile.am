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

INCLUDES = -I$(top_srcdir)/lib -I$(top_srcdir)/gl -I$(top_builddir)/gl

EXTRA_DIST = pkix.asn pkix_asn1_tab.c asn1Coding_test.asn asn1Coding_test.asg

LDADD = ../lib/libtasn1.la

bin_PROGRAMS = asn1Parser asn1Coding asn1Decoding
noinst_PROGRAMS = CertificateExample CrlExample

asn1Parser_SOURCES = asn1Parser.c  

asn1Coding_SOURCES = asn1Coding.c  

asn1Decoding_SOURCES = asn1Decoding.c  

CertificateExample_SOURCES = CertificateExample.c  

CrlExample_SOURCES = CrlExample.c  
