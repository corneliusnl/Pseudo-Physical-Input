	TITLE		"Pseudo-Physical Input"
	SUBTITLE	"PIC16C77 Microcontroller Operating System"
	
; --------------------------------------------------------------------
; Pseudo-Physical Input
; PIC16C77 Microcontroller Operating System
; Copyright 1997-2000 (c) Jeremiah Cornelius McCarthy. All Rights Reserved.
; --------------------------------------------------------------------

	Processor	16C77
	Radix		DEC

	include		"16Cxx.h"

	ORG	_ResetVector
	goto	Start

	ORG	_IntVector
	goto	Interrupt

; --------------------------------------------------------------------
; Start
; --------------------------------------------------------------------
Start:
	call	GetCommand	; Wait for Command from PC
	btfsc	_rcvOver	;
	goto	$-1		;
	
;
; Initialize A/D Convertor
;
InitADC:
	bsf	_rp0
	clrf	_adcon1
	bcf	_rp0
	movlw	0xC1
	movwf	_adcon0
	return

;
; Get ADC Channel
;

	andlw	0x03
	addwf	_pc1
	retlw	(0xC1 | (0 << 3))	; Channel 0
	retlw	(0xC1 | (1 << 3))	; Channel 1
	retlw	(0xC1 | (2 << 3))	; Channel 2
	retlw	(0xC1 | (3 << 3))	; Channel 3
					; ..Channel 7
	
; --------------------------------------------------------------------
; Get X-Coordinate
; --------------------------------------------------------------------
GetXCoordinate:
	return

; --------------------------------------------------------------------
; Get Y-Coordinate
; --------------------------------------------------------------------
GetYCoordinate:
	return

; --------------------------------------------------------------------
; Get Z-Coordinate
; --------------------------------------------------------------------
GetZCoordinate:
	return

; --------------------------------------------------------------------
; Get Thumb Position
; --------------------------------------------------------------------
GetThumbPosition:
	return

; --------------------------------------------------------------------
; Get Index Finger Position
; --------------------------------------------------------------------
GetIndexFingerPosition:
	return

; --------------------------------------------------------------------
; Get Middle Finger Position
; --------------------------------------------------------------------
GetMiddleFingerPosition:
	return

; --------------------------------------------------------------------
; Get Ring Finger Position
; --------------------------------------------------------------------
GetRingFingerPosition:
	return

; --------------------------------------------------------------------
; Get Pinky Finger Position
; --------------------------------------------------------------------
GetPinkyFingerPosition:
	return
	
; --------------------------------------------------------------------
; Interrupts
; --------------------------------------------------------------------
Interrupt:
	return

	END
