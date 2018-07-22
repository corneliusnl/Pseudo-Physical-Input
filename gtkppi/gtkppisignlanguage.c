/*
 * Pseudo-Physical Input
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */
#include <gtk/gtk.h>
#include <ppi/ppi.h>
#include "gtkppisignlanguage.h"

/*
 * SignLanguage->Create
 */
GtkWidget *SignLanguage_Create(TSignLanguage *SignLanguage)
{
	GtkWidget	*Label;
	
	SignLanguage = g_malloc(sizeof(TSignLanguage));

	/* Verticle Box */
	SignLanguage->VBox = gtk_vbox_new(FALSE, 0);
	gtk_widget_show(SignLanguage->VBox);
	
	/* Sign Language Enabler/Disabler */
	SignLanguage->Enabler = gtk_check_button_new_with_label("Enable Sign Language");
	gtk_signal_connect(GTK_OBJECT(SignLanguage->Enabler), "toggled",
			(GtkSignalFunc)SignLanguage_Enabler_Toggle_Update,
			(gpointer)SignLanguage);
	gtk_box_pack_start(GTK_BOX(SignLanguage->VBox), SignLanguage->Enabler, FALSE, TRUE, 0);
	gtk_widget_show(SignLanguage->Enabler);

	/* Sign Language Preferences */
	SignLanguage->Frame = gtk_frame_new("Sign Language Preferences...");
	gtk_container_border_width(GTK_CONTAINER(SignLanguage->Frame), 4);
	gtk_box_pack_start(GTK_BOX(SignLanguage->VBox), SignLanguage->Frame, TRUE, TRUE, 0);
	gtk_widget_show(SignLanguage->Frame);

	SignLanguage->Table = gtk_table_new(2, 2, FALSE);
	gtk_container_add(GTK_CONTAINER(SignLanguage->Frame), SignLanguage->Table);
	gtk_container_border_width(GTK_CONTAINER(SignLanguage->Table), 4);
	gtk_widget_show(SignLanguage->Table);

	/* SignLanguage FinTax List */
	SignLanguage->FinTaxList = gtk_ppi_fintaxlist_new();
	gtk_table_attach(GTK_TABLE(SignLanguage->Table), SignLanguage->FinTaxList, 0, 2, 1, 2,
		GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
	gtk_widget_show(SignLanguage->FinTaxList);
	
	return SignLanguage->VBox;
}

/*
 * SignLangFrame->Enabler_Toggle_Update
 */
void SignLanguage_Enabler_Toggle_Update(GtkWidget *Widget, gpointer Data)
{
	if(GTK_TOGGLE_BUTTON(Widget)->active)
	{
		gtk_widget_set_sensitive(((TSignLanguage *)Data)->Table, FALSE);
		ppi_SignLanguage_Enable(FALSE);
//		gtk_widget_set_sensitive(SignLanguage->Enabler, TRUE);
	}
	else
	{
		gtk_widget_set_sensitive(((TSignLanguage *)Data)->Table, TRUE);
		ppi_SignLanguage_Enable(TRUE);
	}
}
