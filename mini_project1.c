 #include <LPC21xx.h>
#define L293D (1<<10)
#include "lcdleaderfile.h"
#include "keypad.h"
#include "uart.h"
#include "gsm.h"
#include "external_interrupt.h"
#define L293D (1<<10)//motor
#define IRSensor 4 //irsensor



unsigned int count = 0;
unsigned int target = 0;

//unsigned int emergency_flag = 0;
int main(void)
{
char ch;
LCD_INIT();
IODIR0 |= L293D;
IOCLR0 = L293D;
GSM_INIT();
EINT0_INIT();
LCD_COMMAND(0x80);
LCD_STRING("CONVEYOR BELT PRODUCT COUNTER");
delay_milliseconds(1000);
while(1)
{
target=0;
LCD_COMMAND(0x01);
LCD_COMMAND(0x80);
LCD_STRING("ENTER TARGET");
LCD_COMMAND(0xC0);
LCD_STRING("press # to ok");
while(1)
{
ch = keyscan();
if(ch >= '0' && ch <= '9')
{
target = ch - '0';
LCD_COMMAND(0xC0);
LCD_DATA(ch);
}
if(ch == '#')
{
    break;
}
}
count = 0;
LCD_COMMAND(0x01);
LCD_COMMAND(0x80);
LCD_STRING("Target:");
LCD_DATA(target + '0');
LCD_COMMAND(0xC0);
LCD_STRING("Count:0");
IOSET0 = L293D;
while(1)
{
if(emergency_flag == 1)
{
IOCLR0 = L293D;
LCD_COMMAND(0x01);
LCD_COMMAND(0x80);
LCD_STRING("EMERGENCY SITUATION");
GSM_SMS("EMERGENCY Conveyor stopped.");
while(1);
}
if(((IOPIN0 >> IRSensor) & 1) == 0)
{
    count++;
    LCD_COMMAND(0xC0);
    LCD_STRING("Count:");
    LCD_DATA(count + '0');
	delay_milliseconds(500);
    if(count == target)
    {
     IOCLR0 = L293D;
     LCD_COMMAND(0x01);
     LCD_COMMAND(0x80);
     LCD_STRING("TARGET REACHED");
     LCD_COMMAND(0xC0);
     LCD_STRING("Count:");
     LCD_DATA(count + '0');
     GSM_SMS("Target reached. Conveyor stopped.");
	 delay_milliseconds(3000);
     while(((IOPIN0>>IRSensor)&1)==0);
	 break;
     }
     while(((IOPIN0 >> IRSensor) & 1) == 0);
    }
    }
	}
}