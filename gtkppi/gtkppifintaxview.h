#ifndef __GTKPPIFINTAXVIEW_H__
#define __GTKPPIFINTAXVIEW_H__
/*
 * PPI Fintax View GTK Widget
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gtkgl/gdkgl.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GTKPPIFINTAXVIEW(obj)		GTK_CHECK_CAST (obj, gtk_ppi_fintaxview_get_type(), GtkPPIFinTaxView)
#define GTKPPIFINTAXVIEW_CLASS(klass)	GTK_CHECK_CLASS_CAST (klass, gtk_ppi_fintaxview_get_type(), GtkPPIFinTaxViewClass)
#define IS_GTKPPIFINTAXVIEW(obj)	GTK_CHECK_TYPE (obj, gtk_ppi_fintaxview_get_type())

typedef struct
{
	GtkTable	Table;

	GtkWidget	*ViewPort;
	GdkVisual	*Visual;
	GdkPixmap	*Pixmap;
/*	GdkGLPixmap	*glPixmap;
	GdkGLContext	*Context;*/

} GtkPPIFinTaxView;

typedef struct
{
	GtkTableClass	parent_class;

} GtkPPIFinTaxViewClass;

guint		gtk_ppi_fintaxview_get_type(void);
GtkWidget	*gtk_ppi_fintaxview_new(void);

#ifdef __cplusplus
}
#endif

#endif
