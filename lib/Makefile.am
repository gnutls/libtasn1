include_HEADERS = asn1.h 

EXTRA_DIST = asn1.h der.h asn1-api.tex mem.h gstr.h

lib_LTLIBRARIES = libasn1.la

# Separate so we can create the documentation
COBJECTS = ASN.y asn1.c der.c gstr.c

libasn1_la_SOURCES = $(COBJECTS) 

libasn1_la_LDFLAGS = -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

asn1-api.tex: $(COBJECTS)
	@echo "\\newpage" > asn1-api.tex
	@for i in $(COBJECTS); \
	do echo -n "Creating documentation for file $$i... " && ../doc/scripts/gdoc -tex $$i >> asn1-api.tex \
	&& echo "ok"; \
	done

all-local: asn1-api.tex
