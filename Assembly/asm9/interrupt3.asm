/* Assume that the INT1 pin is connected to a switch that is
normally high. Whenever it goes low, it should blink the LED which is
connected to P1.3, otherwise keep LED off. */

ORG 0000H

LJMP MAIN ;by-pass interrupt ;vector table
;--ISR for INT1 to turn on LED
ORG 0013H ;INT1 ISR
SETB P1.3 ;turn on LED
MOV R3,#255

BACK1: DJNZ R3,BACK1 ;keep LED on for a while
CLR P1.3 ;turn off the LED
MOV R3,#255
BACK2: DJNZ R3,BACK2
RETI ;return from ISR
;--MAIN program for initialization
ORG 30H

MAIN: MOV IE,#10000100B ;enable external INT 1
HERE: SJMP HERE ;stay here until get interrupted

END