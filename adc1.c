#include<msp430.h>
//function to initialise ADC
void en_adc()
{
	ADC10CTL0=ADC10ON|SREF_0|ADC10SHT_2;
	ADC10CTL1=INCH_0|SHS_0|ADC10DIV_0|ADC10SSEL_0|CONSEQ_0;
	ADC10CTL0|=ENC;
}
//function to start conversion
void start_conv()
{
	ADC10CTL0|=ADC10SC;
}
//function to know the status of conversion
unsigned int conv_stat()
{
	return ADC10CTL1&ADC10BUSY;
}
//delay function
void delay()
{
	int j=1000;
	for(;j!=0;j--);
}
//main function
void main()
{
	P1DIR|=BIT6;
	while (1)
	{
		en_adc();
		start_conv();
		unsigned int i=conv_stat();
		if(i==0)
		{
			if(ADC10MEM<0x0194&&ADC10MEM>0x017C)
				P1OUT&=0x0000;
			else
				P1OUT|=BIT6;
		}
		delay();	
	}
}
