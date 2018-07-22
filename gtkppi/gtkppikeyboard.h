#ifndef __GTKPPIKEYBOARD_H__
#define __GTKPPIKEYBOARD_H__
//
// Pseudo-Physical Input Control Panel
// Copyright 1997-1999 (c) Leprechaun Software. All Rights Reserved.
//

//
// Keyboard
//
typedef struct
{
	GtkWidget	*VBox;
	GtkWidget	*Frame;
	GtkWidget	*Table;
	GtkWidget	*Enabler;
	GtkWidget	*RepeatRate;
	GtkWidget	*FinTaxList;

} TKeyboard;

GtkWidget	*Keyboard_Create(TKeyboard *Keyboard);
void		Keyboard_Enabler_Toggle_Update(GtkWidget *Widget, gpointer Data);

#endif
