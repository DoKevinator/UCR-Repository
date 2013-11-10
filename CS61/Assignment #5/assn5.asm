; ============================================================================
; Name: Do, Kevin
; Login: kdo009 (kdo009@cs.ucr.edu)
; Assignment: assn5
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
                    LD R0, SUB_GET_INPUT        ;get input 1
                    JSRR R0
                    
                    ADD R1, R6, #0              ;shift value to R1
                    
                    LD R0, SUB_GET_INPUT        ;get input 2
                    JSRR R0
                    
                    ADD R2, R6, #0              ;shift value to R2

                    ;-------------------
                                                ;make both nums positive
                                                ;and set flags for result sign
                    ADD R1, R1, #0
                    BRn NEG_SIGN1               ;if R1, is negative
                    BR POS_SIGN1                ;if R1 is positive
NEG_SIGN1           LD R3, SIGN
                    ADD R3, R3, #-1             ;subtract one to SIGN
                    ST R3, SIGN

                    NOT R1, R1
                    ADD R1, R1, #1              ;change R1 to positive
                    LD R6, FIRSTOP 				;set first operator sign flag
                    ADD R6, R6, #1
                    ST R6, FIRSTOP
                    BR NEXT

POS_SIGN1           LD R3, SIGN
                    ADD R3, R3, #1              ;add one to SIGN
                    ST R3, SIGN

NEXT                ADD R2, R2, #0
                    BRn NEG_SIGN2               ;if R2, is negative
                    BR POS_SIGN2                ;if R2 is positive
NEG_SIGN2           LD R3, SIGN
                    ADD R3, R3, #1              ;add one to SIGN
                    ST R3, SIGN

                    NOT R2, R2
                    ADD R2, R2, #1              ;change R2 to positive
                    LD R6, SECONDOP 				;set second operator sign flag
                    ADD R6, R6, #1
                    ST R6, SECONDOP
                    BR DONE

POS_SIGN2           LD R3, SIGN
                    ADD R3, R3, #-1             ;subtract one to SIGN
                    ST R3, SIGN

DONE

                    ;-------------------
                                                
                    ;-------------------

                    NOT R4, R2
                    ADD R4, R4, #1              ;make second number negative
                    
                    ADD R3, R1, R4
                    BRn FIRST_IS_SMALLER        ;R1 is smaller than R2
                    BR  ELSE                    ;else, R1 is bigger or equal

FIRST_IS_SMALLER    AND R3, R3, #0
					ADD R5, R5, R1
LOOP1               ADD R3, R3, R2
                    BRp CONT1                   ;if somehow the multiplication
                    LD R3, OVER_UNDER_FLAG      ;goes negative, we know there is
                    ADD R3, R3, #1              ;an over or under flow, so exit
                    ST R3, OVER_UNDER_FLAG      ;and set flag
                    BR DONE_MULT

CONT1               ADD R5, R5, #-1             ;add R1 to itself R2 times
                    BRnp LOOP1
                    BR DONE_MULT
                    
ELSE                AND R3, R3, #0
					ADD R5, R5, R2
LOOP2               ADD R3, R3, R1              ;add R2 to itself R1 times
                    BRzp CONT2
                    LD R3, OVER_UNDER_FLAG      ;if somehow the multiplication
                    ADD R3, R3, #1              ;goes negative, we know there is
                    ST R3, OVER_UNDER_FLAG      ;an over or under flow, so exit
                    BR DONE_MULT                ;and set flag

CONT2               ADD R5, R5, #-1
                    BRnp LOOP2

DONE_MULT
                    ;------------------

                    LD R4, OVER_UNDER_FLAG      ;R4 <- overflow signal
                    BRz NOFLOW                  ;if signal is 0, skip all
                    LD R4, SIGN                 ;R4 <- sign signal
                    BRnp UNDERFL                ;if sign != 0, UNDERFLOW
                    LEA R0, OVERFLOW            ;if sign == 0, OVERFLOW
                    PUTS
                    BR FINISH
UNDERFL             LEA R0, UNDERFLOW            
                    PUTS
                    BR FINISH
