GCCPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = 	obj/loader.o \
			obj/gdt.o \
			obj/hardwarecom/port.o \
			obj/hardwarecom/interruptstubs.o \
			obj/hardwarecom/interrupts.o \
			obj/hardwarecom/pci.o \
			obj/drivers/driver.o \
			obj/drivers/mouse.o \
			obj/drivers/keyboard.o \
			obj/drivers/vga.o \
			obj/gui/widget.o \
		  	obj/gui/window.o \
		  	obj/gui/desktop.o \
			obj/gui/render.o \
			obj/kernel.o

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

obj/%.o: kernel/%.cpp
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

obj/%.o: kernel/%.s
	mkdir -p $(@D)
	as $(ASPARAMS) -o $@ $<

obsidian.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

obsidian.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

.PHONY: clean
clean:
	rm -rf obj/ *.o *~ *.iso *.bin