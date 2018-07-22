/*
 * Pseudo-Physical Input Control Panel
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 * 
 * Description:
 * 	Allows the user to modify the properties which control the
 * 	keyboard emulation.
 */
#include <gtk/gtk.h>
#include <ppi/ppi.h>
#include "gtkppikeyboard.h"

/*
 * Keyboard->Create
 */
GtkWidget *Keyboard_Create(TKeyboard *Keyboard)
{
	GtkWidget	*Label;
	
	Keyboard = g_malloc(sizeof(TKeyboard));

	/* Verticle Box */
	Keyboard->VBox = gtk_vbox_new(FALSE, 0);
	gtk_container_border_width(GTK_CONTAINER(Keyboard->VBox), 4);
	gtk_widget_show(Keyboard->VBox);

	/* Keyboard Enable/Disable */
	Keyboard->Enabler = gtk_check_button_new_with_label("Enable Pseudo-Keyboard");
	gtk_signal_connect(GTK_OBJECT(Keyboard->Enabler), "toggled",
			(GtkSignalFunc)Keyboard_Enabler_Toggle_Update,
			(gpointer)Keyboard);
	gtk_box_pack_start(GTK_BOX(Keyboard->VBox), Keyboard->Enabler, FALSE, TRUE, 0);
	gtk_widget_show(Keyboard->Enabler);

	/* Keyboard Preferences */
	Keyboard->Frame = gtk_frame_new("Keyboard Preferences...");
	gtk_container_border_width(GTK_CONTAINER(Keyboard->Frame), 4);
	gtk_box_pack_start(GTK_BOX(Keyboard->VBox), Keyboard->Frame, TRUE, TRUE, 0);
	gtk_widget_show(Keyboard->Frame);

	Keyboard->Table = gtk_table_new(2, 4, FALSE);
	gtk_container_add(GTK_CONTAINER(Keyboard->Frame), Keyboard->Table);
	gtk_container_border_width(GTK_CONTAINER(Keyboard->Table), 4);
	gtk_widget_show(Keyboard->Table);

	/* Keyboard Repeat Rate */
	Label = gtk_label_new("Repeat Rate:");
	gtk_table_attach(GTK_TABLE(Keyboard->Table), Label, 0, 1, 1, 2,
		GTK_FILL, GTK_FILL, 0, 0);
	gtk_widget_show(Label);
	
	Keyboard->RepeatRate = gtk_hscale_new(GTK_ADJUSTMENT(gtk_adjustment_new(0, 0, 0, 0, 0, 0)));
	gtk_table_attach(GTK_TABLE(Keyboard->Table), Keyboard->RepeatRate, 1, 2, 1, 2,
		GTK_FILL | GTK_EXPAND, GTK_FILL, 0, 0);
	gtk_widget_show(Keyboard->RepeatRate);

	/* Keyboard FinTax List */
	Keyboard->FinTaxList = gtk_ppi_fintaxlist_new();
	gtk_table_attach(GTK_TABLE(Keyboard->Table), Keyboard->FinTaxList, 0, 2, 2, 3,
		GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
	gtk_widget_show(Keyboard->FinTaxList);
	
	return Keyboard->VBox;
}

/*
 * Keyboard->Enabler_Toggle_Update
 */
void Keyboard_Enabler_Toggle_Update(GtkWidget *Widget, gpointer Data)
{
	if(GTK_TOGGLE_BUTTON(Widget)->active)
	{
		gtk_widget_set_sensitive(((TKeyboard *)Data)->Table, FALSE);
		ppi_Keyboard_Enable(FALSE);
	}
	else
	{
		gtk_widget_set_sensitive(((TKeyboard *)Data)->Table, TRUE);
		ppi_Keyboard_Enable(TRUE);
	}
}

/*
 * Keyboard->New
 */
void Keyboard_New()
{
}

/*
 * Keyboard->Load
 */
void Keyboard_Load()
{
}

/*
 * Keyboard->Edit
 */
void Keyboard_Edit()
{
}
