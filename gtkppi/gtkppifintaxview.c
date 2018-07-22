/*
 * PPI FinTax View GTK Widget
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */
#include <gtk/gtk.h>
#include "gtkppifintaxview.h"

static void gtk_ppi_fintaxview_class_init(GtkPPIFinTaxViewClass *klass);
static void gtk_ppi_fintaxview_init(GtkPPIFinTaxView *FinTax);
static gint configure_event(GtkWidget *Widget, GdkEventConfigure *Event);
static gint expose_event(GtkWidget *Widget, GdkEventExpose *Event);

static GdkPixmap *Pixmap = NULL;

int Visual_Attributes[] = { GDK_GL_RGBA, GDK_GL_NONE };

/*
 * gtk->ppi->fintaxview->get_type
 */
guint gtk_ppi_fintaxview_get_type()
{
	static guint type = 0;

	if(!type)
	{
		GtkTypeInfo temp_info =
		{
			"PPIFinTaxView",
			sizeof(GtkPPIFinTaxView),
			sizeof(GtkPPIFinTaxViewClass),
			(GtkClassInitFunc)gtk_ppi_fintaxview_class_init,
			(GtkObjectInitFunc)gtk_ppi_fintaxview_init,
			/* Reserved */ NULL,
			/* Reserved */ NULL,
			(GtkClassInitFunc)NULL
		};

		type = gtk_type_unique(gtk_table_get_type(), &temp_info);
	}

	return type;
}

/*
 *
 */
static void gtk_ppi_fintaxview_class_init(GtkPPIFinTaxViewClass *Class)
{
}

/*
 * gtk->ppi->fintax->init
 */
static void gtk_ppi_fintaxview_init(GtkPPIFinTaxView *FinTax)
{
/*
	if(gdk_gl_query() == FALSE)
	{
		g_print("OpenGL not supported\n");
		exit(0);
	}

	FinTax->Visual = gdk_gl_choose_visual(Visual_Attributes);
	if(FinTax->Visual == NULL)
	{
		g_print("Can't get visual!\n");
		exit(0);
	}

	gtk_widget_set_default_colormap(gdk_colormap_new(FinTax->Visual, TRUE));
	gtk_widget_set_default_visual(FinTax->Visual);

	FinTax->Context = gdk_gl_context_new(FinTax->Visual);
	FinTax->Pixmap = gdk_pixmap_new(NULL, 80, 80, FinTax->Visual->depth);
	FinTax->glPixmap = gdk_gl_pixmap_new(FinTax->Visual, FinTax->Pixmap);

	FinTax->ViewPort = gtk_pixmap_new(FinTax->Pixmap, NULL);
	gtk_table_attach(GTK_TABLE(FinTax), FinTax->ViewPort,
			0, 1, 0, 1,
			GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL,
			0, 0);
	gtk_widget_show(FinTax->ViewPort);
 */
/*	FinTax->Pixmap = gdk_pixmap_new(FinTax->ViewPort->window, 100, 100, -1);
	gdk_draw_rectangle(FinTax->Pixmap, FinTax->ViewPort->style->white_gc,
			TRUE, 0, 0, FinTax->ViewPort->allocation.width,
			FinTax->ViewPort->allocation.height);*/

	FinTax->ViewPort = gtk_drawing_area_new();
	gtk_drawing_area_size(GTK_DRAWING_AREA(FinTax->ViewPort), 200, 200);
			
	gtk_table_attach(GTK_TABLE(FinTax), FinTax->ViewPort,
			0, 1, 0, 1,
			GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL,
			0, 0);
	gtk_widget_show(FinTax->ViewPort);

	gtk_signal_connect(GTK_OBJECT(FinTax->ViewPort), "configure_event",
			(GtkSignalFunc)configure_event, NULL);
	gtk_signal_connect(GTK_OBJECT(FinTax->ViewPort), "expose_event",
			(GtkSignalFunc)expose_event, NULL);
}

/*
 * gtk->ppi->fintax->new
 */
GtkWidget *gtk_ppi_fintaxview_new()
{
	return GTK_WIDGET(gtk_type_new(gtk_ppi_fintaxview_get_type()));
}

gint configure_event(GtkWidget *Widget, GdkEventConfigure *Event)
{
	if(Pixmap)
		gdk_pixmap_unref(Pixmap);

	Pixmap = gdk_pixmap_new(Widget->window,
			Widget->allocation.width, Widget->allocation.height, -1);

	gdk_draw_rectangle(Pixmap, Widget->style->white_gc,
			TRUE, 0, 0, Widget->allocation.width, Widget->allocation.height);

	return TRUE;
}

gint expose_event(GtkWidget *Widget, GdkEventExpose *Event)
{
	gdk_draw_pixmap(Widget->window,
			Widget->style->fg_gc[GTK_WIDGET_STATE(Widget)],
			Pixmap,
			Event->area.x, Event->area.y,
			Event->area.x, Event->area.y,
			Event->area.width, Event->area.height);

	return FALSE;
}
