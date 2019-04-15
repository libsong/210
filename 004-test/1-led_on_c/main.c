/* main.c */
// #define GPC0CON		*((volatile unsigned int *)0xE0200060)
// #define GPC0DAT		*((volatile unsigned int *)0xE0200064)

#define GPH0CON		*((volatile unsigned int *)0xE0200C00)
#define GPH0DAT		*((volatile unsigned int *)0xE0200C04)

void delay(volatile unsigned int t)
{
	volatile unsigned int t2 = 0xFFFF;
	while (t--)
		for (; t2; t2--);
}

int main()
{
	int toggle = 0;
	GPH0CON &= ~(0xFFFF << 0);
	GPH0CON |= 0x1111 << 0;			// 配置GPC0_3和GPC0_4为输出
	
	while (1)
	{
		GPH0DAT &= ~(0xF << 0);		// 熄灭LED1和LED2
		
		if (toggle) {
			GPH0DAT |= 1 << 0;		// 点亮LED1
			GPH0DAT |= 1 << 2;
		}
		else {
			GPH0DAT |= 1 << 1;		// 点亮LED2
			GPH0DAT |= 1 << 3;
		}
		
		toggle = !toggle;
		delay(0x50000);
	}
	
	return 0;
}

