#include<msp430.h>
//delay function
void delay()
{
	for(long int j=100000;j!=0;j--);
	P1OUT=0x00;
}
void main()
{
	while(1)//infinite loop
	{
		P1DIR|=0xFF;//all port1 pins are output
		P1OUT=0;//initialise output to 0
		P1OUT=BIT1|BIT2;//light led b n c(1)
		delay();
		P1OUT=BIT0|BIT1|BIT6|BIT4|BIT3;//light a b g e d(2)
		delay();
		P1OUT=BIT0|BIT1|BIT6|BIT2|BIT3;//to show 3
		delay();
		P1OUT=BIT5|BIT6|BIT2;//4
		delay();
		P1OUT=BIT0|BIT5|BIT6|BIT2|BIT3;//5
		delay();
		P1OUT=BIT0|BIT5|BIT4|BIT3|BIT2|BIT6;//6
		delay();
		P1OUT=BIT0|BIT1|BIT2;//7
		delay();
		P1OUT|=0xFF;//8
		delay();
		P1OUT=BIT6|BIT5|BIT0|BIT1|BIT2|BIT3;//9
		delay();
		P1OUT|=(0xFF&(~(1<<6)));//0
		delay();
	}
}
