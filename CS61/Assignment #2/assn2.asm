; ============================================================================
; Name: Do, Kevin
; Login: kdo009 (kdo009@cs.ucr.edu)
; Assignment: assn2
; Lab Section: 24
; TA: Wojtek Karas
;
; I hereby certify that the contents of this file are ENTIRELY my own original
; work.
; ============================================================================
; ----------------------------------------------------------------------------
; Subroutine: SUB_MAIN_30000
; Input: None.
; Postcondition: None.
; Return Value: None.
; ----------------------------------------------------------------------------
		.ORIG x3000		;start at memory address x3000
;-----------------------------------------------------------------------------
;Instruction Block for SUB_MAIN_30000
;-----------------------------------------------------------------------------
		TRAP x20			
		LD R3, CONV_TO_DEC	;convert from char to number
		ADD R0, R0, R3

		ADD R1, R0, #0		;store first value in R1
		


		TRAP x20
		LD R3, CONV_TO_DEC	;convert from char to number
		ADD R0, R0, R3		

		ADD R2, R0, #0		;store second value into R2



		NOT R2, R2		;convert R2 into negative
		ADD R2, R2, #1



		ADD R0, R1, R2		;put total into R0 to print



		BRn PRINT_NEGATIVE	;check if R0 is negative 
							;to print 2 characters
		BRnzp PRINT

PRINT_NEGATIVE	ADD R4, R0, #0
		LD R0, NEGATIVE
		TRAP x21
		ADD R0, R4, #0		;print out a minus sign
		NOT R0, R0			;then stores value back into R0
		ADD R0, R0, #1


PRINT		LD R3, CONV_TO_CHAR	;convert R0 into a character to print
		ADD R0, R0, R3
		
		TRAP x21		;print result		
		
		HALT
;-----------------------------------------------------------------------------
;Data Block for SUB_MAIN_3000
;-----------------------------------------------------------------------------

NEGATIVE	.FILL '-'
CONV_TO_CHAR	.FILL #48
CONV_TO_DEC	.FILL #-48

;-----------------------------------------------------------------------------
;End Subroutine: SUB_MAIN_3000
;-----------------------------------------------------------------------------
		.END 		;stop reading source code





