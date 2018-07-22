#ifndef __SIGNLANGUAGE_H__
#define __SIGNLANGUAGE_H__
/*
 * Pseudo-Physical Input Control Panel
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */

/*
 * SignLanguage
 */
typedef struct
{
	GtkWidget	*VBox;
	GtkWidget	*Frame;
	GtkWidget	*Table;
	GtkWidget	*FinTaxList;
	GtkWidget	*Enabler;
	
} TSignLanguage;

GtkWidget	*SignLanguage_Create(TSignLanguage *SignLanguage);
void		SignLanguage_Enabler_Toggle_Update(GtkWidget *Widget, gpointer Data);

#endif
