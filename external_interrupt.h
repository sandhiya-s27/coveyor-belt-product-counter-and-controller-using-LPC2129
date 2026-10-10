unsigned int emergency_flag = 0;
void EINT0_ISR(void) __irq
{
emergency_flag = 1;
IOCLR0 = L293D;
EXTINT = 0x01;
VICVectAddr = 0;
}
void EINT0_INIT(void)
{
PINSEL1 |= 0x01;
EXTMODE = 0x01;
EXTPOLAR =0x00;
VICIntSelect =0;
VICVectCntl0 = (1<<5) | 14;
VICVectAddr0 = (unsigned long)EINT0_ISR;
VICIntEnable |= (1<<14);
}
