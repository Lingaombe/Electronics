/* Program-3: Write an assembly language program for 8051 to generate a square wave
of 10KHz with 50% duty cycle on port pin P1.5 using timer 0 in mode 2.*/


MOV TMOD,#02 
MOV TH0,#D2H 
SETB TR0 
AGAIN: JNB TF0, AGAIN 
CPL P1.5 
CLR TF0 
SJMP AGAIN 
END