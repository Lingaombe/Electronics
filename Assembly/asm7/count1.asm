/* Program-1 Assuming that clock pulses are fed into pin T1, write a program for
counter 1 in mode 2 to count the pulses and display the state of the TL1 count on P2,
which connects to 8 LEDs*/

MOV TMOD,#01100000B 
MOV TH1,#0 
SETB P3.5 
AGAIN: SETB TR1 
BACK: MOV A,TL1 
MOV P2,A 
JNB TF1,Back 
CLR TR1 
CLR TF1 
SJMP AGAIN 
END