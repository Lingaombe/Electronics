/* Program the IP register to assign the highest priority to INT1(external
interrupt 1), Assume the interrupts are both edge-triggered. */

MOV IP,#00000100B ;IP.2=1 assign INT1 higher priority. The instruction SETB
END

;IP.2 also will do the same thing as the above line since IP is bit-addressable.