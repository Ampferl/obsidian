#include "string.h"
#include "stdint.h"
#include "stddef.h"

size_t strlen(const char *s)
{
	size_t len = 0;

	for(; *s; ++s)
	{
		++len;
	}

	return len;
}
