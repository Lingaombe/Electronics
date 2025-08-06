/* Write a program in which the 8051 gets data from P1 and sends it to
P2 continuously while incoming data from the serial port is sent to P0. Assume
that XTAL=11.0592. Set the baud rata at 9600. */

ORG 0000H
LJMP MAIN
ORG 23H
LJMP SERIAL ;jump to serial int ISR
ORG 30H

MAIN: MOV P1,#0FFH ;make P1 an input port
MOV TMOD,#20H ;timer 1, auto reload
MOV TH1,#0FDH ;9600 baud rate
MOV SCON,#50H ;8-bit,1 stop, ren enabled
MOV IE,10010000B ;enable serial int.
SETB TR1 ;start timer 1
BACK: MOV A,P1 ;read data from port 1

MOV P2,A ;send it to P2
SJMP BACK ;stay in loop indefinitely

;-----------------SERIAL PORT ISR
ORG 100H

SERIAL: JB TI,TRANS ;jump if TI is high
MOV A,SBUF ;otherwise due to receive
MOV P0,A ;send incoming data to P0
CLR RI ;clear RI since CPU doesn’t
RETI ;return from ISR

TRANS: CLR TI ;clear TI since CPU doesn’t

RETI ;return from ISR
END