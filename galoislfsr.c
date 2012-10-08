#include<msp430.h>
unsigned red,grn,op,lfsr=0xACE1;
main()
{
	P1DIR=0x41;
	do{
		unsigned lsb=lfsr&1;
		lfsr>>=1;
		if(lsb==1)
			lfsr^=0xB400;
		red=lfsr&0x0001;
		grn=lfsr&0x0002;
		op=red|(grn<<5);
		P1OUT=op;
		for(int i=100000;i!=0;i--);
	}while(lfsr!=0xAEC1);
}
