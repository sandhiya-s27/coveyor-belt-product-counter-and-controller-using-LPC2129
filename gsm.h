void GSM_INIT(void)
{
UART0_INIT();
delay_milliseconds(1000);
UART0_STRING("AT\r\n");
delay_milliseconds(1000);
UART0_STRING("AT+CMGF=1\r\n");
delay_milliseconds(1000);
}
void GSM_SMS(char *message)
{
UART0_STRING("AT+CMGS=\"9381058662\"\r\n");
delay_milliseconds(2000);
UART0_STRING(message);
UART0_TX(26);
delay_milliseconds(3000);
}