#include <unistd.h>
#include "buche.h"
void foobar()
{
    	int j;
	for(j = 0; j < 3;++j)
	{
	    	BUCHE("iteration #%d",j)
	}
}
int main()
{
    	int i;
	for(i = 0; i < 3; ++i)
	{
		BUCHE("hello, %s", "World!");
		sleep(1);
		foobar();
		sleep(1);
	}
	return 0;
}
