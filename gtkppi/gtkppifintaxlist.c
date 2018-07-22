//
// PPI FinTax List GTK Widget
// Copyright 1997-1999 (c) Leprechaun Software. All Rights Reserved.
//
#include <gtk/gtk.h>
#include "gtkppifintaxlist.h"

static void gtk_ppi_fintaxlist_class_init(GtkPPIFinTaxListClass *klass);
static void gtk_ppi_fintaxlist_init(GtkPPIFinTaxList *FinTax);
void gtk_ppi_fintaxlist_add(GtkWidget *Widget, gpointer Data);
void gtk_ppi_fintaxlist_remove(GtkWidget *Widget, gpointer Data);
void gtk_ppi_fintaxlist_load(GtkWidget *Widget, gpointer Data);
void gtk_ppi_fintaxlist_save(GtkWidget *Widget, gpointer Data);
void add_ok_callback(GtkButton *Button);
void create_fintaxedit_window();

//
// gtk->ppi->fintaxlist->get_type
//
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

//
// gtk->ppi->fintaxlist->class_init
//
static void gtk_ppi_fintaxlist_class_init(GtkPPIFinTaxListClass *Class)
{
}

//
// gtk->ppi->fintaxlist->init
//
static void gtk_ppi_fintaxlist_init(GtkPPIFinTaxList *FinTax)
{
	GtkWidget	*Label;

	gtk_box_set_spacing(GTK_BOX(FinTax), 4);

	FinTax->CList = gtk_clist_new(2);
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
	
	// Horizontal Button Box
	FinTax->ButtonBox = gtk_hbutton_box_new();
	gtk_button_box_set_layout(GTK_BUTTON_BOX(FinTax->ButtonBox), GTK_BUTTONBOX_END);
	gtk_button_box_set_spacing(GTK_BUTTON_BOX(FinTax->ButtonBox), 4);
	gtk_box_pack_start(GTK_VBOX(FinTax), FinTax->ButtonBox, FALSE, TRUE, 2);
	gtk_widget_show(FinTax->ButtonBox);
	
	// Add Template
	FinTax->Add = gtk_button_new_with_label("Add...");
	gtk_signal_connect(GTK_OBJECT(FinTax->Add), "clicked",
			GTK_SIGNAL_FUNC(gtk_ppi_fintaxlist_add),
			FinTax);
	gtk_container_add(GTK_CONTAINER(FinTax->ButtonBox), FinTax->Add);
	gtk_widget_set_sensitive(FinTax->Add, TRUE);
	gtk_widget_show(FinTax->Add);

	// Remove Template
	FinTax->Remove = gtk_button_new_with_label("Remove");
	gtk_signal_connect(GTK_OBJECT(FinTax->Remove), "clicked",
			GTK_SIGNAL_FUNC(gtk_ppi_fintaxlist_remove),
			FinTax);
	gtk_container_add(GTK_CONTAINER(FinTax->ButtonBox), FinTax->Remove);
	gtk_widget_set_sensitive(FinTax->Remove, FALSE);
	gtk_widget_show(FinTax->Remove);
	
	// Load Template
	FinTax->Load = gtk_button_new_with_label("Load...");
	gtk_signal_connect(GTK_OBJECT(FinTax->Load), "clicked",
			GTK_SIGNAL_FUNC(gtk_ppi_fintaxlist_load),
			FinTax);
	gtk_container_add(GTK_CONTAINER(FinTax->ButtonBox), FinTax->Load);
	gtk_widget_set_sensitive(FinTax->Load, TRUE);
	gtk_widget_show(FinTax->Load);

	// Save Template
	FinTax->Save = gtk_button_new_with_label("Save As...");
	gtk_signal_connect(GTK_OBJECT(FinTax->Save), "clicked",
			GTK_SIGNAL_FUNC(gtk_ppi_fintaxlist_save),
			FinTax);
	gtk_container_add(GTK_CONTAINER(FinTax->ButtonBox), FinTax->Save);
	gtk_widget_set_sensitive(FinTax->Save, FALSE);
	gtk_widget_show(FinTax->Save);
}

//
// gtk->ppi->fintaxlist->new
//
GtkWidget *gtk_ppi_fintaxlist_new()
{
	return GTK_WIDGET(gtk_type_new(gtk_ppi_fintaxlist_get_type()));
}

