/* Program-3: Write an Embedded C program to generate a square wave of 5 KHz on port pin P2.0.
Assume that XTAL = 11.0592 MHz. Observe the waveform on keil analyzer */

#include <reg51.h>
sbit x = P2^0; // P2.0 assigned to x variable
void delay(void); // Delay function declaration
void main () // main function
{
	x =0; //output logic 0 to P2.0
	while(1) // infinite loop
	{
		x = 1; // make port pin High
		delay();
		x = 0; // make port pin Low
		delay();
	}
}
void delay()
{
	TMOD = 0x01; // Timer 0, mode1
	TH0=0xFF; //initial value for 1 ms
	TL0=0xA4;
	TR0 = 1; // timer0 start
	while (TF0 == 0); // check overflow condition
	TR0 = 0; // Stop Timer
	TF0 = 0; // Clear flag
}