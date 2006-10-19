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

DISTCHECK_CONFIGURE_FLAGS = --enable-gtk-doc

EXTRA_DIST = windows/asn1-parser/asn1-parser.vcproj		\
	windows/asn1-parser/config.h windows/libtasn1.ncb	\
	windows/libtasn1.sln windows/libtasn1.suo		\
	windows/gnulib/getopt.h windows/gnulib/gnulib.vcproj	\
	windows/libtasn1/libtasn1.vcproj			\
	windows/test-parser/test-parser.vcproj			\
	windows/test-tree/test-tree.vcproj

SUBDIRS = gl lib src tests doc

ACLOCAL_AMFLAGS = -I m4 -I gl/m4

ChangeLog:
	cvs2cl --FSF --fsf --usermap .cvsusers -I ChangeLog -I .cvs \
		-I buildconf

htmldir = ../www-gnutls
tag = $(PACKAGE)_`echo $(VERSION) | sed 's/\./_/g'`

release:
	if cvs upd -p -r $(tag) NEWS > /dev/null; then false else true; fi
	cvs rtag $(tag) libtasn1
	rm -f ChangeLog
	make ChangeLog
	cvs commit -m "" ChangeLog
	cvs rtag -F $(tag) libtasn1
	make dist
	gpg -b $(distdir).tar.gz
	gpg --verify $(distdir).tar.gz.sig
	cd doc && ../gendocs.sh -o ../$(htmldir)/manual/libtasn1/ $(PACKAGE) "Libtasn1"
	cp -v doc/reference/html/*.{html,png,devhelp,css} $(htmldir)/manual/libtasn1/reference/
	cp -v $(distdir).tar.gz{,.sig} $(htmldir)/releases/libtasn1/
	cd $(htmldir) && \
		cvs add -kb releases/libtasn1/$(distdir).tar.gz{,.sig} && \
		cvs commit -m "Update." manual/libtasn1/ releases/libtasn1/
