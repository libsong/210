#define GPH0CON		*((volatile unsigned int *)0xE0200C00)
#define GPH0DAT		*((volatile unsigned int *)0xE0200C04)

int main()
{
	int c;

	GPH0CON &= ~(0xFFFF << 0);
	GPH0CON |= 0x1111 << 0;			
	GPH0DAT &= ~(0xF << 0);		// 熄灭LED1和LED2		

	puts("UART Test in S5PV210");
	puts("1.LED1 Toggle");
	puts("2.LED2 Toggle");
	puts("Please select 1 or 2 to Toggle the LED");
	
	while (1)
	{
		c = getchar();			// 从串口终端获取一个字符
		putchar(c);				// 回显
		putchar('\r');

		if (c == '1')
			GPH0DAT ^= 1 << 0;	// 改变LED1的状态
		else if (c == '2')
			GPH0DAT ^= 1 << 1;	// 改变LED2的状态
	}
	return 0;
}