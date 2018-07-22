/*
 * PPI FinTax List GTK Widget
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */
#include <gtk/gtk.h>
#include "gtkppifintaxlist.h"

static void gtk_ppi_fintaxlist_class_init(GtkPPIFinTaxListClass *klass);
static void gtk_ppi_fintaxlist_init(GtkPPIFinTaxList *FinTax);
void gtk_ppi_fintaxlist_add(GtkWidget *Widget, gpointer Data);
void gtk_ppi_fintaxlist_remove(GtkWidget *Widget, gpointer Data);
void gtk_ppi_fintaxlist_load(GtkWidget *Widget, gpointer Data);
void gtk_ppi_fintaxlist_save(GtkWidget *Widget, gpointer Data);

/*
 * gtk->ppi->fintaxlist->get_type
 */
guint gtk_ppi_fintaxlist_get_type()
{
	static guint type = 0;

	if(!type)
	{
		GtkTypeInfo temp_info =
		{
			"PPIFinTaxList",
			sizeof(GtkPPIFinTaxList),
			sizeof(GtkPPIFinTaxListClass),
			(GtkClassInitFunc)gtk_ppi_fintaxlist_class_init,
			(GtkObjectInitFunc)gtk_ppi_fintaxlist_init,
			/* Reserved */ NULL,
			/* Reserved */ NULL,
			(GtkClassInitFunc)NULL
		};

		type = gtk_type_unique(gtk_vbox_get_type(), &temp_info);
	}

	return type;
}

/*
 * gtk->ppi->fintaxlist->class_init
 */
static void gtk_ppi_fintaxlist_class_init(GtkPPIFinTaxListClass *Class)
{
}

/*
 * gtk->ppi->fintaxlist->init
 */
static void gtk_ppi_fintaxlist_init(GtkPPIFinTaxList *FinTax)
{
	GtkWidget	*Label;

	FinTax->CList = gtk_clist_new(3);
	gtk_clist_column_titles_show(GTK_CLIST(FinTax->CList));
	gtk_box_pack_start(GTK_VBOX(FinTax), FinTax->CList, TRUE, TRUE, 0);
	gtk_widget_show(FinTax->CList);

	Label = gtk_label_new("Description");
	gtk_widget_show(Label);
	gtk_clist_set_column_width(GTK_CLIST(FinTax->CList), 0, 200);
	gtk_clist_set_column_widget(GTK_CLIST(FinTax->CList), 0, Label);

	Label = gtk_label_new("Action");
	gtk_widget_show(Label);
	gtk_clist_set_column_widget(GTK_CLIST(FinTax->CList), 1, Label);
	
	/* Horizontal Button Box */
	FinTax->ButtonBox = gtk_hbutton_box_new();
	gtk_box_pack_start(GTK_VBOX(FinTax), FinTax->ButtonBox, FALSE, TRUE, 2);
	gtk_widget_show(FinTax->ButtonBox);
	
	/* Add Template */
	FinTax->Add = gtk_button_new_with_label("Add...");
	gtk_signal_connect(GTK_OBJECT(FinTax->Add), "clicked",
			GTK_SIGNAL_FUNC(gtk_ppi_fintaxlist_add),
			FinTax);
	gtk_container_add(GTK_CONTAINER(FinTax->ButtonBox), FinTax->Add);
	gtk_widget_set_sensitive(FinTax->Add, TRUE);
	gtk_widget_show(FinTax->Add);

	/* Remove Template */
	FinTax->Remove = gtk_button_new_with_label("Remove");
	gtk_signal_connect(GTK_OBJECT(FinTax->Remove), "clicked",
			GTK_SIGNAL_FUNC(gtk_ppi_fintaxlist_remove),
			FinTax);
	gtk_container_add(GTK_CONTAINER(FinTax->ButtonBox), FinTax->Remove);
	gtk_widget_set_sensitive(FinTax->Remove, FALSE);
	gtk_widget_show(FinTax->Remove);
	
	/* Load Template */
	FinTax->Load = gtk_button_new_with_label("Load...");
	gtk_signal_connect(GTK_OBJECT(FinTax->Load), "clicked",
			GTK_SIGNAL_FUNC(gtk_ppi_fintaxlist_load),
			FinTax);
	gtk_container_add(GTK_CONTAINER(FinTax->ButtonBox), FinTax->Load);
	gtk_widget_set_sensitive(FinTax->Load, TRUE);
	gtk_widget_show(FinTax->Load);

	/* Save Template */
	FinTax->Save = gtk_button_new_with_label("Save As...");
	gtk_signal_connect(GTK_OBJECT(FinTax->Save), "clicked",
			GTK_SIGNAL_FUNC(gtk_ppi_fintaxlist_save),
			FinTax);
	gtk_container_add(GTK_CONTAINER(FinTax->ButtonBox), FinTax->Save);
	gtk_widget_set_sensitive(FinTax->Save, FALSE);
	gtk_widget_show(FinTax->Save);
}

/*
 * gtk->ppi->fintaxlist->new
 */
GtkWidget *gtk_ppi_fintaxlist_new()
{
	return GTK_WIDGET(gtk_type_new(gtk_ppi_fintaxlist_get_type()));
}

/*
 * gtk->ppi->fintaxlist->add
 */
void gtk_ppi_fintaxlist_add(GtkWidget *Widget, gpointer Data)
{
}

/*
 * gtk->ppi->fintaxlist->remove
 */
void gtk_ppi_fintaxlist_remove(GtkWidget *Widget, gpointer Data)
{
}

/*
 * gtk->ppi->fintaxlist->load
 */
void gtk_ppi_fintaxlist_load(GtkWidget *Widget, gpointer Data)
{
}

/*
 * gtk->ppi->fintaxlist->save
 */
void gtk_ppi_fintaxlist_save(GtkWidget *Widget, gpointer Data)
{
}