NOFLOW
					LD R4, SIGN
					LD R5, FIRSTOP
					LD R6, SECONDOP
                    
                    LD R0, SUB_PRINT 			;print the result.
            		JSRR R0



FINISH              HALT
;-----------------------------------------------------------------------------
;Data Block for SUB_MAIN_3000
;-----------------------------------------------------------------------------
SIGN                .FILL #0
OVER_UNDER_FLAG     .FILL #0
OVERFLOW            .STRINGZ "Woes! Overflows!\n"
UNDERFLOW           .STRINGZ "Woahs! Underflows!\n"
FIRSTOP 			.FILL #0
SECONDOP 			.FILL #0

SUB_GET_INPUT       .FILL x3200  
SUB_PRINT           .FILL x3400          
;-----------------------------------------------------------------------------
;End Subroutine: SUB_MAIN_3000
;-----------------------------------------------------------------------------


; ----------------------------------------------------------------------------
; Subroutine: SUB_GET_INPUT
; Input: None.
; Postcondition: Gets input from user and stores value into Register
; Return Value: None.
; ----------------------------------------------------------------------------
                .ORIG x3200		            ;start at memory address x3200
;-----------------------------------------------------------------------------
;Instruction Block for SUB_MAIN_30000
;-----------------------------------------------------------------------------
                ST R0, R0_BACKUP
                ST R1, R1_BACKUP
                ST R2, R2_BACKUP
                ST R3, R3_BACKUP
                ST R4, R4_BACKUP
                ST R5, R5_BACKUP
                ST R7, R7_BACKUP
                
                
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

                
ENDPROG         ADD R5, R5, #0               ;if R5 is 1, change R6 to neg
                BRp CHANGE_NEG
                BRnzp NO_CHANGE_NEG
CHANGE_NEG      NOT R6, R6
                ADD R6, R6, #1              ;else, end program
 
NO_CHANGE_NEG   LD R0, R0_BACKUP
                LD R1, R1_BACKUP
                LD R2, R2_BACKUP
                LD R3, R3_BACKUP
                LD R4, R4_BACKUP
                LD R5, R5_BACKUP
                LD R7, R7_BACKUP
                
                RET
;-----------------------------------------------------------------------------
;Data Block for SUB_GET_INPUT
;-----------------------------------------------------------------------------
R0_BACKUP       .FILL #0
R1_BACKUP       .FILL #0
R2_BACKUP       .FILL #0
R3_BACKUP       .FILL #0
R4_BACKUP       .FILL #0
R5_BACKUP       .FILL #0
R7_BACKUP       .FILL #0

COUNTER         .FILL #9
CHAR_CONV       .FILL #-48
NEWLINE_SIG     .FILL #-10
NEGATIVE_SIG    .FILL #-45
POSITIVE_SIG    .FILL #-43
UPPER_VALID     .FILL #-58
LOWER_VALID     .FILL #-48
MSG             .STRINGZ "Input a number, followed by ENTER: "
ERROR           .STRINGZ "\nInvalid input. "            
;-----------------------------------------------------------------------------
;End Subroutine: SUB_GET_INPUT
;-----------------------------------------------------------------------------




; ----------------------------------------------------------------------------
; Subroutine: SUB_PRINT
; Input: None.
; Postcondition: Prints the result to the console
; Return Value: None.
; ----------------------------------------------------------------------------
                .ORIG x3400                 ;start at memory address x3400
;-----------------------------------------------------------------------------
;Instruction Block for SUB_PRINT
;-----------------------------------------------------------------------------
                
                ST R4, RESULTSIGN				;backup all used registers
                ST R5, FIRSTOP_SIGN
                ST R6, SECONDOP_SIGN
                ST R7, R7_PRINT_BACK


                LD R4, FIRSTOP_SIGN
                BRp FIRSTNEG
                BR FIRSTPOS
FIRSTNEG		LD R0, MINUSSIGN
 				TRAP x21
 				BR FNSH
FIRSTPOS		LD R0, PLUSSIGN
 				TRAP x21
