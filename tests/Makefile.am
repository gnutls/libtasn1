INCLUDES = -I../lib

EXTRA_DIST = Test_parser.asn Test_tree.asn Test_tree_asn1_tab.c

noinst_PROGRAMS = Test_parser Test_tree
Test_parser_SOURCES = Test_parser.c  
Test_parser_LDADD = ../lib/libtasn1.la

Test_tree_SOURCES = Test_tree.c  
Test_tree_LDADD = ../lib/libtasn1.la
