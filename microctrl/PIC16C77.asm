;**********************************************************************
;	Pseudo-Physical Input
;	PIC16C77 Microcontroller Operating System
;	Copyright 1997-1998 (c) Leprechaun Software. All Rights Reserved.
;**********************************************************************
	list      p=16c77             ; list directive to define processor
	#include <p16c77.inc>         ; processor specific variable definitions
	
	__CONFIG   _CP_OFF & _WDT_ON & _BODEN_ON & _PWRTE_ON & _RC_OSC

; '__CONFIG' directive is used to embed configuration data within .asm file.
; The lables following the directive are located in the respective .inc file.
; See respective data sheet for additional information on configuration word.

w_temp        EQU     0x70	; variable used for context saving 
status_temp   EQU     0x71	; variable used for context saving

;**********************************************************************
;	Processor Reset Vector
;**********************************************************************
		ORG     0x000		; Processor reset vector
		
		clrf    PCLATH		; Ensure page bits are claared
  		goto    Main		; Go to beginning of program

;**********************************************************************
;	Interrupt Vector Location
;**********************************************************************
		ORG     0x004		; Interrupt vector location
		
		movwf   w_temp		; Save off current W register contents
		movf	STATUS,w	; Move status register into W register
		movwf	status_temp	; Save off contents of STATUS register

; isr code can go here or be located as a call subroutine elsewhere
		btfss	PIR1, 5		; Check if USART Receive Interrupt
		btfss	PIR1, 4		; Check if USART Transmit Interrupt
		btfss	PIR1, 6		; Check if ADC Complete Interrupt

		movf    status_temp,w	; Retrieve copy of STATUS register
		movwf	STATUS		; Restore pre-isr STATUS register contents
		swapf   w_temp,f
		swapf   w_temp,w	; Restore pre-isr W register contents
		retfie			; Return from interrupt

;**********************************************************************
;	Main Program Entry Point
;**********************************************************************
Main:


;**********************************************************************
;	Select Right Glove
;**********************************************************************
SelectRightGlove:
	bcf	ADCON0, 3
	bcf	ADCON0, 4
	bcf	ADCON0, 5
	return

;**********************************************************************
;	Select Left Glove
;**********************************************************************
SelectLeftGlove:
	bsf	ADCON0, 3
	bcf	ADCON0, 4
	bcf	ADCON0, 5
	return
	
;**********************************************************************
;	Get X-Coordinate
;**********************************************************************
GetXCoordinate:
	return

;**********************************************************************
;	Get Y-Coordinate
;**********************************************************************
GetYCoordinate:
	return

;**********************************************************************
;	Get Z-Coordinate
;**********************************************************************
GetZCoordinate:
	return

;**********************************************************************
;	Get Thumb Position
;**********************************************************************
GetThumbPosition:
	return

;**********************************************************************
;	Get Index Finger Position
;**********************************************************************
GetIndexFingerPosition:
	return

;**********************************************************************
;	Get Middle Finger Position
;**********************************************************************
GetMiddleFingerPosition:
	return

;**********************************************************************
;	Get Ring Finger Position
;**********************************************************************
GetRingFingerPosition:
	return

;**********************************************************************
;	Get Pinky Finger Position
;**********************************************************************
GetPinkyFingerPosition:
	return
		END

