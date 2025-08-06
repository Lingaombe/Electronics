/* Program-4 Assume XTAL = 11.0592 MHz, find the frequency of the square wave
generated on pin P1.0 in the following program*/

MOV TMOD,#20H 
MOV TH1,#5 
SETB TR1 
BACK: JNB TF1,BACK 
CPL P1.0 
CLR TF1 
SJMP BACK 
END