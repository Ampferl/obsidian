#include "main.h"
#include "io.h"
#include "framebuffer.h"
#include "keyboard.h"

int main()
{
	clear_fb(COLOR_WHITE, COLOR_BLACK);
	
	/*
	fb_write_color("jonas@obsidian", COLOR_BRIGHT_GREEN);
        fb_write_color(":", COLOR_WHITE);
        fb_write_color("~", COLOR_CYAN);
        fb_write_color("$ ", COLOR_WHITE);
	*/

	test_input();
	return 0;
}
