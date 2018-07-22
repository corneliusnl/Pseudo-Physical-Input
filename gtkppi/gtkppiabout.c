/*
 * Pseudo-Physical Input Control Panel
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */
#include <gtk/gtk.h>
#include "gtkppiabout.h"
#include "about.xpm"

/*
 * About->Create
 */
GtkWidget *About_Create(TAbout *About)
{
	GtkWidget	*Label;
	GdkPixmap	*Logo;
	GdkBitmap	*Mask;
	
	About = g_malloc(sizeof(TAbout));

	About->Handle = gtk_frame_new("About Pseudo-Physical Input...");
	gtk_container_border_width(GTK_CONTAINER(About->Handle), 4);
	gtk_widget_show(About->Handle);

	/* Vertical Box */
	About->VBox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(About->Handle), About->VBox);
	gtk_widget_show(About->VBox);
	
	/* PPI Logo */
	Logo = gdk_pixmap_create_from_xpm_d(GTK_WIDGET(About->VBox)->window, &Mask,
			NULL, about_xpm);
	About->Pixmap = gtk_pixmap_new(Logo, Mask);
	gdk_pixmap_unref(Logo);
	gdk_pixmap_unref(Mask);
	gtk_box_pack_start(GTK_BOX(About->VBox), About->Pixmap, FALSE, TRUE, 0);
	gtk_widget_show(About->Pixmap);

	/* Driver Version */
	Label = gtk_label_new("PPI Driver Version: 1.0.0");
	gtk_box_pack_start(GTK_BOX(About->VBox), Label, FALSE, TRUE, 0);
	gtk_widget_show(Label);

	return About->Handle;
}
