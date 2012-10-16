#include<msp430.h>
#define led_on (P1OUT=BIT0)
#define led_off (P1OUT=0)
#define max 1000
int on_time = 0;
void delay(int n)
{
	while(n--);
}
void one_cycle()
{
	led_on;
	delay(on_time);
	led_off;
	delay(max-on_time);
}
void main()
{
	int step = 20;
	P1DIR = BIT0;
	on_time = 0;	
inc:	while(1)
	{
		one_cycle();
		on_time+=step;
		if(on_time>max)
		{
			on_time-=step;
			goto dec;
		}
			
	}
dec:	while(1)
        {
                one_cycle();
                on_time-=step;
                if(on_time<0)
                {
			on_time+=step;
		        goto inc;
		}
        }

}
