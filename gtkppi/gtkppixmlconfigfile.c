/*
 * GTK PPI XML Config File Output
 * Copyright 1999-2000 (c) Jeremiah Cornelius McCarthy. All Rights Reserved.
 */

void gtk_ppi_write_config()
{
	xmlDocPtr doc;
	xmlNodePtr tree, subtree;
	char Filename[256];

	sprintf(Filename, "%s/.ppi/ppicontrolpanelrc", getenv("HOME"));
	
	doc = xmlNewDoc("1.0");
	
	doc->root = xmlNewDocNode(doc, NULL, "Linux Operating System", NULL);
	tree = xmlNewChild(doc->root, NULL, "General Properties", NULL);
	subtree = xmlNewChild(tree, NULL, "Com Port", NULL);
	subtree = xmlNewChild(tree, NULL, "Finger Sensitivity", NULL);
	subtree = xmlNewChild(tree, NULL, "Motion Sensitivity", NULL);
	tree = xmlNewChild(doc->root, NULL, "Keyboard Properties", NULL);
	subtree = xmlNewChild(tree, NULL, "Enabled", "True");
	subtree = xmlNewChild(tree, NULL, "Repeat Rate", NULL);
	tree = xmlNewChild(doc->root, NULL, "Mouse Properties", NULL);
	subtree = xmlNewChild(tree, NULL, "Enabled", "True");
	subtree = xmlNewChild(tree, NULL, "Orientation", "Right");
	subtree = xmlNewChild(tree, NULL, "DblClkSpeed", NULL);
	tree = xmlNewChild(doc->root, NULL, "Sign Language Properties", NULL);
	xmlSaveFile(Filename, doc);
};