//
// gtk->ppi->fintaxlist->add
//
void gtk_ppi_fintaxlist_add(GtkWidget *Widget, gpointer Data)
{
/*	GtkWidget *Window;
	GtkWidget *Box1, *Box2;
	GtkWidget *Button;
	GtkWidget *Frame;
	GtkWidget *Separator;

	Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//	gtk_container_set_border_width(GTK_CONTAINER(Window), 4);
	gtk_window_set_title(GTK_WINDOW(Window), "Add New FinTax");
	gtk_widget_show(Window);

	Box1 = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(Window), Box1);

	Frame = gtk_frame_new("Add...");
	gtk_box_pack_start(GTK_BOX(Box1), Frame, TRUE, TRUE, 0);
	
	Box2 = gtk_vbox_new(FALSE, 4);
	gtk_container_set_border_width(GTK_CONTAINER(Box2), 4);
	gtk_container_add(GTK_CONTAINER(Frame), Box2);
	
	Button = gtk_radio_button_new_with_label(NULL, "New");
	gtk_box_pack_start(GTK_BOX(Box2), Button, TRUE, TRUE, 0);

	Button = gtk_radio_button_new_with_label(
			gtk_radio_button_group(GTK_RADIO_BUTTON(Button)),
			"Import");
	gtk_box_pack_start(GTK_BOX(Box2), Button, TRUE, TRUE, 0);

	Separator = gtk_hseparator_new();
	gtk_box_pack_start(GTK_BOX(Box1), Separator, FALSE, TRUE, 0);

	Box2 = gtk_hbox_new(TRUE, 4);
	gtk_container_set_border_widget(GTK_CONTAINER(Box2), 4);
	gtk_box_pack_start(GTK_BOX(Box1), Box2, TRUE, TRUE, 0);

	Button = gtk_button_new_with_label("Ok");
	gtk_signal_connect_object(GTK_OBJECT(Button), "clicked",
			GTK_SIGNAL_FUNC(add_ok_callback),
			GTK_OBJECT(Window));
	gtk_box_pack_start(GTK_BOX(Box2), Button, TRUE, TRUE, 0);
	GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
	gtk_widget_grab_default(Button);

	Button = gtk_button_new_with_label("Cancel");
	gtk_signal_connect_object(GTK_OBJECT(Button), "clicked",
			GTK_SIGNAL_FUNC(gtk_widget_destroy),
			GTK_OBJECT(Window));
	gtk_box_pack_start(GTK_BOX(Box2), Button, TRUE, TRUE, 0);

	gtk_widget_show_all(Window);*/
	create_fintaxedit_window();	
}

//
// gtk->ppi->fintaxlist->remove
//
void gtk_ppi_fintaxlist_remove(GtkWidget *Widget, gpointer Data)
{
}

//
// gtk->ppi->fintaxlist->load
//
void gtk_ppi_fintaxlist_load(GtkWidget *Widget, gpointer Data)
{
}

//
// gtk->ppi->fintaxlist->save
//
void gtk_ppi_fintaxlist_save(GtkWidget *Widget, gpointer Data)
{
}

//
// Add callback
//
void add_ok_callback(GtkButton *Button)
{
}

//
// Create fintax edit window
//
void create_fintaxedit_window()
{
	GtkWidget *Window;
	GtkWidget *Box1, *Box2, *Box3, *Box4;
	GtkWidget *Button;
	GtkWidget *FinTaxView;
	GtkWidget *Frame;
	GtkWidget *Separator;
	GtkWidget *OptionMenu;
	GtkWidget *Text;
	GtkWidget *Menu, *MenuItem;
	GtkWidget *ButtonBox;
	
	Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(Window), "FinTax");
