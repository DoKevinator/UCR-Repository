; ============================================================================
; Name: Do, Kevin
; Login: kdo009 (kdo009@cs.ucr.edu)
; Assignment: assn4
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
                .ORIG x3000		            ;start at memory address x3000
;-----------------------------------------------------------------------------
;Instruction Block for SUB_MAIN_30000
;-----------------------------------------------------------------------------
                BR START

RESET           LEA R0, ERROR
                PUTS
                AND R0, R0, #0
                AND R1, R1, #0
                AND R2, R2, #0
                AND R3, R3, #0
                AND R4, R4, #0
                AND R5, R5, #0
                AND R6, R6, #0
 
START                
                LD R2, NEWLINE_SIG          ;R3 <- #-10
                
                LEA R0, MSG                 ;disp user prompt
                PUTS
                AND R0, R0, #0
                AND R1, R1, #0
                
INPUTLOOP       TRAP x20                    ;R0 <- user input
                TRAP x21                    ;disp user input
                
                
                
                LD R3, POSITIVE_SIG
                ADD R4, R0, R3              ;if '+' sign, ignore and get input
                BRz INPUTLOOP
                
                LD R3, NEGATIVE_SIG         ;if '-' sign, set R5 1 for flag
                ADD R4, R0, R3
                BRz NEG_FLAG
                BRnzp else_FLAG

NEG_FLAG        ADD R5, R5, #1              ;after '-', get new input
                BRnzp INPUTLOOP
                
else_FLAG        

                ADD R3, R0, R2              ;exit on new line
                BRz ENDPROG
                
                
                LD R3, UPPER_VALID          
                ADD R4, R0, R3              ;R4 = R0 + #-58
                BRp RESET                   ;if > 0, reset program
                
                AND R4, R4, #0
                
                LD R3, LOWER_VALID
                ADD R4, R0, R3              ;R4 = R0 + #-47
                BRn RESET                   ;if < 0, reset program
                

                LD R3, CHAR_CONV            ;R3 cast to DEC
                ADD R0, R0, R3
                
                ADD R1, R1, R0
                
                LD R4, COUNTER              ;R4 <- counter
                ADD R6, R1, #0              ;R6 <- R1
                
                ;ADD R1, R0, #0
                
TIMES_10_LOOP   ADD R1, R1, R6              ;R1 += R6
                ADD R4, R4, #-1             ;COUNTER--
                BRp TIMES_10_LOOP           ;if counter > 0, TIMES_10_LOOP

                
                BR INPUTLOOP                ;if R0 != 0, INPUTLOOP
                

                
ENDPROG         
                ADD R1, R6, #0
                ADD R5, R5, #0               ;if R5 is 1, change R1 to neg
                BRp CHANGE_NEG
                BRnzp NO_CHANGE_NEG
CHANGE_NEG      NOT R1, R1
                ADD R1, R1, #1              ;else, end program
 
NO_CHANGE_NEG   HALT
;-----------------------------------------------------------------------------
;Data Block for SUB_MAIN_4000
;-----------------------------------------------------------------------------
COUNTER         .FILL #9
CHAR_CONV       .FILL #-48
NEWLINE_SIG     .FILL #-10
NEGATIVE_SIG    .FILL #-45
POSITIVE_SIG    .FILL #-43
UPPER_VALID     .FILL #-58
LOWER_VALID     .FILL #-48
MSG             .STRINGZ "Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"
ERROR           .STRINGZ "Error: invalid input.\n"            
;-----------------------------------------------------------------------------
;End Subroutine: SUB_MAIN_4000
;-----------------------------------------------------------------------------
                .END 		        ;stop reading source code

