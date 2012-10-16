#include<msp430.h>
//function to initialise adc
void in_adc()
{
	ADC10CTL0 = SREF_0|ADC10SHT_0|ADC10ON;
	ADC10CTL1 = INCH_4|SHS_0|ADC10DIV_0|ADC10SSEL_0|CONSEQ_0;
	ADC10AE0 = BIT4;
	ADC10CTL0 |= ENC;
}
//start converstion function
void adc_sc()
{
	ADC10CTL0 |= ADC10SC;
}
//function to know the conversion status
long int adc_stat()
{
	return ADC10CTL1 & ADC10BUSY;
}
void main()
{
	P1DIR = BIT0|BIT6;  //P1.0 and P1.6 are outputs
	while(1) //infinite loop to continuously check the input
	{
		in_adc(); //initialise adc
		adc_sc(); //start converstion
		long int i = adc_stat(); //converstion status
        	if(i == 0) //check if conversion complete
		{
			if(ADC10MEM<=0x0100) //bot LEDs off when i/p <= 0.9v
				P1OUT&=0;
			else if(ADC10MEM>0x0100 && ADC10MEM<=0x0200) // Green LED on when 0.9v < i/p <= 1.8v
			{
				P1OUT&=0;
				P1OUT|=BIT6;
			}
			else if(ADC10MEM>0x0200 && ADC10MEM<=0x0300) //Red LED on when 1.8v < i/p <= 2.7v
		        {
				P1OUT&=0;
				P1OUT|=BIT0;
			}
			else if(ADC10MEM>0x0300 && ADC10MEM<=0x0400) // Both LEDs on when 2.7v < i/p < 3.6v
			{
				P1OUT&=0;
				P1OUT=BIT0|BIT6;
			}
		}
	}
} 
