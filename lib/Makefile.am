include_HEADERS = libasn1.h 

EXTRA_DIST = libasn1.h der.h asn1-api.tex mem.h gstr.h errors.h \
             defines.h int.h parser_aux.h structure.h errors_int.h \
             element.h

lib_LTLIBRARIES = libasn1.la

# Separate so we can create the documentation
COBJECTS = ASN1.y decoding.c gstr.c errors.c parser_aux.c \
           structure.c element.c coding.c

libasn1_la_SOURCES = $(COBJECTS) 

libasn1_la_LDFLAGS = -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

asn1-api.tex: $(COBJECTS)
	@echo "% \\newpage" > asn1-api.tex
	@for i in $(COBJECTS); \
	do echo -n "Creating documentation for file $$i... " && ../doc/scripts/gdoc -tex $$i >> asn1-api.tex \
	&& echo "ok"; \
	done

all-local: asn1-api.tex
