include_HEADERS = libtasn1.h 

EXTRA_DIST = libtasn1.h der.h asn1-api.tex mem.h gstr.h errors.h \
             defines.h int.h parser_aux.h structure.h errors_int.h \
             element.h asn1-api.tex libtasn1.vers

lib_LTLIBRARIES = libtasn1.la

if HAVE_LD_VERSION_SCRIPT
  libtasn1_version_script_cmd = -Wl,--version-script=$(srcdir)/libtasn1.vers
else
  libtasn1_version_script_cmd =
endif


# Separate so we can create the documentation
COBJECTS = ASN1.y decoding.c gstr.c errors.c parser_aux.c \
           structure.c element.c coding.c

libtasn1_la_SOURCES = $(COBJECTS) 

libtasn1_la_LDFLAGS = -no-undefined -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
	$(libtasn1_version_script_cmd)

asn1-api.tex: $(COBJECTS)
	@echo "% \\newpage" > asn1-api.tex
	@for i in $(COBJECTS); \
	do echo -n "Creating documentation for file $$i... " && $(PERL) ../doc/scripts/gdoc -tex $$i >> asn1-api.tex \
	&& echo "ok"; \
	done

all-local: asn1-api.tex
