void UART0_INIT(void)
{
PINSEL0 |= 0x00000005;
U0LCR = 0x83;
U0DLL = 97;
U0DLM = 0;
U0LCR = 0x03;
}
void UART0_TX(char ch)
{
while(((U0LSR >>5)&1) == 0);
U0THR = ch;
}
void UART0_STRING(char *s)
{
while(*s)
{
UART0_TX(*s);
s++;
}
}
