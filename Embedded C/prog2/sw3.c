/* Program-3: Write an Embedded C program to generate a square wave of 2 KHz on port pin P2.0.
Assume that XTAL = 11.0592 MHz. Observe the waveform on keil analyzer */

#include <reg51.h>

sbit x = P2^0; 
void delay(void); 
void main () 
{
	x =0; 
	while(1) 
	{
		x = 1; 
		delay();
		x = 0; 
		delay();
	}
}
void delay()
{
	TMOD = 0x02; 
	TH0=0x1A; 
	TR0 = 1; 
	while (TF0 == 0); 
	TR0 = 0; 
	TF0 = 0; 
}