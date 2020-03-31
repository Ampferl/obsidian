OBJECTS = loader.o main.o io.o framebuffer.o
LIBC_PATH = -I./src/libraries/libC/
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf:
	@make --no-print-directory -C src/kernel
	@make --no-print-directory -C src/libraries/libC

os.iso: kernel.elf
	cp src/kernel/kernel.elf iso/boot/kernel.elf
	genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -A os -input-charset utf8 -quiet -boot-info-table -o os.iso iso

run: os.iso
	bochs -f boot-config.txt -q

%.o: %.c
	$(CC) $(LIBC_PATH) $(CFLAGS) $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	@echo 'Clean Kernel'
	@make --no-print-directory -C src/kernel clean
	@make --no-print-directory -C src/libraries/libC clean
	rm -rf *.o kernel.elf os.iso boot-log.txt
