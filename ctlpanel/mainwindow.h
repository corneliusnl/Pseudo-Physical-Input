#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__
/*
 * Pseudo-Physical Input Control Panel
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */
#include <gtk/gtk.h>

void	MainWindow_Create(void);
void	MainWindow_Destroy(void);
void	MainWindow_OnOkClick(GtkWidget *Widget, gpointer Data);
void	MainWindow_OnCancelClick(GtkWidget *Widget, gpointer Data);

/*
 * TMainWindow
 */
typedef struct
{
	GtkWidget	*Config;
	GtkWidget	*Handle;
	GtkWidget	*Table;
	GtkWidget	*ButtonBox;
	GtkWidget	*OkButton;
	GtkWidget	*CancelButton;

} TMainWindow;
extern TMainWindow *MainWindow;

#endif
