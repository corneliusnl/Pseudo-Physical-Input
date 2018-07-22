#ifndef __GTKPPICONFIG_H__
#define __GTKPPICONFIG_H__
/*
 * Pseudo-Physical Input
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */
#include <gtk/gtk.h>
#include <gtkppi/gtkppigeneral.h>
#include <gtkppi/gtkppikeyboard.h>
#include <gtkppi/gtkppimouse.h>
#include <gtkppi/gtkppisignlanguage.h>
#include <gtkppi/gtkppiabout.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GTKPPICONFIG(obj)		GTK_CHECK_CAST (obj, gtk_ppi_config_get_type(), GtkPPIConfig)
#define GTKPPICONFIG_CLASS(klass)	GTK_CHECK_CLASS_CAST (klass, gtk_ppi_config_get_type(), GtkPPIConfigClass)
#define IS_GTKPPICONFIG(obj)		GTK_CHECK_TYPE (obj, gtk_ppi_config_get_type())

typedef struct
{
	GtkNotebook	Notebook;
	
	TGeneral	*General;
	TMouse		*Mouse;
	TKeyboard	*Keyboard;
	TSignLanguage	*SignLanguage;
	TAbout		*About;
} GtkPPIConfig;

typedef struct
{
	GtkNotebookClass	parent_class;

} GtkPPIConfigClass;

guint		gtk_ppi_config_get_type(void);

#define PPI_GENERAL		0x0001
#define PPI_MOUSE		0x0002
#define PPI_KEYBOARD		0x0004
#define PPI_SIGNLANGUAGE	0x0008
GtkWidget	*gtk_ppi_config_new(char *AppName, long Show);

#ifdef __cplusplus
}
#endif

#endif
