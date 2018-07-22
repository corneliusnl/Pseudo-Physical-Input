/*
 * Pseudo-Physical Input Control Panel
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved. 
 */
#include <gtk/gtk.h>
//#include <gtkppi/gtkppi.h>
#include <gtkppi/gtkppiconfig.h>
#include "mainwindow.h"
#include "logo.xpm"

TMainWindow *MainWindow = NULL;	

/*
 * MainWindow->Create
 */
void MainWindow_Create(void)
{
	GtkWidget	*Label;
	GtkWidget	*Pixmap;
	GdkPixmap	*Logo;
	GdkBitmap	*Mask;

	MainWindow = g_malloc(sizeof(TMainWindow));

	/* Create Main Window */
	MainWindow->Handle = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(MainWindow->Handle), "Pseudo-Physical Input Control Panel v1.0");
	gtk_container_border_width(GTK_CONTAINER(MainWindow->Handle), 4);
	gtk_signal_connect(GTK_OBJECT(MainWindow->Handle), "destroy",
		GTK_SIGNAL_FUNC(MainWindow_Destroy), NULL);
	
	/* Create Table */
	MainWindow->Table = gtk_table_new(2, 2, FALSE);
	gtk_widget_show(MainWindow->Table);
	gtk_container_add(GTK_CONTAINER(MainWindow->Handle), MainWindow->Table);
	gtk_container_border_width(GTK_CONTAINER(MainWindow->Handle), 4);

	/* Post Logo */
	gtk_widget_realize(MainWindow->Handle);
	Logo = gdk_pixmap_create_from_xpm_d(MainWindow->Handle->window, &Mask,
		&MainWindow->Handle->style->bg[GTK_STATE_NORMAL],
		logo_xpm);
	Pixmap = gtk_pixmap_new(Logo, Mask);
	gdk_pixmap_unref(Logo);
	gdk_bitmap_unref(Mask);
	gtk_table_attach(GTK_TABLE(MainWindow->Table), Pixmap, 0, 1, 0, 2,
		GTK_FILL, GTK_FILL, 0 , 0);
	gtk_widget_show(Pixmap);
	
	/* PPI Configuration */
	MainWindow->Config = gtk_ppi_config_new("ppicontrolpanel",
			PPI_MOUSE | PPI_KEYBOARD | PPI_SIGNLANGUAGE | PPI_GENERAL);
	gtk_table_attach(GTK_TABLE(MainWindow->Table), MainWindow->Config, 1, 2, 0, 1,
			GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 4);
	gtk_widget_show(MainWindow->Config);
	
	/* Button Array */
	MainWindow->ButtonBox = gtk_hbutton_box_new();
	gtk_table_attach(GTK_TABLE(MainWindow->Table), MainWindow->ButtonBox, 1, 2, 1, 2,
		GTK_FILL, GTK_FILL, 0, 4);
	gtk_button_box_set_layout(GTK_BUTTON_BOX(MainWindow->ButtonBox), GTK_BUTTONBOX_END);
	gtk_button_box_set_spacing(GTK_BUTTON_BOX(MainWindow->ButtonBox), 4);
//	gtk_container_border_width(GTK_CONTAINER(MainWindow->ButtonBox), 4);
	gtk_widget_show(MainWindow->ButtonBox);
	
	MainWindow->OkButton = gtk_button_new_with_label("Ok");
	gtk_signal_connect(GTK_OBJECT(MainWindow->OkButton), "clicked",
		GTK_SIGNAL_FUNC(MainWindow_OnOkClick), NULL);
	gtk_widget_show(MainWindow->OkButton);
	gtk_container_add(GTK_CONTAINER(MainWindow->ButtonBox), MainWindow->OkButton);

	MainWindow->CancelButton = gtk_button_new_with_label("Cancel");
	gtk_signal_connect(GTK_OBJECT(MainWindow->CancelButton), "clicked",
		GTK_SIGNAL_FUNC(MainWindow_OnCancelClick), NULL);
	gtk_widget_show(MainWindow->CancelButton);
	gtk_container_add(GTK_CONTAINER(MainWindow->ButtonBox), MainWindow->CancelButton);
	
	gtk_widget_show(MainWindow->Handle);
}

/*
 * MainWindow->Destroy
 */
void MainWindow_Destroy(void)
{
	gtk_exit(0);
}

/*
 * MainWindow->OnOkClick
 */
void MainWindow_OnOkClick(GtkWidget *Widget, gpointer Data)
{
	gtk_exit(0);
}

/*
 * MainWindow->OnCancelClick
 */
void MainWindow_OnCancelClick(GtkWidget *Widget, gpointer Data)
{
	gtk_exit(0);
}
