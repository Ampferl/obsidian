#include "main.h"
#include "io.h"
#include "framebuffer.h"

int main()
{
	char name[] = "Jonas: Soon I have an own Operating System :D";
	fb_write(name);
	return 0;
}
