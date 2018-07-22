#ifndef __GTKPPIFINTAXLIST_H__
#define __GTKPPIFINTAXLIST_H__
//
// PPI Fintax Edit GTK Widget
// Copyright 1997-1999 (c) Lepreschaun Software. All Rights Reserved.
//
#include <gtk/gtk.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GTKPPIFINTAXEDIT(obj)		GTK_CHECK_CAST (obj, gtk_ppi_fintaxedit_get_type(), GtkPPIFinTaxEdit)
#define GTKPPIFINTAXEDIT_CLASS(klass)	GTK_CHECK_CLASS_CAST (klass, gtk_ppi_fintaxedit_get_type(), GtkPPIFinTaxEditClass)
#define IS_GTKPPIFINTAXEDIT(obj)	GTK_CHECK_TYPE (obj, gtk_ppi_fintaxedit_get_type())

typedef struct
{
	GtkTable	Table;


} GtkPPIFinTaxEdit;

typedef struct
{
	GtkTableClass	parent_class;

} GtkPPIFinTaxEditClass;

guint		gtk_ppi_fintaxedit_get_type(void);
GtkWidget	*gtk_ppi_fintaxedit_new(void);

#ifdef __cplusplus
}
#endif

#endif
