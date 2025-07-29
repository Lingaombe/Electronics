/* Program-2: Write an Embedded C program to generate a square wave with ON and OFF time of 1
sec on port pin P2.0. Assume that XTAL = 11.0592 MHz. Observe the waveform on keil analyzer */

#include <reg51.h>
sbit x = P2^0; 

void delay(unsigned int); 
void main () 
{
	x =0; 
	while(1)
	{
		x = 1; 
		delay(1000);
		x = 0; 
		delay(1000);
	}
}

void delay(unsigned int k)
{
	int i;
	for(i=0; i < k; i++)
	{
		TMOD = 0x01; 
		TH0=0xFC; 
		TL0=0x66;
		TR0 = 1; 
		while (TF0 == 0); 
		TR0 = 0;
		TF0 = 0; 
	}
}