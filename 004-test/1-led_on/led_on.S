/* led_on.S */
.global _start				/* 声明一个全局的标号 */
_start:
	ldr r0, =0xE0200C00		/* GPC0CON寄存器 */
	ldr r1, =0x00001111		
	str r1, [r0]			/* 设置GPC0_3为输出,GPC0[15:12] = 0b0001 */

	ldr r0, =0xE0200C04		/* GPC0DAT寄存器 */
	ldr r1, =0x0000000A		
	str r1, [r0]			/* 设置GPC0_3为高电平 */

halt:
	b halt					/* 死循环 */


