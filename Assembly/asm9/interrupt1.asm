/* Show the instructions to (a) enable the serial interrupt, timer 0
interrupt, and external hardware interrupt 1 (EX1),and (b) disable (mask) the
timer 0 interrupt, then (c) show how to disable all the interrupts with a single
instruction.*/

MOV IE,#10010110B ;enable serial, ;timer 0, EX1

SETB IE.7 ;EA=1, global enable
SETB IE.4 ;enable serial interrupt
SETB IE.1 ;enable Timer 0 interrupt
SETB IE.2 ;enable EX1
CLR IE.1 ;mask (disable) timer 0 ;interrupt only
CLR IE.7 ;disable all interrupts
END