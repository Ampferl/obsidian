OBJECTS = stddef.h	\
	  stdint.h	\
	  string.h	\
	  string.c
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

%.o: ./src/kernel/%.c
	$(CC) $(CFLAGS) $< -o $@

%.o: ./src/kernel/%.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o kernel.elf os.iso
