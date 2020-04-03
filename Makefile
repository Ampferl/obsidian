LIBS = -Ilibraries/
KERNEL_PATH = kernel/
GPPPARAMS = -m32 $(LIBS) -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = loader.o kernel.o gdt.o port.o interrupt.o interrupts.o

build: $(objects)

 
mykernel.elf: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

os.iso: mykernel.elf
	cp mykernel.elf iso/boot/mykernel.elf
	genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -A os -input-charset utf8 -quiet -boot-info-table -o os.iso iso

run: os.iso
	bochs -f boot-config.txt -q

%.o: $(KERNEL_PATH)%.cpp
	g++ $(GPPPARAMS) -o $@ -c $<

%.o: $(KERNEL_PATH)%.s
	as $(ASPARAMS) -o $@ $<

clean:
	rm -rf *.o mykernel.elf os.iso boot-log.txt a.out
