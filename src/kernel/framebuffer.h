#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

void fb_write(char *buf);
void write_fb_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);
void move_fb_cursor(unsigned short pos);

#endif
