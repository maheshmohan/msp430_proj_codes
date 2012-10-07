#include<msp430.h>
unsigned int op,grn,red,lfsr = 0xACE1;
unsigned bit;
main()
{
        for(;;)
        {
                P1DIR=0x41;
                do{
                        bit=((lfsr>>0)^(lfsr>>2)^(lfsr>>3)^(lfsr>>5))&1;
                        lfsr=(lfsr>>1)|(bit<<15);
                        grn=lfsr&0x0001;
                        red=lfsr&0x0002;
			red=red>>1;
			grn=grn<<6;
			op=grn|red;
			P1OUT=op;
                        for(int i=100000;i!=0;i--);
		 }while(lfsr!=0xACE1);
        }
}

