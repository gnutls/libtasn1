EXTRA_DIST = asn1.tex asn1.ps fdl.tex TODO
SUBDIRS = scripts


TEX_OBJECTS = asn1.tex ../lib/asn1-api.tex 

asn1.ps: $(TEX_OBJECTS)
	-$(LN_S) ../lib/asn1-api.tex .
	-latex asn1.tex && latex asn1.tex && dvips asn1.dvi -o asn1.ps

asn1.html: asn1.ps $(TEX_OBJECTS)
	-latex2html asn1.tex -no_navigation -split 0 -local_icons -html_version 3.2,math \
	-info "" -white


clean:
	@-rm *.log *.aux *.toc
	@-rm *.pl index.html asn1.dvi
	@-rm WARNINGS asn1-api.tex
