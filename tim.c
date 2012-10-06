#include<msp430.h>
main()
{
	P1DIR|=0x01;
	P1OUT=1;
	TACTL=0x220;
	while(1)
	{
		while(TACTL==0x220);
		TACTL=0x220;
		P1OUT^=1;
	}
}
	
