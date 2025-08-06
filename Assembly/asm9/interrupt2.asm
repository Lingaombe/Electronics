/* Write a program that continuously get 8-bit data from P0 and
sends it to P1 while simultaneously creating a square wave of 200 µs period on
pin P2.1. Use timer 0 to create the square wave. Assume that XTAL = 11.0592 MHz. */


ORG 0000H
LJMP MAIN ;by-pass interrupt vector table ;
;--ISR for timer 0 to generate square wave
ORG 000BH ;Timer 0 interrupt vector table
CPL P2.1 ;toggle P2.1 pin
RETI ;return from ISR
;--The main program for initialization
ORG 0030H ;after vector table space

MAIN: MOV TMOD,#02H ;Timer 0, mode 2
MOV P0,#0FFH ;make P0 an input port
MOV TH0,#-92 ;TH0=A4H for -92
MOV IE,#82H ;IE=10000010 (bin) ; enable Timer 0
SETB TR0 ;Start Timer 0
BACK: MOV A,P0 ;get data from P0
MOV P1,A ;issue it to P1
SJMP BACK ;keep doing it loop ;unless interrupted by TF0
END