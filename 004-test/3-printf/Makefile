uart.bin: start.o uart_2.o main.o
	arm-linux-ld -Ttext 0xD0020010 -o uart_2.elf $^
	arm-linux-objcopy -O binary uart_2.elf $@
	arm-linux-objdump -D uart_2.elf > uart_2.dis
	
%.o : %.c
	arm-linux-gcc -c $< -o $@ -fno-builtin 
%.o : %.S
	arm-linux-gcc -c $< -o $@
	
clean:
	rm *.o *.elf *.bin *.dis
