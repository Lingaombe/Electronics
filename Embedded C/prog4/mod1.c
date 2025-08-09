/* Program-2: Write an Embedded C program to generate a square wave with ON and OFF time of 1
sec on port pin P2.0. Assume that XTAL = 11.0592 MHz. Observe the waveform on keil analyzer */

#include<reg51.h>
sbit x = P2^0; // P2.0 assigned to x variable
void delay(unsigned int); // Delay function declaration
void main () // main function
{
	x =0; //output logic 0 to P2.0
	while(1) // infinite loop
	{
		x = 1; // make port pin High
		delay(10000);
		x = 0; // make port pin Low
		delay(10000);
	}
}
void delay(unsigned int k)
{
unsigned int i;
	for(i=0; i<k; i++)
	{
		//timer delay of 100 µs
		TMOD = 0x02; // Timer 0, mode1
		TH0=0xA4; //initial value for 100 µs
		TR0 = 1; // timer0 start
		while (TF0 == 0); // check overflow condition
		TR0 = 0; // Stop Timer
		TF0 = 0; // Clear flag
	}
}