#ifndef __PPIMOUSE_H__
#define __PPIMOUSE_H__
//
// Pseudo-Physical Input
// Copyright 1997-1999 (c) Leprechaun Software.  All Rights Reserved.
// 

void	ppi_Mouse_Enable(int Enable);
#define PPI_MO_LEFT	1
#define PPI_MO_RIGHT	2
void	ppi_Mouse_SetOrientation(int Orient);
int	ppi_Mouse_GetOrientation();
void	ppi_Mouse_SetDblClkSpeed(int Speed);
int	ppi_Mouse_GetDblClkSpeed();

#endif
