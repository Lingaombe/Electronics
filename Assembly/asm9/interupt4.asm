/* Assume that pin 3.3 (INT1) is connected to a pulse generator, write
a program in which the falling edge of the pulse will send a high to P1.3, which
is connected to an LED (or buzzer). In other words, the LED is turned on and off
at the same rate as the pulses is applied to the INT1 pin. */

ORG 0000H
LJMP MAIN

;--ISR for hardware interrupt INT1 to turn on LED

ORG 0013H ;INT1 ISR
SETB P1.3 ;turn on LED
MOV R3,#255
BACK: DJNZ R3,BACK ;keep the buzzer on for a while
CLR P1.3 ;turn off the buzzer
RETI ;return from ISR
;------MAIN program for initialization
ORG 30H
MAIN: SETB TCON.2 ;make INT1 edge-triggered int.
MOV IE,#10000100B ;enable External INT 1
HERE: SJMP HERE ;stay here until get interrupted
END