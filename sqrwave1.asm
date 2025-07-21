MOV TMOD,#01 ;Timer 0, 16-bitmode
HERE: MOV TL0,#1AH ;TL0=1A, the low byte
MOV TH0,#0FFH ;TH0=FF, the high byte
CPL P1.5 ;complement P1.5 to get hi, lo
SETB TR0 ;Start timer 0
AGAIN: JNB TF0,AGAIN ;Monitor timer flag 0
CLR TR0 ;Stop the timer 0
CLR TF0 ;Clear timer 0 flag
SJMP HERE ;is not auto-reload
END