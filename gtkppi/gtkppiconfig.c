//
// PPI Configuration GTK Widget
// Copyright 1997-1999 (c) Leprechaun Software. All Rights Reserved.
//
#include <gtk/gtk.h>
#include "gtkppiconfig.h"
#include "gtkppimouse.h"
#include "gtkppikeyboard.h"
#include "gtkppisignlanguage.h"
#include "gtkppiabout.h"

static void gtk_ppi_config_class_init(GtkPPIConfigClass *klass);
static void gtk_ppi_config_init(GtkPPIConfig *Config);

//
// gtk->ppi->config->get_type()
//
guint gtk_ppi_config_get_type()
{
	static guint type = 0;

	if(!type)
	{
		GtkTypeInfo temp_info =
		{
			"PPIConfig",
			sizeof(GtkPPIConfig),
			sizeof(GtkPPIConfigClass),
			(GtkClassInitFunc)gtk_ppi_config_class_init,
			(GtkObjectInitFunc)gtk_ppi_config_init,
			/* Reserved */ NULL,
			/* Reserved */ NULL,
			(GtkClassInitFunc)NULL
		};

		type = gtk_type_unique(gtk_notebook_get_type(), &temp_info);
	}

	return type;
}

//
// gtk->ppi->config->class_init
//
static void gtk_ppi_config_class_init(GtkPPIConfigClass *Class)
{
}

//
// gtk->ppi->config->init
//
static void gtk_ppi_config_init(GtkPPIConfig *Config)
{
}

//
// gtk->ppi->config->new
//
GtkWidget *gtk_ppi_config_new(char *AppName, long Show)
{
	GtkWidget	*Widget;
	GtkLabel	*Label;

	Widget = GTK_WIDGET(gtk_type_new(gtk_ppi_config_get_type()));

	// Show General Properties???
	if(Show & PPI_GENERAL)
	{
		Label = gtk_label_new("General");
		gtk_notebook_append_page(GTK_NOTEBOOK(Widget),
				General_Create(GTKPPICONFIG(Widget)->General), Label);
	}

	// Show Mouse Properties???
	if(Show & PPI_MOUSE)
	{
		Label = gtk_label_new("Keyboard");
		gtk_notebook_append_page(GTK_NOTEBOOK(Widget),
				Keyboard_Create(GTKPPICONFIG(Widget)->Keyboard), Label);
	}

	// Show Keyboard Properties???
	if(Show & PPI_KEYBOARD)
	{
		Label = gtk_label_new("Mouse");
		gtk_notebook_append_page(GTK_NOTEBOOK(Widget),
				Mouse_Create(GTKPPICONFIG(Widget)->Mouse), Label);
	}

	// Show Signlanguage Properties???
	if(Show & PPI_SIGNLANGUAGE)
	{
		Label = gtk_label_new("Sign Language");
		gtk_notebook_append_page(GTK_NOTEBOOK(Widget),
				SignLanguage_Create(GTKPPICONFIG(Widget)->SignLanguage), Label);
	}
	
	Label = gtk_label_new("About");
	gtk_notebook_append_page(GTK_NOTEBOOK(Widget),
			About_Create(GTKPPICONFIG(Widget)->About), Label);

	gtk_widget_set_usize(Widget, 470, 300);
	gtk_widget_show(Widget);
		
	return Widget;
}

