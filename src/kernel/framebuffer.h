#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200
#define NULL 0

void fb_write(char *buf);
void write_fb_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);
void move_fb_cursor(unsigned short pos);
void move_fb_cursor_right(void);
void move_fb_cursor_left();
void move_fb_cursor_top();
void move_fb_cursor_bottom();
void clear_fb(char fg, char bg);
void fb_new_line();
void fb_write_char(char buf);
void fb_delete_char();

enum vga_color {
    COLOR_BLACK,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_CYAN,
    COLOR_RED,
    COLOR_MAGENTA,
    COLOR_BROWN,
    COLOR_GREY,
    COLOR_DARK_GREY,
    COLOR_BRIGHT_BLUE,
    COLOR_BRIGHT_GREEN,
    COLOR_BRIGHT_CYAN,
    COLOR_BRIGHT_RED,
    COLOR_BRIGHT_MAGENTA,
    COLOR_YELLOW,
    COLOR_WHITE,
};

#endif
