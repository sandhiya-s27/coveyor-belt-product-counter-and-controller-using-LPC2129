#include<LPC21XX.H>
void delay_milliseconds(unsigned int);
void delay_milliseconds(unsigned int milliseconds)
{
T0PR=15000-1;
T0TCR=0X1;
while(T0TC< milliseconds);
T0TCR=0X3;
T0TCR=0X0;
}