FNSH
                
           		
           		;print first operand of equation
                ;----

           		LD R6, TEN_K
				ADD R5, R1, R6 					;if number is in 10k range
				BRzp TENK1

				LD R6, THOUSAND
				ADD R5, R1, R6 					;if number is in 1k range
				BRzp THOUS1

				LD R6, HUNDRED
				ADD R5, R1, R6 					;if number is in 100 range
				BRzp HUND1

				LD R6, TEN
				ADD R5, R1, R6 					;if number is in 10 range
				BRzp TENL1
 					
				BR ONEL1 						;if number is in 1 range


TENK1 			LD R0, COUNT
				LD R6, TEN_K
				BR TMP11
TENKLOOP1 		ADD R0, R0, #1 					;algorithm for getting 10k place
				ADD R1, R1, R6
TMP11 			ADD R5, R1, R6
				BRzp TENKLOOP1

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


THOUS1 			LD R0, COUNT
				LD R6, THOUSAND
				BR TMP21
THOUSLOOP1  	ADD R0, R0, #1 					;algorithm for getting 1k place
				ADD R1, R1, R6
TMP21			ADD R5, R1, R6
				BRzp THOUSLOOP1

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


HUND1 			LD R0, COUNT
				LD R6, HUNDRED
				BR TMP31
HUNDLOOP1 		ADD R0, R0, #1 					;algorithm for getting 100 place
				ADD R1, R1, R6
TMP31			ADD R5, R1, R6
				BRzp HUNDLOOP1

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


TENL1  			LD R0, COUNT	
				LD R6, TEN
				BR TMP41
TENLOOP1 	 	ADD R0, R0, #1 					;algorithm for getting 10 place
				ADD R1, R1, R6
TMP41 			ADD R5, R1, R6
				BRzp TENLOOP1

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


ONEL1  			LD R0, COUNT	
				LD R6, ONE
				BR TMP51
ONELOOP1 	 	ADD R0, R0, #1
				ADD R1, R1, R6 					;algorithm for getting 1's place
TMP51 			ADD R5, R1, R6
				BRzp ONELOOP1		

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21

				;----

				LEA R0, PRINTMULT 				;prints " * " inbetween numbers
				PUTS

				LD R4, SECONDOP_SIGN
                BRp SECONDNEG
                BR SECONDPOS
SECONDNEG		LD R0, MINUSSIGN
 				TRAP x21
 				BR FNSH2
SECONDPOS		LD R0, PLUSSIGN
 				TRAP x21
FNSH2

				;print second operand of equation
				;----

				LD R6, TEN_K
				ADD R5, R2, R6 					;if number is in 10k range
				BRzp TENK2

				LD R6, THOUSAND
				ADD R5, R2, R6 					;if number is in 1k range
				BRzp THOUS2

				LD R6, HUNDRED
				ADD R5, R2, R6 					;if number is in 100 range
				BRzp HUND2

				LD R6, TEN
				ADD R5, R2, R6 					;if number is in 10 range
				BRzp TENL2
 					
				BR ONEL2 						;if number is in 1 range


TENK2 			LD R0, COUNT
				LD R6, TEN_K
				BR TMP12
TENKLOOP2 		ADD R0, R0, #1 					;algorithm for getting 10k place
				ADD R2, R2, R6
TMP12 			ADD R5, R2, R6
				BRzp TENKLOOP2

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


THOUS2 			LD R0, COUNT
				LD R6, THOUSAND
				BR TMP22
THOUSLOOP2  	ADD R0, R0, #1 					;algorithm for getting 1k place
				ADD R2, R2, R6
TMP22			ADD R5, R2, R6
				BRzp THOUSLOOP2

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


HUND2 			LD R0, COUNT
				LD R6, HUNDRED
				BR TMP32
HUNDLOOP2 		ADD R0, R0, #1 					;algorithm for getting 100 place
				ADD R2, R2, R6
TMP32			ADD R5, R2, R6
				BRzp HUNDLOOP2

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


TENL2  			LD R0, COUNT	
				LD R6, TEN
				BR TMP42
TENLOOP2 	 	ADD R0, R0, #1 					;algorithm for getting 10 place
				ADD R2, R2, R6
TMP42 			ADD R5, R2, R6
				BRzp TENLOOP2

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


ONEL2  			LD R0, COUNT	
				LD R6, ONE
				BR TMP52
