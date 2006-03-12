if ENABLE_GTK_DOC
SUBDIRS = reference
endif

EXTRA_DIST = gdoc TODO libtasn1.html libtasn1.ps libtasn1.pdf

info_TEXINFOS = libtasn1.texi
libtasn1_TEXINFOS = fdl.texi $(gdoc_TEXINFOS)

AM_MAKEINFOFLAGS = -I $(top_builddir)/doc
AM_MAKEINFOHTMLFLAGS = --no-split

dist_man_MANS = $(gdoc_MANS) asn1Parser.1 asn1Coding.1 asn1Decoding.1

HELP2MAN_OPTS = --info-page libtasn1

asn1Parser.1: $(top_srcdir)/src/asn1Parser.c $(top_srcdir)/configure.in
	$(HELP2MAN) $(HELP2MAN_OPTS) \
		--name="ASN.1 syntax tree generator for libtasn1" \
		--output=$@ $(top_builddir)/src/asn1Parser$(EXEEXT)

asn1Coding.1: $(top_srcdir)/src/asn1Coding.c $(top_srcdir)/configure.in
	$(HELP2MAN) $(HELP2MAN_OPTS) \
		--name="ASN.1 DER encoder" \
		--output=$@ $(top_builddir)/src/asn1Coding$(EXEEXT)

asn1Decoding.1: $(top_srcdir)/src/asn1Decoding.c $(top_srcdir)/configure.in
	$(HELP2MAN) $(HELP2MAN_OPTS) \
		--name="ASN.1 DER decoder" \
		--output=$@ $(top_builddir)/src/asn1Decoding$(EXEEXT)

gdoc_MANS = man/asn1_get_length_der.3 man/asn1_get_tag_der.3 man/asn1_get_octet_der.3 man/asn1_get_bit_der.3 man/asn1_der_decoding.3 man/asn1_der_decoding_element.3 man/asn1_der_decoding_startEnd.3 man/asn1_expand_any_defined_by.3 man/asn1_expand_octet_string.3 man/libtasn1_perror.3 man/libtasn1_strerror.3 man/asn1_find_node.3 man/asn1_check_version.3 man/asn1_length_der.3 man/asn1_octet_der.3 man/asn1_bit_der.3 man/asn1_der_coding.3 man/asn1_write_value.3 man/asn1_read_value.3 man/asn1_read_tag.3 man/asn1_array2tree.3 man/asn1_delete_structure.3 man/asn1_delete_element.3 man/asn1_create_element.3 man/asn1_print_structure.3 man/asn1_number_of_elements.3 man/asn1_find_structure_from_oid.3 man/asn1_copy_node.3 man/asn1_parser2tree.3 man/asn1_parser2array.3
gdoc_TEXINFOS = texi/decoding.c.texi texi/errors.c.texi texi/parser_aux.c.texi texi/coding.c.texi texi/element.c.texi texi/gstr.c.texi texi/structure.c.texi texi/ASN1.c.texi texi/asn1_get_length_der.texi texi/asn1_get_tag_der.texi texi/asn1_get_octet_der.texi texi/asn1_get_bit_der.texi texi/asn1_der_decoding.texi texi/asn1_der_decoding_element.texi texi/asn1_der_decoding_startEnd.texi texi/asn1_expand_any_defined_by.texi texi/asn1_expand_octet_string.texi texi/libtasn1_perror.texi texi/libtasn1_strerror.texi texi/asn1_find_node.texi texi/asn1_check_version.texi texi/asn1_length_der.texi texi/asn1_octet_der.texi texi/asn1_bit_der.texi texi/asn1_der_coding.texi texi/asn1_write_value.texi texi/asn1_read_value.texi texi/asn1_read_tag.texi texi/asn1_array2tree.texi texi/asn1_delete_structure.texi texi/asn1_delete_element.texi texi/asn1_create_element.texi texi/asn1_print_structure.texi texi/asn1_number_of_elements.texi texi/asn1_find_structure_from_oid.texi texi/asn1_copy_node.texi texi/asn1_parser2tree.texi texi/asn1_parser2array.texi

$(gdoc_MANS) $(gdoc_TEXINFOS):
	make update-makefile
	make Makefile
	make doit

GDOC_SRC = $(top_srcdir)/lib/decoding.c $(top_srcdir)/lib/errors.c	\
	$(top_srcdir)/lib/parser_aux.c $(top_srcdir)/lib/coding.c	\
	$(top_srcdir)/lib/element.c $(top_srcdir)/lib/gstr.c		\
	$(top_srcdir)/lib/structure.c $(top_builddir)/lib/ASN1.c

update-makefile:
	@MANS=""; \
	TEXINFOS=""; \
	for i in $(GDOC_SRC); do \
		BASE=`basename $$i`; \
		TEXINFOS="$$TEXINFOS texi/$$BASE.texi"; \
	done; \
	FUNCS=`$(srcdir)/gdoc -listfunc $(GDOC_SRC)`; \
	for i in $$FUNCS; do \
		MANS="$$MANS man/$$i.3"; \
		TEXINFOS="$$TEXINFOS texi/$$i.texi"; \
	done; \
	perl -pi -e "s,^gdoc_MANS =.*,gdoc_MANS =$$MANS,;" \
		-e "s,^gdoc_TEXINFOS =.*,gdoc_TEXINFOS =$$TEXINFOS,;" \
		Makefile.am

doit:
	$(mkdir_p) man texi; \
	for i in `$(srcdir)/gdoc -listfunc $(GDOC_SRC)`; do \
		echo -n "Creating documentation for $$i... " && \
		$(srcdir)/gdoc -man \
			-module $(PACKAGE) -sourceversion $(VERSION) \
			-include libtasn1.h \
			-seeinfo $(PACKAGE) -verbatimcopying \
			-copyright "2001, 2002, 2003 Fabio Fiorina" \
			-function $$i \
			$(GDOC_SRC) > man/$$i.3 && \
		$(srcdir)/gdoc -texinfo -function $$i \
			$(GDOC_SRC) > texi/$$i.texi && \
		echo "ok"; \
	done; \
	for i in $(GDOC_SRC); do \
		BASE=`basename $$i`; \
		echo -n "Creating documentation for $$i... " && \
		$(srcdir)/gdoc -texinfo $$i > texi/$$BASE.texi && \
		echo "ok"; \
	done

.PHONY: update-makefile doit
