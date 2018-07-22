#ifndef __GENERAL_H__
#define __GENERAL_H__
/*
 * Pseudo-Physical Input Control Panel
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */

/*
 * GeneralFrame
 */
typedef struct
{
	GtkWidget	*Frame;
	GtkWidget	*Table;
	GtkWidget	*ComPort;
	GtkWidget	*MotionSensitivity;
	GtkWidget	*FingerSensitivity;
	
} TGeneral;

GtkWidget	*General_Create(TGeneral *General);

#endif
