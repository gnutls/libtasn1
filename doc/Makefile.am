if ENABLE_GTK_DOC
SUBDIRS = reference
endif

EXTRA_DIST = gdoc TODO libtasn1.html libtasn1.ps libtasn1.pdf

info_TEXINFOS = libtasn1.texi
libtasn1_TEXINFOS = fdl.texi $(gdoc_TEXINFOS)

AM_MAKEINFOHTMLFLAGS = --no-split

dist_man_MANS = $(gdoc_MANS)

gdoc_MANS = man/asn1_parser2tree.3 man/asn1_parser2array.3 man/asn1_der_coding.3 man/asn1_der_decoding.3 man/asn1_der_decoding_element.3 man/asn1_der_decoding_startEnd.3 man/asn1_expand_any_defined_by.3 man/asn1_expand_octet_string.3 man/asn1_write_value.3 man/asn1_read_value.3 man/asn1_read_tag.3 man/libtasn1_perror.3 man/libtasn1_strerror.3 man/asn1_check_version.3 man/asn1_array2tree.3 man/asn1_delete_structure.3 man/asn1_delete_element.3 man/asn1_create_element.3 man/asn1_print_structure.3 man/asn1_number_of_elements.3 man/asn1_find_structure_from_oid.3
gdoc_TEXINFOS = texi/ASN1.c.texi texi/coding.c.texi texi/decoding.c.texi texi/element.c.texi texi/errors.c.texi texi/gstr.c.texi texi/parser_aux.c.texi texi/structure.c.texi texi/asn1_parser2tree.texi texi/asn1_parser2array.texi texi/asn1_der_coding.texi texi/asn1_der_decoding.texi texi/asn1_der_decoding_element.texi texi/asn1_der_decoding_startEnd.texi texi/asn1_expand_any_defined_by.texi texi/asn1_expand_octet_string.texi texi/asn1_write_value.texi texi/asn1_read_value.texi texi/asn1_read_tag.texi texi/libtasn1_perror.texi texi/libtasn1_strerror.texi texi/asn1_check_version.texi texi/asn1_array2tree.texi texi/asn1_delete_structure.texi texi/asn1_delete_element.texi texi/asn1_create_element.texi texi/asn1_print_structure.texi texi/asn1_number_of_elements.texi texi/asn1_find_structure_from_oid.texi

$(gdoc_MANS) $(gdoc_TEXINFOS):
	make update-makefile
	make Makefile
	make doit

GDOC_SRC = $(top_srcdir)/lib/*.c

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
