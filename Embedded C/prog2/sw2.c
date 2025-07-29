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
		delay(10000);
		x = 0; 
		delay(10000);
	}
}
void delay(unsigned int k)
{
unsigned int i;
	for(i=0; i<k; i++)
	{
		//timer delay of 100 µs
		TMOD = 0x02; 
		TH0=0xA4; 
		TR0 = 1; 
		while (TF0 == 0); 
		TR0 = 0; 
		TF0 = 0; 
	}
}