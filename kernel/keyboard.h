#ifndef KEYBOARD_H
#define KEYBOARD_H

#define KEYBOARD_PORT 0x60
#define SECOND_MULTIPLIER 500000

void test_input();
void sleep(int timer_count);
char get_input_keycode();
char get_ascii_char(int key_code);

#endif
