// Interfacing Eight LED with 8051
//Left shift effect with 250 ms ON and 250 ms OFF time period

#include <REGX51.H>
void delay(unsigned int);
void main(void)
{
	while(1)
	{
		unsigned int j;
		P2=0x01;
		for (j=0;j<8;j++)
		{
			delay(250);
			P2=P2<<1;
		}
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