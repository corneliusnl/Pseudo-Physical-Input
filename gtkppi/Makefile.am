## Process this file with automake to produce Makefile.in

INCLUDES = -I$(top_srcdir)

gtkppiincludedir = $(includedir)/gtkppi

LDADD = $(top_builddir)/ppi/libppi.la libxml.la 

lib_LTLIBRARIES = libgtkppi.la

gtkppiinclude_HEADERS =			\
	gtkppi.h			\
	gtkppiconfig.h			\
	gtkppifintaxlist.h		\
	gtkppifintaxview.h		\
	gtkppigeneral.h 		\
	gtkppimouse.h			\
	gtkppikeyboard.h		\
	gtkppisignlanguage.h		\
	gtkppiabout.h
libgtkppi_la_SOURCES  =			\
	gtkppiconfig.c			\
	gtkppifintaxlist.c		\
	gtkppifintaxview.c		\
	gtkppigeneral.c			\
	gtkppimouse.c			\
	gtkppikeyboard.c		\
	gtkppisignlanguage.c		\
	gtkppiabout.c
	
libgtkppi_la_LDFLAGS  = -version-info $(PPI_LIBRARY_VERSION) 
