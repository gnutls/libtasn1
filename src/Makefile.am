INCLUDES = -I../lib

EXTRA_DIST = pkix.asn

noinst_PROGRAMS = asn1c CertificateExample CrlExample 
CertificateExample_SOURCES = CertificateExample.c  
CertificateExample_LDADD = ../lib/libasn1.la
CrlExample_SOURCES = CrlExample.c  
CrlExample_LDADD = ../lib/libasn1.la
asn1c_SOURCES = asn1c.c
asn1c_LDADD = ../lib/libasn1.la
