#ifndef __MOUSE_H__
#define __MOUSE_H__
/*
 * Pseudo-Physical Input Control Panel
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy.  All Rights Reserved.
 */

/*
 * MouseFrame
 */
typedef struct
{
	GtkWidget	*VBox;
	GtkWidget	*Frame;
	GtkWidget	*Table;
	GtkWidget	*Orientation;
	GtkWidget	*FinTaxList;
	GtkWidget	*DblClkSpeed;
	GtkWidget	*Enabler;
	
} TMouse;

GtkWidget	*Mouse_Create(TMouse *Mouse);
void		Mouse_Enabler_Toggle_Update(GtkWidget *Widget, gpointer Data);

#endif
