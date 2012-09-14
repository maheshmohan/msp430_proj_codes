#include <msp430.h>
main()
{
	P1DIR=0x41;
	while(1)
	{
		P1OUT=0x40;
		long int i=10000;
		while(i!=0)
		{
			P1OUT=0x00;
			i--;		
		}
		P1OUT=0x01;
		i=10000;
		while(i!=0)
		{
			P1OUT=0x00;
			i--;		
		}
	}
}
