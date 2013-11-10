; ============================================================================
; Name: Do, Kevin
; Login: kdo009 (kdo009@cs.ucr.edu)
; Assignment: assn3
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
                .ORIG x3000		       ;start at memory address x3000
;-----------------------------------------------------------------------------
;Instruction Block for SUB_MAIN_30000
;-----------------------------------------------------------------------------
                LD R1, MASK             ;R1 <- 0111 1111 1111 1111
                NOT R1, R1              ;R1 <- 1000 0000 0000 0000
                LD R2, DATA             ;R2 <- xABCD
                LD R3, COUNTER          ;R3 <- COUNTER
                LD R4, SPACE_COUNT      ;R4 <- SPACE_COUNT

LOOP            AND R0, R2, R1          ;mask first number
                
                BRnp PRINT_ONE           ;if R0 != 0, print 1
                
                LD R0, ZERO             ;prints zero
                TRAP x21
                
                BRnzp PRINT_ZERO        ;else, print 0
                
PRINT_ONE       LD R0, ONE              ;prints one
                TRAP x21
PRINT_ZERO
                
                ADD R2, R2, R2          ;left bitshift the number
                
                ADD R4, R4, #-1         ;SPACE_COUNT--
                BRz PRINT_SPACE         ;if SPACE_COUNT == 0, print space
                BRnzp NO_SPACE          ;else, dont print space
PRINT_SPACE     LD R0, SPACE
                TRAP x21
                LD R4, SPACE_COUNT      ;reset SPACE_COUNT
NO_SPACE        
                
                ADD R3, R3, #-1         ;COUNTER--
                BRp LOOP
                
                HALT
;-----------------------------------------------------------------------------
;Data Block for SUB_MAIN_3000
;-----------------------------------------------------------------------------
DATA            .FILL #169          ;number to output
MASK            .FILL x7FFF         ;has to be x7FFF... because it gives 
                                    ;invalid when i try x8000
COUNTER         .FILL #16           ;prints 16 bits

SPACE_COUNT     .FILL #4            ;print space every 4 bits
SPACE           .FILL #32           ;space character

ONE             .FILL #49           ;1 character
ZERO            .FILL #48           ;0 character
;-----------------------------------------------------------------------------
;End Subroutine: SUB_MAIN_3000
;-----------------------------------------------------------------------------
                .END 		;stop reading source code