ONELOOP2 	 	ADD R0, R0, #1
				ADD R2, R2, R6 					;algorithm for getting 1's place
TMP52 			ADD R5, R2, R6
				BRzp ONELOOP2		

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21

				;----


				LEA R0, PRINTEQUAL 				;print " = " sign
				PUTS

				LD R4, RESULTSIGN
				ADD R4, R4, #0
				BRnp PRINTNEG
 				LD R0, PLUSSIGN 				;print neg or pos of result
 				TRAP x21
 				BR PRINTPOS

PRINTNEG 		LD R0, MINUSSIGN
				TRAP x21
PRINTPOS

				;print result of the two operands 
				;----

				LD R6, TEN_K
				ADD R5, R3, R6 					;if number is in 10k range
				BRzp TENK3

				LD R6, THOUSAND
				ADD R5, R3, R6 					;if number is in 1k range
				BRzp THOUS3

				LD R6, HUNDRED
				ADD R5, R3, R6 					;if number is in 100 range
				BRzp HUND3

				LD R6, TEN
				ADD R5, R3, R6 					;if number is in 10 range
				BRzp TENL3
 					
				BR ONEL3 						;if number is in 1 range


TENK3 			LD R0, COUNT
				LD R6, TEN_K
				BR TMP13
TENKLOOP3 		ADD R0, R0, #1 					;algorithm for getting 10k place
				ADD R3, R3, R6
TMP13 			ADD R5, R3, R6
				BRzp TENKLOOP3

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


THOUS3 			LD R0, COUNT
				LD R6, THOUSAND
				BR TMP23
THOUSLOOP3  	ADD R0, R0, #1 					;algorithm for getting 1k place
				ADD R3, R3, R6
TMP23			ADD R5, R3, R6
				BRzp THOUSLOOP3

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


HUND3 			LD R0, COUNT
				LD R6, HUNDRED
				BR TMP33
HUNDLOOP3 		ADD R0, R0, #1 					;algorithm for getting 100 place
				ADD R3, R3, R6
TMP33			ADD R5, R3, R6
				BRzp HUNDLOOP3

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


TENL3 			LD R0, COUNT	
				LD R6, TEN
				BR TMP43
TENLOOP3 	 	ADD R0, R0, #1 					;algorithm for getting 10 place
				ADD R3, R3, R6
TMP43 			ADD R5, R3, R6
				BRzp TENLOOP3

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21


ONEL3 			LD R0, COUNT	
				LD R6, ONE
				BR TMP53
ONELOOP3 	 	ADD R0, R0, #1
				ADD R3, R3, R6 					;algorithm for getting 1's place
TMP53 			ADD R5, R3, R6
				BRzp ONELOOP3		

				LD R6, TO_CHAR					;print number
				ADD R0, R0, R6
				TRAP x21

				;----



                LD R4, R4_PRINT_BACK			;reload all used registers
                LD R5, R5_PRINT_BACK
                LD R6, R6_PRINT_BACK
                LD R7, R7_PRINT_BACK

                RET
;-----------------------------------------------------------------------------
;Data Block for SUB_PRINT
;-----------------------------------------------------------------------------
TEN_K           .FILL -x2710
THOUSAND        .FILL -x03E8
HUNDRED         .FILL -x0064
TEN             .FILL -x000A
ONE             .FILL -x0001

FIRSTOP_SIGN 	.FILL #0
SECONDOP_SIGN 	.FILL #0
RESULTSIGN 		.FILL #0

COUNT 			.FILL #0
TO_CHAR 		.FILL #48
PRINTMULT 		.STRINGZ " * "
PRINTEQUAL 		.STRINGZ " = "
MINUSSIGN 	 	.FILL #45
PLUSSIGN 		.FILL #43

R4_PRINT_BACK 	.FILL #0
R5_PRINT_BACK 	.FILL #0
R6_PRINT_BACK 	.FILL #0
R7_PRINT_BACK 	.FILL #0
;-----------------------------------------------------------------------------
;End Subroutine: SUB_PRINT
;-----------------------------------------------------------------------------


                .END 		        ;stop reading source code

