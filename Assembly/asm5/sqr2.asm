/*Program-2: Assume that XTAL = 11.0592 MHz. What value do we need to load the
timer’s register if we want to have a time delay of 200 µs (microseconds)? Show the
program for timer 0 in mode 2 to create a pulse width of 200 µs on P2.3.*/

MOV TMOD,#02 
MOV TH0,#48H 
SETB TR0 
AGAIN: JNB TF0, AGAIN 
CPL P2.3 
CLR TF0 
SJMP AGAIN 
END