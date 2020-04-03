#include <types.h>
#include "gdt.h"

void printf(char* str)
{
        static uint16_t* VideoMemory = (uint16_t*)0xb8000;

	static uint8_t x=0;
	static uint8_t y=0;

        for(int i = 0; str[i] != '\0'; ++i)
        {
		switch(str[i])
		{
			case '\n':
				y++;
				x = 0;
				break;
			default:
				VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
				x++;
				break;
		}

		if(x >= 80)
		{
			y++;
			x = 0;
		}

		if(y >= 25)
		{
			for(y = 0; y < 25; y++)
				for(x = 0; x < 80; x++)
					VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | ' ';
			x = 0;
			y = 0;
		}
	}
}

extern "C" void kernelMain(void* multiboot_structure, uint32_t magicnumber)
{
	printf("Jonas ist nice xD ");
	printf("Test\n");
	printf("Ein Test");
	
	GlobalDescriptorTable gdt;

	while(1);
}
