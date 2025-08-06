/*Write a C program for 8051 to transfer the letter “A” serially at 4800
baud continuously. Use 8-bit data and 1 stop bit.*/

MOV TMOD,#20H 
MOV TH1,#-6 
MOV SCON,#50H 
SETB TR1 
AGAIN: MOV SBUF, #"A" 
HERE: JNB TI, HERE ;
CLR TI 
SJMP AGAIN
END