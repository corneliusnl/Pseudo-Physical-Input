#ifndef __ABOUT_H__
#define __ABOUT_H__
/*
 * Pseudo-Physical Input Control Panel
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */

/*
 * AboutFrame
 */
typedef struct
{
	GtkWidget	*Handle;
	GtkWidget	*VBox;
	GtkWidget	*Pixmap;

} TAbout;

GtkWidget *About_Create(TAbout *About);

#endif
