#include <unistd.h>
#include "buche.h"
int main()
{
    	int i;
	for(i = 0; i < 10; ++i)
	{
		BUCHE("hello, %s", "World!");
		usleep(500);
	}
	return 0;
}
