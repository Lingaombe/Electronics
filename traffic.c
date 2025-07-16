#include <reg51.h>

sbit Red0=P0^0; sbit Red1=P1^0; sbit Red2=P2^0; sbit Red3=P3^0;
sbit Green0=P0^1; sbit Green1=P1^1; sbit Green2=P2^1; sbit Green3=P3^1;
sbit Yellow0=P0^2; sbit Yellow1=P1^2; sbit Yellow2=P2^2; sbit Yellow3=P3^2;


void delay(unsigned int);
			

void main(){
	P0=P1=P2=P3=0x00;
	while(1){
			
//mphambano yoyamba	
			Red0=0; Green0=1;
			Red1=Red2=Red3=1;
			
			Green1=Green2=Green3=0;
			Yellow0=Yellow1=Yellow2=Yellow3=0;
			delay(1000); 
		
			Red0=0;
			Red1=Red2=Red3=1;
			Green0=Green1=Green2=Green3=0;
			Yellow0=1;
			Yellow1=Yellow2=Yellow3=0;
			delay(100); 
			
//mphambano yachiwiri
			Red1=0;
			Red0=Red2=Red3=1;
			Green1=1;
			Green0=Green2=Green3=0;
			Yellow0=Yellow1=Yellow2=Yellow3=0;
			delay(1000); 
		
			Red1=0;
			Red0=Red2=Red3=1;
			Green0=Green1=Green2=Green3=0;
			Yellow1=1;
			Yellow0=Yellow2=Yellow3=0;
			delay(100); 
			
//mphambano yachitatu
			Red2=0;
			Red0=Red1=Red3=1;
			Green2=1;
			Green0=Green1=Green3=0;
			Yellow0=Yellow1=Yellow2=Yellow3=0;
			delay(1000); 
		
			Red2=0;
			Red0=Red1=Red3=1;
			Green0=Green1=Green2=Green3=0;
			Yellow2=1;
			Yellow0=Yellow1=Yellow3=0;
			delay(100); 
			
//mphambano yachinayi
			Red3=0;
			Red0=Red2=Red1=1;
			Green3=1;
			Green0=Green2=Green1=0;
			Yellow0=Yellow1=Yellow2=Yellow3=0;
			delay(1000); 
		
			Red3=0;
			Red0=Red2=Red1=1;
			Green0=Green1=Green2=Green3=0;
			Yellow3=1;
			Yellow0=Yellow2=Yellow1=0;
			delay(100); 
	}
}

void delay(unsigned int h){
	unsigned int i;
	for(i=0;i<h;i++){
				TMOD=0x01; TH0=0xEE; TL0=0x00;
				TR0=1;
				while(TF0==0);
				TR0=0;
				TF0=0;
	}
}