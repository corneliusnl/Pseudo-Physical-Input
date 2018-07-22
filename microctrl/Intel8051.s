;
; Pseudo-Physical Input BIOS for the Intel 80C51/87C51 Microcontroller
; Copyright 1997-1999 (c) Leprechaun Software. All Rights Reserved.
;
; Todo:
; -Respond to serial interrupt instead
; -Select ADC channel

INPUTSEL	EQU	0x80
; use first two bytes to select low state of desired 4081
LSENSOR		EQU	00000000b
CSENSOR		EQU	00000001b
BSENSOR		EQU	00000010b
LH_THUMB	EQU	00000011b
LH_INDEX	EQU	00000100b
LH_MIDDLE	EQU	00000101b
LH_RING		EQU	00000110b
LH_PINKY	EQU	00000111b
RH_THUMB	EQU	00000000b
RH_INDEX	EQU	00001000b
RH_MIDDLE	EQU	00010000b
RH_RING		EQU	00011000b
RH_PINKY	EQU	00100000b

; ------------------------------------------------
; Program Entry Point
; ------------------------------------------------
	ORG	0h
	
Start:
	AJMP	MainLoop

; ------------------------------------------------
; External Interrupt 0
; ------------------------------------------------
	ORG	03H
	
Int_External0:
	RETI

; ------------------------------------------------
; Timer 0 Interrupt
; ------------------------------------------------
	ORG	0BH
	
Int_Timer0:
	RETI

; ------------------------------------------------
; External Interrupt 1
; ------------------------------------------------
	ORG	013H
	
Int_External1:
	RETI

; ------------------------------------------------
; Timer 1 Interrupt
; ------------------------------------------------
	ORG	01BH
	
Int_Timer1:
	RETI

; ------------------------------------------------
; Serial Port Interrupt
; ------------------------------------------------
	ORG	023H
	
Int_SerialPort:
	; Check For Incoming Commands
	MOV	DPTR, #Jump_Table
	MOV	A, <index number>
	RL	A
	JMP	@A + DPTR

Jump_Table:
	AJMP	MainLoop
	CALL	GetXCoord
	CALL	GetYCoord
	CALL	GetZCoord
	CALL	GetThumbPosition
	CALL	GetIndexFingerPosition
	CALL	GetMiddleFingerPosition
	CALL	GetRingFingerPosition
	CALL	GetPinkyFingerPosition
	CALL	GetVersion
	RETI

; ------------------------------------------------
; Timer 2 Interrupt
; ------------------------------------------------
	ORG	02BH
	
Int_Timer2:
	RETI

; ------------------------------------------------
; Main Loop of Execution
; ------------------------------------------------
MainLoop:

	; Transmit 9-byte Packet
	CALL	GetXCoord
	CALL	GetYCoord
	CALL	GetZCoord
	CALL	GetThumbPosition
	CALL	GetIndexFingerPosition
	CALL	GetMiddleFingerPosition
	CALL	GetRingFingerPosition
	CALL	GetPinkyFingerPosition

; ------------------------------------------------
; Get X Coordinate of Hand
; ------------------------------------------------
GetXCoord:
	RET

; ------------------------------------------------
; Get Y Coordinate of Hand
; ------------------------------------------------
GetYCoord:
	RET

; ------------------------------------------------
; Get Z Coordinate of Hand
; ------------------------------------------------
GetZCoord:
	RET

; ------------------------------------------------
; Get Thumb Position of Hand
; ------------------------------------------------
GetThumbPosition:
	RET

; ------------------------------------------------
; Get Index Finger Position of Hand
; ------------------------------------------------
GetIndexFingerPosition:
	RET

; ------------------------------------------------
; Get Middle Finger Position of Hand
; ------------------------------------------------
GetMiddleFingerPosition:
	RET

; ------------------------------------------------
; Get Ring Finger Position of Hand
; ------------------------------------------------
GetRingFingerPosition:
	RET

; ------------------------------------------------
; Get Pinky Finger Position of Hand
; ------------------------------------------------
GetPinkyFingerPosition:
	RET

; ------------------------------------------------
; Get Version
; ------------------------------------------------
GetVersion:
	RET
	
	END
