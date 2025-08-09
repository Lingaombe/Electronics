// Interfacing single LED with 8051
//Blink single LED with 5 sec ON and % sec OFF time period
#include<REGX51.H>
sbit LED=P2^0;
void delay(unsigned int);
void main(void)
{
	while(1)
	{
		LED =1;
		delay(1000);
		LED =0;
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