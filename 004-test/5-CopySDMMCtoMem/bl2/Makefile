OBJ=bl2
$(OBJ).bin: start.o uart_2.o main.o
	arm-linux-ld -Ttext 0xD0022800 -o $(OBJ).elf $^ -lgcc -L/usr/local/arm/4.3.2/lib/gcc/arm-none-linux-gnueabi/4.3.2
	arm-linux-objcopy -O binary $(OBJ).elf $@
	arm-linux-objdump -D $(OBJ).elf > $(OBJ).dis
	
%.o : %.c
	arm-linux-gcc -c $< -o $@ -fno-builtin
%.o : %.S
	arm-linux-gcc -c $< -o $@
	
clean:
	rm *.o *.elf *.bin *.dis
