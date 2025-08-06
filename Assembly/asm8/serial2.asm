;Write a program to transfer the message “YES” serially at 9600 baud, 8-
;bit data, with 1 stop bit.

MOV TMOD,#20H 
MOV TH1,#-3 
MOV SCON,#50H 
SETB TR1
AGAIN: MOV A,#"Y" 
ACALL TRANS
MOV A,#"E"
ACALL TRANS
MOV A,#"S" 
ACALL TRANS
SJMP AGAIN 
TRANS: MOV SBUF,A 
HERE: JNB TI,HERE 
CLR TI 
RET
END