#include "kmain.h"
#include "io.h"

#define COLOR_GREEN			2
#define COLOR_GREY			8
#define COLOR_WHITE			15
#define COLOR_BLACK			0

#define FB_CMD_PORT			0x3D4
#define FB_DATA_PORT			0x3D5
#define FB_HIGH_BYTE_CMD		14
#define FB_LOW_BYTE_CMD			15

#define SERIAL_COM1_BASE        	0x3F8

#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)
#define SERIAL_LINE_ENABLE_DLAB         0x80

int main()
{
	char name[] = "Jonas: Soon I have an own Operating System :D";
	fb_write(name);
	return 0;
}

void serial_write()
{
	serial_configure_baud_rate(SERIAL_COM1_BASE, 2);
	serial_configure_line(SERIAL_COM1_BASE);
	serial_is_transmit_fifo_empty(SERIAL_COM1_BASE);
}

void serial_configure_baud_rate(unsigned short com, unsigned short divisor)
{
	outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
	outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
	outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

void serial_configure_line(unsigned short com)
{
	outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

int serial_is_transmit_fifo_empty(unsigned int com)
{
	return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

void fb_write(char *buf)
{
	char * buffer = buf;
	int i = 0;
	for(i = 0; buffer[i] != '\0'; i++)
	{
		write_fb_cell(i*2, buffer[i], COLOR_WHITE, COLOR_BLACK);
	}
	move_fb_cursor(i);
}

void move_fb_cursor(unsigned short pos)
{
	outb(FB_CMD_PORT, FB_HIGH_BYTE_CMD);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_CMD_PORT, FB_LOW_BYTE_CMD);
	outb(FB_DATA_PORT, pos & 0x00FF);
}

void write_fb_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
	char *fb = (char *) 0x000B8000;
	fb[i] = c;
	fb[i+1] = ((bg & 0x0F) << 4) | (fg & 0x0F);
}
