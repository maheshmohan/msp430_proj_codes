#include<msp430.h>


//delay function
void delay()
{
	for(long int j=100000;j!=0;j--);
	P1OUT&=0;
}
void main()
{
	P1DIR|=0x07;
	P1OUT&=0;
	while(1)
	{
		P1OUT=0x01;
		delay();
		P1OUT=0x02;
		delay();
		P1OUT=0x04;
		delay();
	}
}
