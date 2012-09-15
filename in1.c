#include <msp430.h>
main()
{
	P1DIR=0;
	int i=0x08;
	while(i=i&P1IN)
	{
	}
	P1DIR=1;
	P1OUT=1;
}
