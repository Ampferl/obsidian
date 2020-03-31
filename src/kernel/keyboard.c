#include "keyboard.h"
#include "framebuffer.h"
#include "io.h"
#include "char.h"

char get_input_keycode()
{
	char ch = 0;
	while((ch = inb(KEYBOARD_PORT)) != 0)
	{
		if(ch > 0)
		{
			return ch;
		}
	
	}
	return ch;
}

void wait_for_io(int timer_count)
{
	while(1)
	{
		noop();
		timer_count--;
		if(timer_count <= 0)
		{
			break;
		}
	}
}

void sleep(int timer_count)
{
	int seconds = SECOND_MULTIPLIER * timer_count;
	wait_for_io(seconds);
}

void test_input()
{
	char ch = 0;
	char keycode = 0;
	do{
		keycode = get_input_keycode();
		if(keycode == KEY_ENTER)
		{
			fb_new_line();
		}
		else if(keycode == KEY_BACKSPACE)
		{
			fb_delete_char();
		}
		else if(keycode == KEY_UP)
		{
			move_fb_cursor_top();
		}
		else if(keycode == KEY_DOWN)
		{
			move_fb_cursor_bottom();
		}
		else if(keycode == KEY_LEFT)
		{
			move_fb_cursor_left();
		}
		else if(keycode == KEY_RIGHT)
		{
			move_fb_cursor_right();
		}
		else
		{
			ch = get_ascii_char(keycode);
			fb_write_char(ch);
		}
		sleep(1);
	}while(ch > 0);
}
