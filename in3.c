#include<msp430.h>
main()
{
	P1DIR=0x41;
	P1OUT=0x01;
	for(;;)
	{
		if(((0x08&P1IN)==0)&&(P1OUT==0x01))
		{
			P1OUT=0x40;
		}
		if(((0x08&P1IN)==0)&&(P1OUT==0x40))
		{
			P1OUT=0x01;
		}
	}
}