//	gtk_container_set_border_width(GTK_CONTAINER(Window), 4);
	
	Box1 = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(Window), Box1);
	
	Box2 = gtk_hbox_new(TRUE, 4);
	gtk_container_set_border_width(GTK_CONTAINER(Box2), 4);
	gtk_box_pack_start(GTK_BOX(Box1), Box2, TRUE, TRUE, 0);
	
	FinTaxView = gtk_ppi_fintaxview_new();
	gtk_box_pack_start(GTK_BOX(Box2), FinTaxView, TRUE, TRUE, 0);
	
	Box3 = gtk_vbox_new(FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Box2), Box3, TRUE, TRUE, 0);
	
	// Class
	Frame = gtk_frame_new("Class");
	gtk_box_pack_start(GTK_BOX(Box3), Frame, TRUE, TRUE, 0);

	Box4 = gtk_vbox_new(FALSE, 0);
	gtk_container_set_border_width(GTK_CONTAINER(Box4), 4);
	gtk_container_add(GTK_CONTAINER(Frame), Box4);

	// *******************
	// Menu to be compiled from system database
	// *******************
	Menu = gtk_menu_new();
	MenuItem = gtk_menu_item_new_with_label("Operating System");
	gtk_menu_append(GTK_MENU(Menu), MenuItem);
	MenuItem = gtk_menu_item_new_with_label("Netscape");
	gtk_menu_append(GTK_MENU(Menu), MenuItem);
	MenuItem = gtk_menu_item_new_with_label("French");
	gtk_menu_append(GTK_MENU(Menu), MenuItem);
	MenuItem = gtk_menu_item_new_with_label("English");
	gtk_menu_append(GTK_MENU(Menu), MenuItem);
	MenuItem = gtk_menu_item_new_with_label("Spanish");
	gtk_menu_append(GTK_MENU(Menu), MenuItem);
	MenuItem = gtk_menu_item_new_with_label("E'sparanto");
	gtk_menu_append(GTK_MENU(Menu), MenuItem);
	
	OptionMenu = gtk_option_menu_new();
	gtk_option_menu_set_menu(GTK_OPTION_MENU(OptionMenu), Menu);
	gtk_box_pack_start(GTK_BOX(Box4), OptionMenu, TRUE, TRUE, 0);

	ButtonBox = gtk_hbutton_box_new();
	gtk_button_box_set_layout(GTK_BUTTON_BOX(ButtonBox), GTK_BUTTONBOX_END);
	gtk_button_box_set_spacing(GTK_BUTTON_BOX(ButtonBox), 4);
	gtk_box_pack_start(GTK_BOX(Box4), ButtonBox, TRUE, TRUE, 0);

	Button = gtk_button_new_with_label("New...");
	gtk_container_add(GTK_CONTAINER(ButtonBox), Button);

	// Sub-Class
	Frame = gtk_frame_new("Subclass");
	gtk_box_pack_start(GTK_BOX(Box3), Frame, TRUE, TRUE, 0);

	Box4 = gtk_vbox_new(FALSE, 0);
	gtk_container_set_border_width(GTK_CONTAINER(Box4), 4);
	gtk_container_add(GTK_CONTAINER(Frame), Box4);

	// ******************
	// Menu to be compiled with sub-classes applicable to that class
	// (ie. a french one will not contain mouse fintax)
	// ******************
	Menu = gtk_menu_new();
	MenuItem = gtk_menu_item_new_with_label("Mouse");
	gtk_menu_append(GTK_MENU(Menu), MenuItem);
	MenuItem = gtk_menu_item_new_with_label("Keyboard");
	gtk_menu_append(GTK_MENU(Menu), MenuItem);
	MenuItem = gtk_menu_item_new_with_label("Sign-Language");
	gtk_menu_append(GTK_MENU(Menu), MenuItem);
	
	OptionMenu = gtk_option_menu_new();
	gtk_option_menu_set_menu(GTK_OPTION_MENU(OptionMenu), Menu);
	gtk_box_pack_start(GTK_BOX(Box4), OptionMenu, TRUE, TRUE, 0);
	
	// Description
	Frame = gtk_frame_new("Description");
	gtk_box_pack_start(GTK_BOX(Box3), Frame, TRUE, TRUE, 0);
	
	Box4 = gtk_vbox_new(FALSE, 0);
	gtk_container_set_border_width(GTK_CONTAINER(Box4), 4);
	gtk_container_add(GTK_CONTAINER(Frame), Box4);

	OptionMenu = gtk_option_menu_new();
	gtk_box_pack_start(GTK_BOX(Box4), OptionMenu, TRUE, TRUE, 0);

	ButtonBox = gtk_hbutton_box_new();
	gtk_button_box_set_layout(GTK_BUTTON_BOX(ButtonBox), GTK_BUTTONBOX_END);
	gtk_button_box_set_spacing(GTK_BUTTON_BOX(ButtonBox), 4);
	gtk_box_pack_start(GTK_BOX(Box4), ButtonBox, TRUE, TRUE, 0);
	
	Button = gtk_button_new_with_label("New...");
	gtk_container_add(GTK_CONTAINER(ButtonBox), Button);
	
	Separator = gtk_hseparator_new();
	gtk_box_pack_start(GTK_BOX(Box1), Separator, FALSE, TRUE, 0);
	
	Box2 = gtk_hbox_new(FALSE, 4);
	gtk_container_set_border_width(GTK_CONTAINER(Box2), 4);
	gtk_box_pack_start(GTK_BOX(Box1), Box2, FALSE, TRUE, 0);
			
	Button = gtk_button_new_with_label("Ok");
	gtk_signal_connect_object(GTK_OBJECT(Button), "clicked",
			GTK_SIGNAL_FUNC(add_ok_callback),
			GTK_OBJECT(Window));
	gtk_box_pack_start(GTK_BOX(Box2), Button, TRUE, TRUE, 0);
	GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
	gtk_widget_grab_default(Button);

	Button = gtk_button_new_with_label("Cancel");
	gtk_signal_connect_object(GTK_OBJECT(Button), "clicked",
			GTK_SIGNAL_FUNC(gtk_widget_destroy),
			GTK_OBJECT(Window));
	gtk_box_pack_start(GTK_BOX(Box2), Button, TRUE, TRUE, 0);

	gtk_widget_show_all(Window);
}
