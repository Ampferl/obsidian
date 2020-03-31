#include "framebuffer.h"
#include "io.h"

#define FB_CMD_PORT                     0x3D4
#define FB_DATA_PORT                    0x3D5
#define FB_HIGH_BYTE_CMD                14
#define FB_LOW_BYTE_CMD                 15
int cursor_pos = 0;

void fb_write(char *buf)
{
	int start_pos = cursor_pos;
        char * buffer = buf;
	int i = 0;
        for(i = 0; buffer[i] != '\0'; i++)
        {
                write_fb_cell(start_pos*2, buffer[i], COLOR_WHITE, COLOR_BLACK);
		start_pos += 1;
        }
        move_fb_cursor(start_pos);
	cursor_pos = start_pos;
}

void fb_write_char(char buf)
{
	write_fb_cell(cursor_pos*2, buf, COLOR_WHITE, COLOR_BLACK);
	cursor_pos += 1;
	move_fb_cursor(cursor_pos);
}

void fb_delete_char()
{
	write_fb_cell(cursor_pos*2-2, NULL, COLOR_WHITE, COLOR_BLACK);
	move_fb_cursor_left();
}

void fb_new_line(){
	cursor_pos += 80;
	int rest = cursor_pos % 80;
	cursor_pos -= rest;
	move_fb_cursor(cursor_pos);
}

void move_fb_cursor_right()
{
	cursor_pos += 1;
	move_fb_cursor(cursor_pos);
}

void move_fb_cursor_left()
{
	cursor_pos -= 1;
	move_fb_cursor(cursor_pos);
}

void move_fb_cursor_top()
{
	if(cursor_pos - 80 <= 0)
	{
		cursor_pos = 0;
	}else{
		cursor_pos -= 80;
	}
	move_fb_cursor(cursor_pos);
}

void move_fb_cursor_bottom()
{
	cursor_pos += 80;
	move_fb_cursor(cursor_pos);
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

void clear_fb(char fg, char bg)
{
	int i;
	for(i = 0; i < BUFSIZE; i++)
	{
		write_fb_cell(i*2, NULL, fg, bg);
	}
}
