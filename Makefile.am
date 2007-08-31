## Process this file with automake to produce Makefile.in
# Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007 Free Software Foundation
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
	git log --pretty --numstat --summary | git2cl > ChangeLog

htmldir = ../www-gnutls
tag = $(PACKAGE)_`echo $(VERSION) | sed 's/\./_/g'`

release:
	! git-tag -l $(tag) > /dev/null
	rm -f ChangeLog
	$(MAKE) ChangeLog distcheck
	git commit -m Generated. ChangeLog
	git-tag -u b565716f! -m $(VERSION) $(tag)
	gpg -b $(distdir).tar.gz
	gpg --verify $(distdir).tar.gz.sig
	cd doc && ../build-aux/gendocs.sh -o ../$(htmldir)/manual/libtasn1/ $(PACKAGE) "Libtasn1"
	cp -v doc/reference/html/*.{html,png,devhelp,css} $(htmldir)/manual/libtasn1/reference/
	cp -v $(distdir).tar.gz{,.sig} $(htmldir)/releases/libtasn1/
	scp $(distdir).tar.gz{,.sig} igloo.linux.gr:~ftp/pub/gnutls/libtasn1/
	ssh igloo.linux.gr 'cd ~ftp/pub/gnutls/libtasn1/ && sha1sum *.tar.gz > CHECKSUMS'
	cd $(htmldir) && \
		cvs add -kb releases/libtasn1/$(distdir).tar.gz{,.sig} && \
		cvs commit -m "Update." manual/libtasn1/ releases/libtasn1/
