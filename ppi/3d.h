#ifndef __3D_H__
#define __3D_H__
/*
 * Pseudo-Physical Input
 * Copyright 1997-1999 (c) Jeremiah Cornelious McCarthy. All Rights Reserved.
 */

typedef struct
{
	float X, Y, Z;
} Vertex;

typedef struct
{
	float X, Y, Z;
	float Magnitude;
} Vector;

typedef struct
{
	float	X, Y, Z;
	float	ThumbPosition;
	float	IndexFingerPosition;
	float	MiddleFingerPosition;
	float	RingFingerPosition;
	float	PinkyFingerPosition;
	Vector	DirVector;
	
} FinTaxPoint;

#endif
