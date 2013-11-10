; ============================================================================
; Name: Do, Kevin
; Login: kdo009 (kdo009@cs.ucr.edu)
; Assignment: assn6
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
                    
                    LD R0, SUB_GET_INPUT        ;get input from user in R6
                    JSRR R0
                    
                    ADD R1, R6, #0              ;R1 <- R6
                    
                    LD R0, DEC_TO_HEX           ;convert R1 to hex in array
                    JSRR R0

                    LD R0, HEX
                    TRAP x21
                    
                    LD R4, TRAVERSE             ;R4 <- #3
                    LD R5, TO_CHAR              ;R5 <- #48

PRINT               LDR R0, R2, #0              ;R0 <- mem[R2]
                    ADD R2, R2, #1              ;R2 += 1

                    LD R6, LETTER_SIGNAL        ;R6 <- #-10
                    ADD R1, R0, R6              ;R1 <- R0 + #-10
                    BRzp TO_LETTER 
                    BR NO_LETTER
TO_LETTER           LD R6, LETTER               ;R6 <- #8
                    ADD R0, R0, R6              ;R0 += #8
NO_LETTER

                    ADD R0, R0, R5              ;convert R0 to char
                    TRAP x21                    ;display R0
                    ADD R4, R4, #-1             ;counter--
                    BRzp PRINT


                    HALT
;-----------------------------------------------------------------------------
;Data Block for SUB_MAIN_3000
;-----------------------------------------------------------------------------
TRAVERSE            .FILL #3
TO_CHAR             .FILL #48
LETTER              .FILL #7
LETTER_SIGNAL       .FILL #-10
HEX                 .FILL #120

SUB_GET_INPUT       .FILL x3200    
DEC_TO_HEX          .FILL x3400   

;-----------------------------------------------------------------------------
;End Subroutine: SUB_MAIN_3000
;-----------------------------------------------------------------------------



; ----------------------------------------------------------------------------
; Subroutine: SUB_GET_INPUT
; Input: None
; Postcondition: Gets input from user and stores value into Register 6
; Return Value: R6
; ----------------------------------------------------------------------------
                .ORIG x3200		            ;start at memory address x3200
;-----------------------------------------------------------------------------
;Instruction Block for SUB_GET_INPUT_30000
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
                
                TRAP x20
                TRAP x21
                LD R1, HASH_SIG             ;checks for # symbol in beginning
                ADD R0, R0, R1
                BRz HASH_ENTERED
                BR RESET
HASH_ENTERED
                AND R0, R0, #0
                AND R1, R1, #0
                
INPUTLOOP       TRAP x20                    ;R0 <- user input
                TRAP x21                    ;disp user input
                

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
HASH_SIG        .FILL #-35
UPPER_VALID     .FILL #-58
LOWER_VALID     .FILL #-48
MSG             .STRINGZ "\nInput a \"#\", followed by a number (0-65535), followed by ENTER: "
ERROR           .STRINGZ "\nInvalid input. "            
;-----------------------------------------------------------------------------
;End Subroutine: SUB_GET_INPUT
;-----------------------------------------------------------------------------




; ----------------------------------------------------------------------------
; Subroutine: SUB_DEC_TO_HEX
; Input: None
; Postcondition: converts decimal to hex
; Return Value: None
; ----------------------------------------------------------------------------
                .ORIG x3400		            ;start at memory address x3200
;-----------------------------------------------------------------------------
;Instruction Block for SUB_DEC_TO_HEX_30000
;-----------------------------------------------------------------------------
                ST R0, R0_BACK              ;backup all registers
                ST R1, R1_BACK
                ST R3, R3_BACK
                ST R4, R4_BACK
                ST R5, R5_BACK
                ST R6, R6_BACK
                ST R7, R7_BACK
                
                LEA R2, HEXARRAY

                ADD R1, R1, #0                  ;value is negative
                BRzp POSITIVE

NEG             LD R0, COUNT
                LD R6, FIRSTHEX
                BR TMP
