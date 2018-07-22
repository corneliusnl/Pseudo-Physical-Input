/*
 * Parse Resource File
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */
#include <stdio.h>
#include "parserc.h"

void ReadPPIRCFile()
{
	FILE	*fp;
	char	Buffer[512];
	char	Section[512];
	char	Label[512];
	char	Value[512];
	char	Single[2];
	
	sprintf(Buffer, "%s/.ppi/ppicontrolpanelrc", getenv("HOME"));

	if((fp = fopen(Buffer, "r")) == NULL)
	{
		printf("Error opening %s\n", Buffer);
		exit(1);
	}

	while(!feof(fp))
	{
		fgets(Buffer, 512, fp);

		if(Buffer[0] != '#' || Buffer[0] != '\n')
		{
			sscanf(Buffer, "%s %[^\n]", Label, Value);
			strip_quote(Value);

			if(!strcmp(Label, "Section"))
			{
				strcpy(Section, Value);
			}
			else if(!strcmp(Label, "EndSection"))
			{
				strcpy(Section, "");
			}

			if(!strcmp(Section, "General"))
			{
				if(!strcmp(Label, "ComPort"))
				{
				}
				else if(!strcmp(Label, "MotionSensitivity"))
				{
				}
				else if(!strcmp(Label, "FingerSensitivity"))
				{
				}
			}
			else if(!strcmp(Section, "Keyboard"))
			{
				if(!strcmp(Label, "Enabled"))
				{
				}
				else if(!strcmp(Label, "RepeatRate"))
				{
				}
			}
			else if(!strcmp(Section, "Mouse"))
			{
				if(!strcmp(Label, "Enabled"))
				{
				}
				else if(!strcmp(Label, "Orientation"))
				{
				}
				else if(!strcmp(Label, "DblClkSpeed"))
				{
				}
			}
			else if(!strcmp(Section, "SignLanguage"))
			{
				if(!strcmp(Label, "Enabled"))
				{
				}
			}

			fread(Single, 1, 1, fp);
		}
				
	}

	fclose(fp);
	
}

void CreatePPIRCFile()
{
	FILE	*fp;
	char	rcFile[256];
	
	sprintf(rcFile, "mkdir -p %s/.ppi", getenv("HOME"));
	system(rcFile);

	sprintf(rcFile, "chmod 700 %s/.ppi", getenv("HOME"));
	system(rcFile);


	sprintf(rcFile, "%s/.ppi/ppicontrolpanelrc", getenv("HOME"));

	if((fp = fopen(rcFile, "w")) == NULL)
	{
		g_print("Error creating %s\n", rcFile);
		exit(1);
	}

	/* General Properties */
	fprintf(fp, "Section \"General\"\n");
	fprintf(fp, "\tCom Port %s\n", );
	fprintf(fp, "\tFinger Sensitivity %d\n", );
	fprintf(fp, "\tMotion Sensitivity %d\n", );
	fprintf(fp, "EndSection \"General\"\n\n");

	/* Keyboard Properties */
	fprintf(fp, "Section \"Keyboard\"\n");
	if(GTK_TOGGLE_BUTTON(Keyboard->Enabled)->active)
		fprintf(fp, "\tEnabled TRUE\n");
	else
		fprintf(fp, "\tEnabled FALSE\n");
	fprintf(fp, "\tRepeat Rate %d\n", );
	fprintf(fp, "End Section \"Keyboard\"\n\n");
	
	/* Mouse Properties */
	fprintf(fp, "Section \"Mouse\"\n");
	if(GTK_TOGGLE_BUTTON(Mouse->Enabler)->active)
		fprintf(fp, "\tEnabled TRUE\n", );
	else
		fprintf(fp, "\tEnabled FALSE\n");
	fprintf(fp, "\tOrientation %s\n", );
	fprintf(fp, "\tDblClk Speed %d\n", );
	fprintf(fp, "EndSection \"Mouse\"\n\n");

	/* Sign Language Properties */
	fprintf(fp, "Section \"Sign Language\"\n");
	fprintf(fp, "\tEnabled %s\n", );
	fprintf(fp, "EndSection \"Sign Language\"\n\n");
}
