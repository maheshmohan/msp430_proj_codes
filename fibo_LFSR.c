#include<msp430.h>
#include<stdint.h>
unsigned int op,lfsr = 0xACE1;
unsigned bit;
main()
{
	for(;;)
	{
		P1DIR=0x40;
		do{
			bit=((lfsr>>0)^(lfsr>>2)^(lfsr>>3)^(lfsr>>5))&1;
			lfsr=(lfsr>>1)|(bit<<15);
			op=lfsr&0x0001;
			P1OUT=(op<<6);
			for(int i=100000;i!=0;i--);
		}while(lfsr!=0xACE1);
		P1DIR=0x01;
		P1OUT=1;
		for(int i=100000;i!=0;i--);
		P1OUT=0;
	}
}
