INCLUDES = -I../lib

EXTRA_DIST = pkix.asn pkix_asn1_tab.c asn1Coding_test.asn asn1Coding_test.asg

noinst_PROGRAMS = asn1Parser asn1Coding asn1Decoding asn1c CertificateExample \
                  CrlExample
 
asn1Parser_SOURCES = asn1Parser.c  
asn1Parser_LDADD = ../lib/libtasn1.la

asn1Coding_SOURCES = asn1Coding.c  
asn1Coding_LDADD = ../lib/libtasn1.la

asn1Decoding_SOURCES = asn1Decoding.c  
asn1Decoding_LDADD = ../lib/libtasn1.la

CertificateExample_SOURCES = CertificateExample.c  
CertificateExample_LDADD = ../lib/libtasn1.la

CrlExample_SOURCES = CrlExample.c  
CrlExample_LDADD = ../lib/libtasn1.la

asn1c_SOURCES = asn1c.c
asn1c_LDADD = ../lib/libtasn1.la
