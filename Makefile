GCCPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = loader.o gdt.o port.o kernel.o interruptstubs.o interrupts.o mouse.o keyboard.o

run: obsidian.iso
	qemu-system-i386 obsidian.iso

obsidian.iso: obsidian.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp obsidian.bin iso/boot/obsidian.bin
	echo 'set timeout=0'                      > iso/boot/grub/grub.cfg
	echo 'set default=0'                     >> iso/boot/grub/grub.cfg
	echo ''                                  >> iso/boot/grub/grub.cfg
	echo 'menuentry "Obsidian" {'			 >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/obsidian.bin'    >> iso/boot/grub/grub.cfg
	echo '  boot'                            >> iso/boot/grub/grub.cfg
	echo '}'                                 >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=obsidian.iso iso
	rm -rf iso

%.o: %.cpp
	gcc $(GCCPARAMS) -c -o $@ $<

%.o: %.s
	as $(ASPARAMS) -o $@ $<

obsidian.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

obsidian.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)



clean:
	sudo rm *.o *~ iso/ *.iso -r *.bin