// Interfacing Eight LED with 8051
//Glow LED one after another in Left to Right direction with 250 ms ON and 250 ms OFF time period

#include <REGX51.H>
void delay(unsigned int);
void main(void)
{
	while(1)
	{
		unsigned int j;
		unsigned int m[]={0x00, 0x01, 0x03, 0x07, 0x0F, 0X1F, 0X3F,0X7F,0XFF,};
		for (j=0;j<9;j++)
		{
			P2=m[j];
			delay(250);
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