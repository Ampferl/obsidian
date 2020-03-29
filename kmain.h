#ifndef KMAIN_H
#define KMAIN_H

void fb_write(char *buf);
void write_fb_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);
void move_fb_cursor(unsigned short pos);

void serial_write();
void serial_configure_baud_rate(unsigned short com, unsigned short divisor);
void serial_configure_line(unsigned short com);
int serial_is_transmit_fifo_empty(unsigned int com);

#endif
