;Write a program to receive serially at 4800 baud, 8-bit data, with 1
;stop bit. After receiving send it continuously to P0.

MOV TMOD,#20H 
MOV TH1,#-6 
MOV SCON,#50H 
SETB TR1 
HERE: JNB RI,HERE 
MOV A,SBUF 
MOV P1,A 
CLR RI 
SJMP HERE 
END