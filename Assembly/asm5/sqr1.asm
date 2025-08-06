/*Program-1: In the following program, we create a square wave of 2 KHz with 50%
duty cycle (with equal portions high and low) on the P1.2 bit. Timer 0 is used to
generate the time delay in mode 2.*/

MOV TMOD,#20H 
MOV TH1,#12H 
SETB TR1 
BACK: JNB TF1,BACK 
CPL P1.2 
CLR TF1 
SJMP BACK
END