include_HEADERS = libtasn1.h 

bin_SCRIPTS = libtasn1-config

m4datadir = $(datadir)/aclocal
dist_m4data_DATA = libtasn1.m4

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libtasn1.pc

lib_LTLIBRARIES = libtasn1.la

libtasn1_la_SOURCES = libtasn1.h der.h mem.h gstr.h errors.h defines.h	\
	int.h parser_aux.h structure.h errors_int.h element.h ASN1.y	\
	decoding.c gstr.c errors.c parser_aux.c structure.c element.c	\
	coding.c

libtasn1_la_LDFLAGS = -no-undefined \
	-version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

if HAVE_LD_VERSION_SCRIPT
libgnutls_la_LDFLAGS += -Wl,--version-script=$(srcdir)/libtasn1.vers
endif
