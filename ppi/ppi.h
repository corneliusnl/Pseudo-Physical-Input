#ifndef __PPI_H__
#define __PPI_H__
/*
 * Pseudo-Physical Input Application Programming Interface
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */
#include <ppi/ppimouse.h>
#include <ppi/ppikeyboard.h>
#include <ppi/ppisignlanguage.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * General Functions
 */
void	ppi_Initialize(int comport);
void	ppi_GetHWVersion();
void	ppi_GetSWVersion();
void	ppi_SetHand();
void	ppi_SetFingerSensitivity();
void	ppi_GetFingerSensitivity();
void	ppi_SetMotionSensitivity();
void	ppi_GetMotionSensitivity();

/*
 * Position Functions
 */
void	ppi_GetXCoordinate();
void	ppi_GetYCoordinate();
void	ppi_GetZCoordinate();

/*
 * Finger Functions
 */
void	ppi_GetThumbPosition();
void	ppi_GetIndexFingerPosition();
void	ppi_GetMiddleFingerPosition();
void	ppi_GetRingFingerPosition();
void	ppi_GetPinkyFingerPosition();

#ifdef __cplusplus
}
#endif

#endif

