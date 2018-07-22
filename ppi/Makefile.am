## Process this file with automake to produce Makefile.in

INCLUDES = -I$(top_srcdir)

ppiincludedir = $(includedir)/ppi

lib_LTLIBRARIES = libppi.la

ppiinclude_HEADERS =			\
	ppi.h				\
	ppimouse.h			\
	ppikeyboard.h 			\
	ppisignlanguage.h
libppi_la_SOURCES  =			\
	ppi.c				\
	ppimouse.c			\
	ppikeyboard.c			\
	ppisignlanguage.c
libppi_la_LDFLAGS  = -version-info $(PPI_LIBRARY_VERSION) 
