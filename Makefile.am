## Process this file with automake to produce Makefile.in

SUBDIRS = lib src tests doc

ChangeLog:
	cvs2cl --utc -U .cvsusers --fsf -t -S -I ChangeLog -I .cvs

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
	scp $(distdir).tar.gz{,.sig} igloo.linux.gr:/ftp/pub/gnutls/libtasn1
	ssh igloo.linux.gr 'cd /ftp/pub/gnutls/libtasn1 && sha1sum *.tar.gz *.tar.bz2 > CHECKSUMS'
	cp -v $(distdir).tar.gz{,.sig} $(htmldir)/releases/libtasn1/
	cd $(htmldir) && \
		cvs add -kb releases/libtasn1/$(distdir).tar.gz{,.sig} && \
		cvs commit -m "Update." releases/libtasn1/