NEGLOOP         ADD R0, R0, #1                  ;subtract until positive
                ADD R1, R1, R6
TMP             ADD R5, R1, R6
                BRnz NEGLOOP

                BR TMPNEG
NEGLOOP2        ADD R0, R0, #1                  ;subtract until negative
                ADD R1, R1, R6
TMPNEG          ADD R5, R1, R6
                BRzp NEGLOOP2

                STR R0, R2, #0                  ;put counter into array
                ADD R2, R2, #1

                BR AFTERNEG


                
POSITIVE        LD R6, FIRSTHEX
				ADD R5, R1, R6 					;finds first hex value
				BRzp FIRST
                STR R3, R2, #0                  ;add 0 to array
                ADD R2, R2, #1

AFTERNEG		LD R6, SECONDHEX
				ADD R5, R1, R6 					;finds second hex value
				BRzp SEC
                STR R3, R2, #0                  ;add 0 to array
                ADD R2, R2, #1

				LD R6, THIRDHEX
				ADD R5, R1, R6 					;finds third hex value
				BRzp THIRD
                STR R3, R2, #0                  ;add 0 to array
                ADD R2, R2, #1
 					
				BR FOURTH    					;finds fourth hex value
                
                ;----
                
FIRST 			LD R0, COUNT
				LD R6, FIRSTHEX
				BR TMP21
FIRSTLOOP     	ADD R0, R0, #1 					;algorithm for getting 1k place
				ADD R1, R1, R6
TMP21			ADD R5, R1, R6
				BRzp FIRSTLOOP

				STR R0, R2, #0                  ;put counter into array
                ADD R2, R2, #1


SEC 			LD R0, COUNT
				LD R6, SECONDHEX
				BR TMP31
SECLOOP 		ADD R0, R0, #1 					;algorithm for getting 100 place
				ADD R1, R1, R6
TMP31			ADD R5, R1, R6
				BRzp SECLOOP

				STR R0, R2, #0                  ;put counter into array
                ADD R2, R2, #1


THIRD  			LD R0, COUNT	
				LD R6, THIRDHEX
				BR TMP41
THIRDLOOP 	 	ADD R0, R0, #1 					;algorithm for getting 10 place
				ADD R1, R1, R6
TMP41 			ADD R5, R1, R6
				BRzp THIRDLOOP

				STR R0, R2, #0                  ;put counter into array
                ADD R2, R2, #1
                    
                
FOURTH  		LD R0, COUNT	
				LD R6, FOURTHHEX
				BR TMP51
FOURTHLOOP 	 	ADD R0, R0, #1
				ADD R1, R1, R6 					;algorithm for getting 1's place
TMP51 			ADD R5, R1, R6
				BRzp FOURTHLOOP		

				STR R0, R2, #0                  ;put counter into array
                ADD R2, R2, #1
                
                
                ;----
                
                
                LD R0, R0_BACK              ;load back all registers
                LD R1, R1_BACK
                LD R3, R3_BACK
                LD R4, R4_BACK
                LD R5, R5_BACK
                LD R6, R6_BACK
                LD R7, R7_BACK

                LEA R2, HEXARRAY
                
                RET 
;-----------------------------------------------------------------------------
;Data Block for SUB_DEC_TO_HEX
;-----------------------------------------------------------------------------
R0_BACK       .FILL #0
R1_BACK       .FILL #0
R3_BACK       .FILL #0
R4_BACK       .FILL #0
R5_BACK       .FILL #0
R6_BACK       .FILL #0
R7_BACK       .FILL #0

COUNT         .FILL #0

FIRSTHEX      .FILL #-4096
SECONDHEX     .FILL #-256
THIRDHEX      .FILL #-16
FOURTHHEX     .FILL #-1

HEXARRAY      .BLKW #4
            
;-----------------------------------------------------------------------------
;End Subroutine: SUB_DEC_TO_HEX
;-----------------------------------------------------------------------------

                .END 		        ;stop reading source code

