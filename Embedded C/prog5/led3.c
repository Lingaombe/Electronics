// Interfacing Eight LED with 8051
//Blink all LEDs simultaneously with 1sec ON and 1 sec OFF time period

#include <REGX51.H>
void delay(unsigned int);
void main(void)
{
	while(1)
	{
		P2=0xFF;
		delay(1000);
		P2=0x00;
		delay(1000);
	}
}
void delay(unsigned int k)
{
	unsigned int i;
	for (i=0;i<k;i++)
	{
		//delay of 1 ms
		TMOD=0X01;
		TH0=0XFC;
		TL0=0x66;
		TR0=1;
		while(TF0==0);
		TR0=0;
		TF0=0;
	}
}