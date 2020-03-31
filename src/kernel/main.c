#include "main.h"
#include "io.h"
#include "framebuffer.h"
#include "keyboard.h"

int main()
{
	char name[] = "Jonas: Soon I have an own Operating System :D";
	fb_write(name);
	fb_new_line();
	test_input();
	return 0;
}
