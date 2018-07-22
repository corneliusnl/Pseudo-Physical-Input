/*
 * Pseudo-Physical Input Control Panel
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 * 
 * Description:
 * 	Allows the user to configure the options associated with
 * 	the emulation of the mouse.
 */
#include <gtk/gtk.h>
#include <ppi/ppi.h>
#include "gtkppimouse.h"

/*
 * Mouse->Create
 */
GtkWidget *Mouse_Create(TMouse *Mouse)
{
	GtkWidget	*Label;
	GtkWidget	*Menu, *Menuitem;
	
	Mouse = g_malloc(sizeof(TMouse));

	/* Verticle Box */
	Mouse->VBox = gtk_vbox_new(FALSE, 0);
	gtk_container_border_width(GTK_CONTAINER(Mouse->VBox), 4);
	gtk_widget_show(Mouse->VBox);
	
	/* Mouse Enabler/Disabler */
	Mouse->Enabler = gtk_check_button_new_with_label("Enable Pseudo-Mouse");
	gtk_signal_connect(GTK_OBJECT(Mouse->Enabler), "toggled",
		GTK_SIGNAL_FUNC(Mouse_Enabler_Toggle_Update),
		(gpointer)Mouse);
	gtk_box_pack_start(GTK_BOX(Mouse->VBox), Mouse->Enabler, FALSE, TRUE, 0);
	gtk_widget_show(Mouse->Enabler);
	
	/* Mouse Preferences Frame */
	Mouse->Frame = gtk_frame_new("Mouse Preferences...");
	gtk_container_border_width(GTK_CONTAINER(Mouse->Frame), 4);
	gtk_widget_show(Mouse->Frame);
	gtk_box_pack_start(GTK_BOX(Mouse->VBox), Mouse->Frame, TRUE, TRUE, 0);

	Mouse->Table = gtk_table_new(5, 2, FALSE);
	gtk_container_add(GTK_CONTAINER(Mouse->Frame), Mouse->Table);
	gtk_container_border_width(GTK_CONTAINER(Mouse->Table), 4);
	gtk_widget_show(Mouse->Table);

	/* Mouse Orientation */
	Label = gtk_label_new("Orientation:");
	gtk_table_attach(GTK_TABLE(Mouse->Table), Label, 0, 1, 1, 2,
		GTK_FILL, GTK_FILL, 0, 0);
	gtk_widget_show(Label);

	Menu = gtk_menu_new();
	Menuitem = gtk_menu_item_new_with_label("Right Handed");
	gtk_widget_show(Menuitem);
	gtk_menu_append(GTK_MENU(Menu), Menuitem);

	Menuitem = gtk_menu_item_new_with_label("Left Handed");
	gtk_widget_show(Menuitem);
	gtk_menu_append(GTK_MENU(Menu), Menuitem);

	Mouse->Orientation = gtk_option_menu_new();
	gtk_table_attach(GTK_TABLE(Mouse->Table), Mouse->Orientation, 1, 2, 1, 2,
		GTK_EXPAND | GTK_FILL, GTK_FILL, 0, 0);
	gtk_option_menu_set_menu(GTK_OPTION_MENU(Mouse->Orientation), Menu);
	gtk_widget_show(Mouse->Orientation);

	/* Mouse Double Click Speed */
	Label = gtk_label_new("DblClk Speed:");
	gtk_table_attach(GTK_TABLE(Mouse->Table), Label, 0, 1, 2, 3,
		GTK_FILL, GTK_FILL, 0, 0);
	gtk_widget_show(Label);
	
	Mouse->DblClkSpeed = gtk_hscale_new(GTK_ADJUSTMENT(gtk_adjustment_new(0, 0, 0, 0, 0, 0)));
	gtk_table_attach(GTK_TABLE(Mouse->Table), Mouse->DblClkSpeed, 1, 2, 2, 3,
		GTK_FILL | GTK_EXPAND, GTK_FILL, 0, 0);
	gtk_widget_show(Mouse->DblClkSpeed);

	/* Mouse FinTax List */
	Mouse->FinTaxList = gtk_ppi_fintaxlist_new();
	gtk_table_attach(GTK_TABLE(Mouse->Table), Mouse->FinTaxList, 0, 2, 3, 4,
		GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
	gtk_widget_show(Mouse->FinTaxList);

	return Mouse->VBox;
}

/*
 * Mouse->Enabler_Toggle_Update
 */
void Mouse_Enabler_Toggle_Update(GtkWidget *Widget, gpointer Data)
{
	if(GTK_TOGGLE_BUTTON(Widget)->active)
	{
		gtk_widget_set_sensitive(((TMouse *)Data)->Table, FALSE);
		ppi_Mouse_Enable(FALSE);
	}
	else
	{
		gtk_widget_set_sensitive(((TMouse *)Data)->Table, TRUE);
		ppi_Mouse_Enable(TRUE);
	}
}
