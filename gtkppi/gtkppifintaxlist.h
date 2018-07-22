#ifndef __GTKPPIFINTAXLIST_H__
#define __GTKPPIFINTAXLIST_H__
/*
 * PPI Fintax List GTK Widget
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */
#include <gtk/gtk.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GTKPPIFINTAXLIST(obj)		GTK_CHECK_CAST (obj, gtk_ppi_fintaxlist_get_type(), GtkPPIFinTaxList)
#define GTKPPIFINTAXLIST_CLASS(klass)	GTK_CHECK_CLASS_CAST (klass, gtk_ppi_fintaxlist_get_type(), GtkPPIFinTaxListClass)
#define IS_GTKPPIFINTAXLIST(obj)	GTK_CHECK_TYPE (obj, gtk_ppi_fintaxlist_get_type())

typedef struct
{
	GtkVBox		VBox;

	GtkWidget	*CList;
	GtkWidget	*ButtonBox;
	GtkWidget	*Load;
	GtkWidget	*Save;
	GtkWidget	*Remove;
	GtkWidget	*Add;

} GtkPPIFinTaxList;

typedef struct
{
	GtkVBoxClass	parent_class;

} GtkPPIFinTaxListClass;

guint		gtk_ppi_fintaxlist_get_type(void);
GtkWidget	*gtk_ppi_fintaxlist_new(void);

#ifdef __cplusplus
}
#endif

#endif
