#include "uart.h"
#include "clock.h"

#define GPH0CON		*((volatile unsigned int *)0xE0200C00)
#define GPH0DAT		*((volatile unsigned int *)0xE0200C04)

void delay(volatile u32 t)
{
	volatile u32 t2 = 0xFFFF;
	while (t--)
		for (; t2; t2--);
}

int main()
{
	int toggle = 0;
	GPH0CON &= ~(0xFFFF << 0);
	GPH0CON |= 0x1111 << 0;				
	
	puts("\n##### Before init clock by we #####");
	print_clockinfo();
	
	clock_init();		// 时钟初始化
	
	puts("\n##### After init clock by we #####");
	print_clockinfo();
	
	while (1)
	{
		GPH0DAT &= ~(0xF << 0);		// 熄灭LED1和LED2
		
		if (toggle)
			GPH0DAT |= 1 << 0;		// 点亮LED1
		else
			GPH0DAT |= 1 << 1;		// 点亮LED2
		
		toggle = !toggle;
		delay(0x50000);
	}
	
	return 0;
}
