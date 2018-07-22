/*
 * Pseudo-Physical Input
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */
#include <gtk/gtk.h>
#include "ctlpanel.h"
#include "mainwindow.h"

/*
 * main
 */
int main(int argc, char *argv[])
{
	int show_version = FALSE;
	int show_help = FALSE;
	int i;
	
	gtk_set_locale();
	gtk_init(&argc, &argv);

	for(i = 1; i < argc; i++)
	{
		if((strcmp(argv[i], "--version") == 0) ||
			(strcmp(argv[i], "-v") == 0))
		{
			show_version = TRUE;
		}
		else if((strcmp(argv[i], "--help") == 0) ||
			(strcmp(argv[i], "-h") == 0))
		{
			show_help = TRUE;
		}
		else if(argv[i][0] == '-')
		{
			show_help = TRUE;
		}
	}

	if(show_version)
		g_print("Pseudo-Physical Input Control Panel " PPI_VERSION "\n");

	if(show_help)
	{
		g_print("\007Usage: ctlpanel [option ...]\n");
		g_print("Valid options are:\n");
		g_print(" -h --help               Output this help.\n");
		g_print(" -v --version            Output version info.\n");
		g_print(" --display <display>     Use the designated X display.\n\n");
	}

	if(show_help || show_version)
		exit(0);
	
	MainWindow_Create();
	
	gtk_main();
	return 0;
};
