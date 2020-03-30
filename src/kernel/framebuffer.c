#include "framebuffer.h"
#include "io.h"

#define FB_CMD_PORT                     0x3D4
#define FB_DATA_PORT                    0x3D5
#define FB_HIGH_BYTE_CMD                14
#define FB_LOW_BYTE_CMD                 15

#define COLOR_GREEN                     2
#define COLOR_GREY                      8
#define COLOR_WHITE                     15
#define COLOR_BLACK                     0

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
