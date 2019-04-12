/*led_on.S*/
.global _start
_start:
	ldr r0, =0xE0200C00
	ldr r1, =0x00001111
	str r1,[r0]
	
	ldr r0, =0xE0200C04
	ldr r1, =0x0000000F
	str r1,[r0]
	
halt:
	b halt