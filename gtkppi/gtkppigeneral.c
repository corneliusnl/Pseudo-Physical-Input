/*
 * Pseudo-Physical Input Control Panel
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy.  All Rights Reserved.
 */
#include <gtk/gtk.h>
#include "gtkppigeneral.h"

/*
 * General->Create
 */
GtkWidget *General_Create(TGeneral *General)
{
	GtkWidget	*Label;
	GtkWidget	*Menu, *MenuItem;
	
	General = g_malloc(sizeof(TGeneral));

	/* Create Outer Frame */
	General->Frame = gtk_frame_new("General Preferences...");
	gtk_container_border_width(GTK_CONTAINER(General->Frame), 4);
	gtk_widget_show(General->Frame);

	/* Create Inner Table */
	General->Table = gtk_table_new(3, 2, FALSE);
	gtk_container_add(GTK_CONTAINER(General->Frame), General->Table);
	gtk_container_border_width(GTK_CONTAINER(General->Table), 4);
	gtk_widget_show(General->Table);
	
	/* Communications Port */
	Label = gtk_label_new("Com port:");
	gtk_table_attach(GTK_TABLE(General->Table), Label, 0, 1, 0, 1,
		GTK_FILL, GTK_FILL, 0, 0);
	gtk_widget_show(Label);

	Menu = gtk_menu_new();
	MenuItem = gtk_menu_item_new_with_label("/dev/cua0");
	gtk_widget_show(MenuItem);
	gtk_menu_append(GTK_MENU(Menu), MenuItem);
	
	MenuItem = gtk_menu_item_new_with_label("/dev/cua1");
	gtk_widget_show(MenuItem);
	gtk_menu_append(GTK_MENU(Menu), MenuItem);

	General->ComPort = gtk_option_menu_new();
	gtk_table_attach(GTK_TABLE(General->Table), General->ComPort, 1, 2, 0, 1,
		GTK_FILL | GTK_EXPAND, GTK_FILL, 0, 0);
	gtk_option_menu_set_menu(GTK_OPTION_MENU(General->ComPort), Menu);
	gtk_widget_show(General->ComPort);
	
	/* Finger Sensitivity */
	Label = gtk_label_new("Finger Sensitivty:");
	gtk_widget_show(Label);
	gtk_table_attach(GTK_TABLE(General->Table), Label, 0, 1, 1, 2,
		GTK_FILL, GTK_FILL, 0, 0);

	General->FingerSensitivity = gtk_hscale_new(GTK_ADJUSTMENT(gtk_adjustment_new(0, 0, 100, 1, 10, 10)));
	gtk_table_attach(GTK_TABLE(General->Table), General->FingerSensitivity, 1, 2, 1, 2,
		GTK_FILL | GTK_EXPAND, GTK_FILL, 0, 0);
	gtk_widget_show(General->FingerSensitivity);
	
	/* Motion Sensitivity */
	Label = gtk_label_new("Motion Sensitivty:");
	gtk_widget_show(Label);
	gtk_table_attach(GTK_TABLE(General->Table), Label, 0, 1, 2, 3,
		GTK_FILL, GTK_FILL, 0, 0);

	General->MotionSensitivity = gtk_hscale_new(GTK_ADJUSTMENT(gtk_adjustment_new(0, 0, 100, 1, 10, 10)));
	gtk_table_attach(GTK_TABLE(General->Table), General->MotionSensitivity, 1, 2, 2, 3,
		GTK_FILL | GTK_EXPAND, GTK_FILL, 0, 0);
	gtk_widget_show(General->MotionSensitivity);
	
	return General->Frame;
}
